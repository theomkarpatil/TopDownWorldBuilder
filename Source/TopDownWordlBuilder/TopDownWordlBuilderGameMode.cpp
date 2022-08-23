// Copyright Epic Games, Inc. All Rights Reserved.

#include "TopDownWordlBuilderGameMode.h"
#include "TopDownWordlBuilderPlayerController.h"
#include "TopDownWordlBuilderCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATopDownWordlBuilderGameMode::ATopDownWordlBuilderGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATopDownWordlBuilderPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/Player/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/Player/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}