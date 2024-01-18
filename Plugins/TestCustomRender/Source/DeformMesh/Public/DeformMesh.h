// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class FDeformMesh : public IModuleInterface
{
public:
	static inline FDeformMesh& Get()
	{
		return FModuleManager::LoadModuleChecked<FDeformMesh>("DeformMesh");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("DeformMesh");
	}
	
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
