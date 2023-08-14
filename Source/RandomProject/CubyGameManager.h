// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CubyGameManager.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMPROJECT_API ACubyGameManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACubyGameManager();

protected:
	virtual void BeginPlay() override;
};
