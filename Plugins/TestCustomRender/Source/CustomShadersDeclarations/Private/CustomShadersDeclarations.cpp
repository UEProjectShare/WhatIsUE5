// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CustomShadersDeclarations.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "GlobalShader.h"

IMPLEMENT_GAME_MODULE( FCustomShadersDeclarationsModule, CustomShadersDeclarations);


void FCustomShadersDeclarationsModule::StartupModule()
{
	// Maps virtual shader source directory to actual shaders directory on disk.
	const FString ShaderDirectory = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("TestCustomRender/Shaders/Private"));
	AddShaderSourceDirectoryMapping("/CustomShaders", ShaderDirectory);
}

void FCustomShadersDeclarationsModule::ShutdownModule()
{
}

