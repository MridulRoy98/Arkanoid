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
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyCubyController::JumpCuby);
}

void AMyCubyController::BeginPlay()
{
}

void AMyCubyController::TriggerJump()
{
}

void AMyCubyController::MoveCuby(float AxisValue)
{
	ACuby* ControlledPawn = Cast<ACuby>(GetPawn());

	if (ControlledPawn)
	{
		if (AxisValue > 0.03f)
		{
			ControlledPawn->MoveRight();
		}
		else if (AxisValue < -0.03f)
		{
			ControlledPawn->MoveLeft();
		}
		if (!ControlledPawn)
		{
			UE_LOG(LogTemp, Warning, TEXT("NullPtr"));
		}
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Green, FString::Printf(TEXT("Axis Value: %f"), AxisValue));
	}
}

void AMyCubyController::JumpCuby()
{
	ACuby* ControlledPawn = Cast<ACuby>(GetPawn());

	if (ControlledPawn)
	{
		ControlledPawn->CubyJump();
	}
}
