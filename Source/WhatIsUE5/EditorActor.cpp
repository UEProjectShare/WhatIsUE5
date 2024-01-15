// Fill out your copyright notice in the Description page of Project Settings.


#include "EditorActor.h"

// Sets default values
AEditorActor::AEditorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEditorActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEditorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

#if WITH_EDITOR
	if (GIsEditor)
	{
		FEditorScriptExecutionGuard ScriptGuard;
		EditorTick(DeltaTime);
	}
#endif
}

bool AEditorActor::ShouldTickIfViewportsOnly() const
{
	if (const UWorld* World = GetWorld())
	{
		switch (World->WorldType)
		{
		case EWorldType::Game:
		case EWorldType::GameRPC:
		case EWorldType::PIE:
			return true;
		case EWorldType::Editor:
			return true;
		case EWorldType::EditorPreview:
			return false;
		case EWorldType::GamePreview:
			return false;
		default: ;
		}
	}
	return false;
}

void AEditorActor::EditorTick_Implementation(float DeltaSeconds)
{
}

