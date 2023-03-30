// Copyright Epic Games, Inc. All Rights Reserved.

#include "EndlessRunnerGameMode.h"
#include "EndlessRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

#include <Blueprint/UserWidget.h>

AEndlessRunnerGameMode::AEndlessRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AEndlessRunnerGameMode::BeginPlay()
{
	Super::BeginPlay();
	ChangeMenuWidget(startingWidgetClass);
}

void AEndlessRunnerGameMode::ChangeMenuWidget(TSubclassOf<UUserWidget> _NewWidgetClass)
{
	if (currentWidget != nullptr)
	{
		currentWidget->RemoveFromViewport();
		currentWidget = nullptr;
	}

	if (_NewWidgetClass != nullptr)
	{
		currentWidget = CreateWidget(GetWorld(), _NewWidgetClass);
		if (currentWidget != nullptr)
		{
			currentWidget->AddToViewport();
		}
	}
}