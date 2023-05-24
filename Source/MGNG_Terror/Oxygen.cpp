// Fill out your copyright notice in the Description page of Project Settings.


#include "Oxygen.h"

// Sets default values
AOxygen::AOxygen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	
	TankMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankMesh"));
	TankMesh->SetupAttachment(BoxCollision);

	NiagaraSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraSystem"));
	
	ManometerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ManometerMesh"));
	ManometerMesh->SetupAttachment(TankMesh);

	NeedleCenterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NeedleCenterMesh"));
	NeedleCenterMesh->SetupAttachment(ManometerMesh);

	NeedleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NeedleMesh"));
	NeedleMesh->SetupAttachment(NeedleCenterMesh);

	NeedleCenterMesh->SetRelativeRotation(FRotator(0,0,-207));
	RotSpeed = 1;
	OxygenValue = 0;
	bIsLeaking = false;
	counter = 0;
}

// Called when the game starts or when spawned
void AOxygen::BeginPlay()
{
	Super::BeginPlay();
	NiagaraSystem->Deactivate();
}

// Called every frame
void AOxygen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(OxygenValue < 207.f)
	{
		if(bIsLeaking)
		{
			RotSpeed = 10.0f;
		}
		else
		{
			RotSpeed = 1.0f;
		}
		const FRotator NewRotation = FRotator(0,0,DeltaTime * RotSpeed);
		OxygenValue += DeltaTime * RotSpeed;
		NeedleCenterMesh->AddRelativeRotation(NewRotation);
	}
	counter += DeltaTime;
	if(counter > 5.0f)
	{
		SetIsLeaking();
		counter = 0;
	}
}

void AOxygen::SetIsLeaking()
{
	bIsLeaking = !bIsLeaking;
	if(bIsLeaking)
	{
		NiagaraSystem->Activate();
	}
	else
	{
		NiagaraSystem->Deactivate();
	}
}