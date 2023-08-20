// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCubyController.h"
#include <Kismet/GameplayStatics.h>
#include <Camera/CameraActor.h>
#include "Cuby.h"
#include "Ball.h"


void AMyCubyController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("LookRight", this, &AMyCubyController::MoveCuby);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMyCubyController::TriggerJump);
}

//This function is called when the player presses space
//It finds the Aball in the scene and changes the bool "bBallInMotion" to false
//The ball is then set to motion and it no longer follows the paddle's movement
void AMyCubyController::TriggerJump()
{
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("Ball")), foundActors);
	
	for (AActor* Actor : foundActors)
	{
		ABall* ballRef = Cast<ABall>(Actor);
		if (Actor && ballRef->GetBallInMotion() != true)
		{
			ballRef->SetBallInMotion();
			ballRef->MovingBall();
		}
	}
}

//This function is called everytime the mouse is moved
//It accesses the default pawn which is ACuby and moves it with respect to the mouse movement
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