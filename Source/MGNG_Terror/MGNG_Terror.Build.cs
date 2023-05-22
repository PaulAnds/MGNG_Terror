// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MGNG_Terror : ModuleRules
{
	public MGNG_Terror(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
