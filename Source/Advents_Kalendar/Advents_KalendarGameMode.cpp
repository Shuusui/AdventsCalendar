// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Advents_KalendarGameMode.h"
#include "Advents_KalendarCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAdvents_KalendarGameMode::AAdvents_KalendarGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
