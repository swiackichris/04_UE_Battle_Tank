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

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	// How close can the AI tank get
	float AcceptanceRadius = 3000;
};
	
	
