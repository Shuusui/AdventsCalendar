// Fill out your copyright notice in the Description page of Project Settings.

#include "FinishScreen.h"


// Sets default values
AFinishScreen::AFinishScreen(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpriteRoot = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root")); 
	RootComponent = SpriteRoot; 

	Plane = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Plane")); 
	Plane->SetupAttachment(SpriteRoot); 

	//SpriteRoot->SetVisibility(false); 
}

// Called when the game starts or when spawned
void AFinishScreen::BeginPlay()
{
	Super::BeginPlay();
	Plane->SetVisibility(false);
}

// Called every frame
void AFinishScreen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFinishScreen::SetVisible(bool bIsVisible)
{
	if (!bIsVisible)
	{
		if (Plane->bVisible)
		{
			Plane->SetVisibility(false);
		}
	}
	else
	{
		if (!Plane->bVisible)
		{
			Plane->SetVisibility(true);
		}
	}
}