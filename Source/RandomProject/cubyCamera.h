// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "cubyCamera.generated.h"

UCLASS()
class RANDOMPROJECT_API AcubyCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcubyCamera();

	UPROPERTY(EditAnywhere, Category = "Camera")
		AActor* myCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	class UCameraComponent* mainCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
