#include "CustomComputeShader.h"

DEFINE_LOG_CATEGORY(CustomComputeShader);

#define LOCTEXT_NAMESPACE "FCustomComputeShader"

void FCustomComputeShader::StartupModule()
{
	UE_LOG(CustomComputeShader, Warning, TEXT("CustomComputeShader module has been loaded"));
}

void FCustomComputeShader::ShutdownModule()
{
	UE_LOG(CustomComputeShader, Warning, TEXT("CustomComputeShader module has been unloaded"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FCustomComputeShader, CustomComputeShader)