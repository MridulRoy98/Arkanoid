// Fill out your copyright notice in the Description page of Project Settings.


#include "cubyCamera.h"
#include <Camera/CameraComponent.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
AcubyCamera::AcubyCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Cuby Camera"));
	mainCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	SetRootComponent(mainCamera);
}

// Called when the game starts or when spawned
void AcubyCamera::BeginPlay()
{
	Super::BeginPlay();
	
	if (myCamera)
	{
		APlayerController* myPlayer = UGameplayStatics::GetPlayerController(this, 0);
		
		if (myPlayer)
		{
			myPlayer->SetViewTarget(myCamera);
		}
	}
}

// Called every frame
void AcubyCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

