// Copyright Epic Games, Inc. All Rights Reserved.

#include "MGNG_TerrorGameMode.h"
#include "MGNG_TerrorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMGNG_TerrorGameMode::AMGNG_TerrorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
