// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class RANDOMPROJECT_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	UPROPERTY(EditAnywhere, Category = "Brick Config")
	class UBoxComponent* brickCollider;
	
	UPROPERTY(EditAnywhere, Category = "Brick Config")
	class UStaticMeshComponent* brickMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
