// Copyright Epic Games, Inc. All Rights Reserved.

#include "WhatIsUE5GameMode.h"
#include "WhatIsUE5Character.h"
#include "UObject/ConstructorHelpers.h"

AWhatIsUE5GameMode::AWhatIsUE5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
