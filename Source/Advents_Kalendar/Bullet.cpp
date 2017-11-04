// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletRoot = CreateDefaultSubobject<USphereComponent>( TEXT("Root")); 
	BulletRoot->InitSphereRadius(2.0f); 
	BulletRoot->BodyInstance.SetCollisionProfileName("Bullet"); 


	RootComponent = BulletRoot; 

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp")); 
	ProjectileMovement->UpdatedComponent = BulletRoot; 
	ProjectileMovement->InitialSpeed = 7000.f;  
	ProjectileMovement->MaxSpeed = 7000.f; 
	ProjectileMovement->bRotationFollowsVelocity = true; 
	ProjectileMovement->bShouldBounce = true; 




}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 1000.0f, GetActorLocation()); 

		Destroy(); 
	}
}


