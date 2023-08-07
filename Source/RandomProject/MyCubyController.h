// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyCubyController.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMPROJECT_API AMyCubyController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyCubyController();

	UPROPERTY()
	class ACuby* cuby;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;
	virtual void TriggerJump();
	virtual void MoveCuby(float AxisValue);

};
