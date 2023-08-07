// Fill out your copyright notice in the Description page of Project Settings.


#include "CubyGameManager.h"
#include "Camera/CameraActor.h"
#include "Cuby.h"
ACubyGameManager::ACubyGameManager()
{
	DefaultPawnClass = ACuby::StaticClass();
}

void ACubyGameManager::BeginPlay()
{

}

void ACubyGameManager::SetMainCamera(ACameraActor* myCamera)
{
	if (myCamera)
	{
		
	}
}
