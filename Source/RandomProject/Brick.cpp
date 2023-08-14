// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include <Components/BoxComponent.h>
#include "Ball.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	brickCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Brick Collider"));
	SetRootComponent(brickCollider);

	brickMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick Mesh"));
	brickMesh->SetupAttachment(brickCollider);

	//brickCollider->OnComponentHit.AddDynamic(this, &ABrick::OnHit);
}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("Overlapped"));
	if (OtherActor->IsA(ABall::StaticClass()))
	{
		UE_LOG(LogTemp, Warning, TEXT("ABrick::OnHit"));
		brickMesh->DestroyComponent();
		brickCollider->DestroyComponent();
	}
}