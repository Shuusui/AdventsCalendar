// Fill out your copyright notice in the Description page of Project Settings.

#include "ACGameMode.h"
#include "DefaultPlayerController.h"



AACGameMode::AACGameMode()
{
	PlayerControllerClass = ADefaultPlayerController::StaticClass();

}


