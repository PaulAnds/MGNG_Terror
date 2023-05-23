// Fill out your copyright notice in the Description page of Project Settings.


#include "Oxygen.h"

// Sets default values
AOxygen::AOxygen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ManometerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ManometerMesh"));
	RootComponent = ManometerMesh;

	NeedleCenterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NeedleCenterMesh"));
	NeedleCenterMesh->SetupAttachment(ManometerMesh);

	NeedleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NeedleMesh"));
	NeedleMesh->SetupAttachment(NeedleCenterMesh);

	NeedleCenterMesh->SetRelativeRotation(FRotator(0,0,-207));
	RotSpeed = 10;
	OxygenValue = 0;
}

// Called when the game starts or when spawned
void AOxygen::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOxygen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(OxygenValue < 207.f)
	{
		const FRotator NewRotation = FRotator(0,0,DeltaTime * RotSpeed);
		OxygenValue += DeltaTime * RotSpeed;
		NeedleCenterMesh->AddRelativeRotation(NewRotation);
	}
}