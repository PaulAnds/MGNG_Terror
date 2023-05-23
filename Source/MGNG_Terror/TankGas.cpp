// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGas.h"

// Sets default values
ATankGas::ATankGas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TankMesh"));
	RootComponent = TankMesh;
}

// Called when the game starts or when spawned
void ATankGas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankGas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

