// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootingCylinder.generated.h"

UCLASS()
class ADVENTS_KALENDAR_API AShootingCylinder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShootingCylinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void ShootFrequently();


	UPROPERTY(EditAnywhere, Category = Cylinder)
		class USceneComponent* CylinderRoot; 
	UPROPERTY(EditAnywhere, Category = Cylinder)
		class UStaticMeshComponent* Cylinder; 
	UPROPERTY(EditAnywhere, Category = Bullet)
		TSubclassOf<class ABullet> BulletClass;

	FTimerHandle timerHandle; 
	UPROPERTY(EditAnywhere, Category = Bullet)
		int32 delay; 
};
