// Fill out your copyright notice in the Description page of Project Settings.

#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/SphereComponent.h>
#include <Kismet/GameplayStatics.h>
#include "MyCubyController.h"
#include "CubyGameManager.h"
#include "Brick.h"
#include "Ball.h"
#include "Cuby.h"


// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//SETTING DEFAULT CONFIGURATION FOR THE BALL//
	/////////////////////////////////////////////
	ballCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Ball Collider"));
	SetRootComponent(ball);

	ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	ball->SetupAttachment(ballCollider);

	ballMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Ball Projectile Component"));
	ballMovement->InitialSpeed = 0;
	ballMovement->MaxSpeed = 0;
	bBallInMotion = false;

	ballCollider->OnComponentHit.AddDynamic(this, &ABall::OnHit);

	/////////////////////////////////////////////
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

	if (bBallInMotion == false)
	{
		FollowPaddle();
	}

	//To Restrict the ball from moving in the X-Axis
	FVector CurrentLocation = GetActorLocation();
	FVector RestrictedLocation = FVector(0.f, CurrentLocation.Y, CurrentLocation.Z);
	SetActorLocation(RestrictedLocation);
}


//Destroys the brick it touches and also adds a point
void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor->IsA(ABrick::StaticClass()))
	{
		OtherActor->Destroy();
		SetPoints(GetPoints()+1);
		//UE_LOG(LogTemp, Warning, TEXT("Points Accumulated: %d"), GetPoints());
	}

	if (OtherActor->ActorHasTag("BottomTrigger"))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Bottom Trigger touched"));
		RestartLevel();
	}
}

//Until the player presses "Spacebar" the ball will follow the paddle
void ABall::FollowPaddle()
{
	AMyCubyController* playerController =Cast<AMyCubyController>(UGameplayStatics::GetPlayerController(this, 0));

	if (playerController)
	{
		ACuby* paddle = Cast<ACuby>(playerController->GetPawn());

		if (paddle)
		{
			ballMovement->Velocity.X = 0;
			ballMovement->Velocity.Y = 0;
			ballMovement->Velocity.Z = 0;

			FVector ballStallLocation = FVector(0, paddle->GetActorLocation().Y,20);
			SetActorLocation(ballStallLocation);
		}
	}	
}


//After the player presses the "Spacebar" this function sets the ball in motion
void ABall::MovingBall()
{
	ballMovement->Velocity.X = 0;
	ballMovement->Velocity.Y = 200;
	ballMovement->Velocity.Z = 200;
}

//To stop the ball from being idle
void ABall::SetBallInMotion()
{
	bBallInMotion = true;
}

void ABall::RestartLevel()
{
	ACubyGameManager* gameManager = Cast<ACubyGameManager>(UGameplayStatics::GetGameMode(this));

	if (gameManager)
	{
		FString levelName = UGameplayStatics::GetCurrentLevelName(this);
		UGameplayStatics::OpenLevel(this, *levelName);
	}
}
