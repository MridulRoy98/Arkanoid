// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCubyController.h"
#include "Cuby.h"
#include <Kismet/GameplayStatics.h>
#include <Camera/CameraActor.h>

AMyCubyController::AMyCubyController()
{
}

void AMyCubyController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("LookRight", this, &AMyCubyController::MoveCuby);
}

void AMyCubyController::Tick(float DeltaTime)
{
}

void AMyCubyController::BeginPlay()
{
	cuby = NewObject<ACuby>(this);


	TArray<AActor*>CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);
	
	FViewTargetTransitionParams params;
	SetViewTarget(CameraActors[1], params);
}

void AMyCubyController::TriggerJump()
{
}

void AMyCubyController::MoveCuby(float AxisValue)
{
	if (AxisValue > 0.09f && cuby)
	{
		cuby->MoveRight();
	}
	else if (AxisValue < -0.09f && cuby)
	{
		cuby->MoveLeft();
	}
	if (!cuby)
	{
		UE_LOG(LogTemp, Warning, TEXT("NullPtr"));
	}

	GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("Axis Value: %f"), AxisValue));
}
