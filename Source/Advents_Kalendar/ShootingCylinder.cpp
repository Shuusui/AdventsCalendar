// Fill out your copyright notice in the Description page of Project Settings.

#include "ShootingCylinder.h"
#include "Bullet.h"

// Sets default values
AShootingCylinder::AShootingCylinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CylinderRoot = CreateDefaultSubobject<USceneComponent>( TEXT("Root")); 
	RootComponent = CylinderRoot; 

	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Cylinder")); 
	Cylinder->SetupAttachment(CylinderRoot); 

	delay = 3; 

}

// Called when the game starts or when spawned
void AShootingCylinder::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandle, this, &AShootingCylinder::ShootFrequently, delay, true); 
}

// Called every frame
void AShootingCylinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShootingCylinder::ShootFrequently()
{
	FVector Loc = GetActorLocation() + GetActorForwardVector() * 100; 
	FRotator Rot = GetActorRotation();  
	UWorld* const World = GetWorld(); 
	if (World != NULL)
	{
		World->SpawnActor<ABullet>(BulletClass, Loc, Rot);
	}
}
	
