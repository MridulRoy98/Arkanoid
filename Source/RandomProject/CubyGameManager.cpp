// Fill out your copyright notice in the Description page of Project Settings.


#include "CubyGameManager.h"
#include "Cuby.h"
#include "GameFramework/PlayerController.h"
ACubyGameManager::ACubyGameManager()
{
	DefaultPawnClass = ACuby::StaticClass();
}

void ACubyGameManager::BeginPlay()
{	
	
}
