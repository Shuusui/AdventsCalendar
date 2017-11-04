// Fill out your copyright notice in the Description page of Project Settings.

#include "Collectable_Cone.h"
#include "Engine/TriggerBox.h"
#include "Classes/Components/BoxComponent.h"
#include "FinishScreen.h"

// Sets default values
ACollectable_Cone::ACollectable_Cone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollectableRoot = CreateDefaultSubobject<USceneComponent>( TEXT("Root")); 
	RootComponent = CollectableRoot; 

	Cone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collectable")); 
	Cone->SetupAttachment(CollectableRoot);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox")); 
	TriggerBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	TriggerBox->bGenerateOverlapEvents = true; 
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ACollectable_Cone::OnPlayerEnterPickupBox); 
	TriggerBox->SetupAttachment(CollectableRoot);

	finishScreen = CreateDefaultSubobject<AFinishScreen>(TEXT("FinishScreen")); 
}

// Called when the game starts or when spawned
void ACollectable_Cone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectable_Cone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectable_Cone::OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	finishScreen->SetVisible(true);
	Destroy();
}