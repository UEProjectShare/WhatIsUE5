#pragma once

#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(CustomComputeShader, All, All);

class FCustomComputeShader : public IModuleInterface
{
public:
	static inline FCustomComputeShader& Get()
	{
		return FModuleManager::LoadModuleChecked<FCustomComputeShader>("FCustomComputeShader");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("FCustomComputeShader");
	}

	/* Called when the module is loaded */
	virtual void StartupModule() override;

	/* Called when the module is unloaded */
	virtual void ShutdownModule() override;
};