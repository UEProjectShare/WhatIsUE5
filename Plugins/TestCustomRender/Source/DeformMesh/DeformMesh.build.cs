using UnrealBuildTool;
 
public class DeformMesh : ModuleRules
{
	public DeformMesh(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{ 
			"Core",
			"CoreUObject",
			"Engine",
			"InteractiveToolsFramework",
			"MeshDescription",
			"RenderCore",
			"RHI",
			"StaticMeshDescription"
		});
 
		PublicIncludePaths.AddRange(new string[] {"DeformMesh/Public"});
		PrivateIncludePaths.AddRange(new string[] {"DeformMesh/Private"});
	}
}