// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DeformMesh.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "GlobalShader.h"

IMPLEMENT_GAME_MODULE(FDeformMesh, DeformMesh);

void FDeformMesh::StartupModule()
{
	// Maps virtual shader source directory to actual shaders directory on disk.
	const FString ShaderDirectory = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("Shaders/Private"));
	//AddShaderSourceDirectoryMapping("/CustomShaders", ShaderDirectory);
}

void FDeformMesh::ShutdownModule()
{
}

