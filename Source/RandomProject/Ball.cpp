// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/SphereComponent.h>
#include "Brick.h"

// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ballCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Ball Collider"));
	SetRootComponent(ball);

	ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	ball->SetupAttachment(ballCollider);

	ballMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Ball Projectile Component"));

	ballCollider->OnComponentHit.AddDynamic(this, &ABall::OnHit);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector RestrictedLocation = FVector(0.f, CurrentLocation.Y, CurrentLocation.Z);
	SetActorLocation(RestrictedLocation);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->IsA(ABrick::StaticClass()))
	{
		OtherActor->Destroy();
		SetPoints(GetPoints()+1);

		UE_LOG(LogTemp, Warning, TEXT("Points Accumulated: %d"), GetPoints());
	}
}