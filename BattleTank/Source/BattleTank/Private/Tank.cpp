// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"


// Sets default values
ATank::ATank()
{
	UE_LOG(LogTemp, Warning, TEXT("PREFIX TANK Constructor Working")); // TODO remove this log
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("PREFIX TANK BeginPlay Working"));
	Super::BeginPlay(); // TODO remove this function needed for BP begin play to run!
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool isReloaded = (GetWorld()->GetRealTimeSeconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded)
	{

		// Spawn a projectile at the socket location on the barrel	
		auto Projectile = GetWorld()->SpawnActor<AProjectile>
			(
				Projectileblueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
				);

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetRealTimeSeconds();
	}
}

