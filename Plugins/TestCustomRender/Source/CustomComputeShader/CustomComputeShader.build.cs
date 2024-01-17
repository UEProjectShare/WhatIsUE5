using UnrealBuildTool;
 
public class CustomComputeShader : ModuleRules
{
	public CustomComputeShader(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "CustomShadersDeclarations" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine"});
 
		PublicIncludePaths.AddRange(new string[] {"CustomComputeShader/Public"});
		PrivateIncludePaths.AddRange(new string[] {"CustomComputeShader/Private"});
	}
}