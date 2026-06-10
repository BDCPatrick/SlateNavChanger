/* Copyright © beginning at 2026 - BlackDevilCreations
* Author: Patrick Wenzel
* All rights reserved.
* This file and the corresponding Definition is part of a BlackDevilCreations project and may not be distributed, copied,
* or modified without prior written permission from BlackDevilCreations.
* Unreal Engine and its associated trademarks are property of Epic Games, Inc.
* and are used with permission.
*/

#include "SlateChangerLibrary.h"

#include "InputCoreTypes.h"
#include "Framework/Application/NavigationConfig.h"
#include "Framework/Application/SlateApplication.h"

#pragma region Custom Navigation Config
/**
 * Custom navigation configuration to override default Slate keys.
 */
class FBDCNavigationConfig : public FNavigationConfig
{
public:
	FBDCNavigationConfig(const FSlateNavigationKeys& NavigationKeys)
	{
		KeyEventRules.Empty();
		
		auto AddRule = [this](const FKey& Key, EUINavigation Nav)
		{
			if (Key.IsValid() && Key != EKeys::Invalid)
			{
				KeyEventRules.Add(Key, Nav);
			}
		};

		AddRule(NavigationKeys.Up, EUINavigation::Up);
		AddRule(NavigationKeys.Down, EUINavigation::Down);
		AddRule(NavigationKeys.Left, EUINavigation::Left);
		AddRule(NavigationKeys.Right, EUINavigation::Right);
		AddRule(NavigationKeys.Next, EUINavigation::Next);
		AddRule(NavigationKeys.Previous, EUINavigation::Previous);
		AddRule(NavigationKeys.AcceptKey, static_cast<EUINavigation>(7));
		AddRule(NavigationKeys.BackKey, static_cast<EUINavigation>(8));

		AnalogHorizontalKey = NavigationKeys.AnalogHorizontalKey;
		AnalogVerticalKey = NavigationKeys.AnalogVerticalKey;

		// Disable default tab navigation handling in FNavigationConfig if we want full control
		bTabNavigation = false;
		bKeyNavigation = true;
		bAnalogNavigation = true;
	}
};
#pragma endregion

#pragma region Blueprint Functions
void USlateChangerLibrary::UpdateSlateNavigationConfig(const FSlateNavigationKeys& NavigationKeys)
{
	if (FSlateApplication::IsInitialized())
	{
		const TSharedRef<FBDCNavigationConfig> Config = MakeShared<FBDCNavigationConfig>(NavigationKeys);
		FSlateApplication::Get().SetNavigationConfig(Config);
	}
}

void USlateChangerLibrary::GetCurrentSlateNavigationConfig(FSlateNavigationKeys& CurrentKeys)
{
	if (FSlateApplication::IsInitialized())
	{
		const TSharedRef<FNavigationConfig> CurrentConfig = FSlateApplication::Get().GetNavigationConfig();
		for (const TPair<FKey, EUINavigation>& Rule : CurrentConfig->KeyEventRules)
		{
			const EUINavigation NavValue = Rule.Value;
			if (NavValue == EUINavigation::Up) CurrentKeys.Up = Rule.Key;
			else if (NavValue == EUINavigation::Down) CurrentKeys.Down = Rule.Key;
			else if (NavValue == EUINavigation::Left) CurrentKeys.Left = Rule.Key;
			else if (NavValue == EUINavigation::Right) CurrentKeys.Right = Rule.Key;
			else if (NavValue == EUINavigation::Next) CurrentKeys.Next = Rule.Key;
			else if (NavValue == EUINavigation::Previous) CurrentKeys.Previous = Rule.Key;
			else if (static_cast<int32>(NavValue) == 7) CurrentKeys.AcceptKey = Rule.Key;
			else if (static_cast<int32>(NavValue) == 8) CurrentKeys.BackKey = Rule.Key;
		}

		CurrentKeys.AnalogHorizontalKey = CurrentConfig->AnalogHorizontalKey;
		CurrentKeys.AnalogVerticalKey = CurrentConfig->AnalogVerticalKey;
	}
}
#pragma endregion
