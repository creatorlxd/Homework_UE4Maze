// Copyright Epic Games, Inc. All Rights Reserved.

#include "MazeGameMode.h"
#include "MazePlayerController.h"
#include "MazeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMazeGameMode::AMazeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMazePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}