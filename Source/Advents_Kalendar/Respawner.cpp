// Fill out your copyright notice in the Description page of Project Settings.

#include "Respawner.h"
#include "Advents_KalendarCharacter.h"

// Sets default values
ARespawner::ARespawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ARespawner::BeginPlay()
{
	Super::BeginPlay();
	StartPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

}

// Called every frame
void ARespawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z < -500)
		GetWorld()->GetFirstPlayerController()->GetPawn()->SetActorLocation(StartPosition); 

}

