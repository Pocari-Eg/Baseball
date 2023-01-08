// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BaseballProject : ModuleRules
{
	public BaseballProject(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
