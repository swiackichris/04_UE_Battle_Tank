// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class TankAimingComponent;

/**
*
*/

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
	
	
