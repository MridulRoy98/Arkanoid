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
}

void ACuby::ConstraintRotation()
{
	const FRotator cubyRotation = FRotator(0.0f, 0.0f, 0.0f);
	cubyMesh->SetWorldRotation(cubyRotation);

}

void ACuby::MoveRight()
{
	FVector currentLocation = cubyMesh->GetComponentLocation();
	if (currentLocation.Y < 121.0f)
	{
		FVector newLocation = FVector(0.f, currentLocation.Y + 0.02f * speed, currentLocation.Z);
		SetActorLocation(newLocation);
	}
}
void ACuby::MoveLeft()
{
	FVector currentLocation = cubyMesh->GetComponentLocation();
	if (currentLocation.Y > -101.0f)
	{
		FVector newLocation = FVector(0.f, currentLocation.Y + 0.02f * -speed, currentLocation.Z);
		SetActorLocation(newLocation);
	}
}
