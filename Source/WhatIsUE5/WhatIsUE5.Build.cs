// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class WhatIsUE5 : ModuleRules
{
	public WhatIsUE5(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
