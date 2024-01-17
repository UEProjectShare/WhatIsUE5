using UnrealBuildTool;
 
public class CustomComputeShader : ModuleRules
{
	public CustomComputeShader(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 				
			"Core",
			"CoreUObject",
			"Engine",
			"Renderer",
			"RenderCore",
			"RHI",
			"Projects"
			
		});
 
		PublicIncludePaths.AddRange(new string[] {"CustomComputeShader/Public"});
		PrivateIncludePaths.AddRange(new string[] {"CustomComputeShader/Private"});
	}
}