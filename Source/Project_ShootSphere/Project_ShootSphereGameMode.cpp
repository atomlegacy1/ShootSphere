// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_ShootSphereGameMode.h"
#include "Project_ShootSphereCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_ShootSphereGameMode::AProject_ShootSphereGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
