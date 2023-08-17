// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Cuby.generated.h"

UCLASS()
class RANDOMPROJECT_API ACuby : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACuby();
	
	UPROPERTY(EditAnywhere, Category = "Cuby Config")
	class UStaticMeshComponent* cubyMesh;

	UPROPERTY(EditAnywhere, Category = "Cuby Config")
	class UBoxComponent* cubyCollider;

	UPROPERTY(EditAnywhere, Category = "Cuby Config")
	float cubyJumpForce;

	UPROPERTY(EditAnywhere, Category = "Cuby Config")
	float speed;

	UFUNCTION()
		void MoveRight();

	UFUNCTION()
		void MoveLeft();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void ConstraintRotation();
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
