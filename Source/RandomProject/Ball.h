// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class RANDOMPROJECT_API ABall : public AActor
{
	GENERATED_BODY()
	
private:
	int points;

	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(EditAnywhere, Category = "Ball Config")
		class UStaticMeshComponent* ball;

	UPROPERTY(EditAnywhere, Category = "Ball Config")
		class USphereComponent* ballCollider;

	UPROPERTY(EditAnywhere, Category = "Ball Config")
		class UProjectileMovementComponent* ballMovement;

	UPROPERTY(EditAnywhere, Category = "Ball Config")
		class ACuby* paddleRef;

		bool bBallInMotion;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SetPoints(int pts)
	{
		points = pts;
	}
	int GetPoints()
	{
		return points;
	}

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void FollowPaddle();
	void RestartLevel();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetBallInMotion();
	void MovingBall();
};
