// Fill out your copyright notice in the Description page of Project Settings.

#include "Cuby.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>
#include "MyCubyController.h"

// Sets default values
ACuby::ACuby()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setting up mesh component for cuby
	cubyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cuby"));
	RootComponent = cubyMesh;

	cubyCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Cuby Collider"));
	cubyCollider->SetupAttachment(cubyMesh);
}

// Called when the game starts or when spawned
void ACuby::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ACuby::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ConstraintRotation();
	
	//Will call depending on earned points
	//ShrinkPaddle();
}

// Called to bind functionality to input
void ACuby::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACuby::CubyJump()
{
	//// Calculate the force to apply in the direction of the Pawn's forward vector

	//FVector ForceDirection = GetActorUpVector();
	//FVector AppliedForce = ForceDirection * 5070;

	//// Apply the force to the cubyMesh
	//cubyMesh->AddImpulse(AppliedForce);

	//UE_LOG(LogTemp, Warning, TEXT("pressed space"));
}

void ACuby::ConstraintRotation()
{
	const FRotator cubyRotation = FRotator(0.0f, 0.0f, 0.0f);
	cubyMesh->SetWorldRotation(cubyRotation);

}


void ACuby::ShrinkPaddle()
{
	if (GetActorScale().Y > 0.3f)
	{
		FVector shrinkRate = FVector(0.f, 0.01f, 0.);
		FVector newScale = FVector(GetActorScale().X, (GetActorScale().Y - (shrinkRate.Y)), GetActorScale().Z);
		SetActorScale3D(newScale);
	}
}




void ACuby::MoveRight()
{
	FVector currentLocation = cubyMesh->GetComponentLocation();
	if (currentLocation.Y < 121.0f)
	{
		FVector newLocation = FVector(0.f, currentLocation.Y + 0.02f * speed, currentLocation.Z);
		SetActorLocation(newLocation);
		//UE_LOG(LogTemp, Warning, TEXT("MoveRight() being triggered"));
	}
}
void ACuby::MoveLeft()
{
	FVector currentLocation = cubyMesh->GetComponentLocation();
	if (currentLocation.Y > -101.0f)
	{
		FVector newLocation = FVector(0.f, currentLocation.Y + 0.02f * -speed, currentLocation.Z);
		SetActorLocation(newLocation);
		//UE_LOG(LogTemp, Warning, TEXT("MoveLeft() being triggered"));
	}
}
