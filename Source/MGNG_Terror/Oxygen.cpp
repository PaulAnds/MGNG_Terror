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
	RotSpeed = 0.5f;
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
		const FRotator NewRotation = FRotator(0,0,DeltaTime * RotSpeed);
		OxygenValue += DeltaTime * RotSpeed;
		NeedleCenterMesh->AddRelativeRotation(NewRotation);
	}
}

void AOxygen::SetIsLeaking()
{
	bIsLeaking = !bIsLeaking;
	if(bIsLeaking)
	{
		NiagaraSystem->Activate();
		RotSpeed = 3.0f;
	}
	else
	{
		NiagaraSystem->Deactivate();
		RotSpeed = 0.5f;
	}
}

float AOxygen::GetOxygenValue()
{
	return OxygenValue;
}
