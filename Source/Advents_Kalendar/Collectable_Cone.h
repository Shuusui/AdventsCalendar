// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectable_Cone.generated.h"

UCLASS()
class ADVENTS_KALENDAR_API ACollectable_Cone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectable_Cone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
		class USceneComponent* CollectableRoot; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collectable)
		class UStaticMeshComponent* Cone; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collectable)
		class UShapeComponent* TriggerBox; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collectable)
		class AFinishScreen* finishScreen; 
	UFUNCTION()
		void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OhterComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
};
