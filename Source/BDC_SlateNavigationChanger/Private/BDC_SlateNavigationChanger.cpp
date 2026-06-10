/* Copyright © beginning at 2026 - BlackDevilCreations
* Author: Patrick Wenzel
* All rights reserved.
* This file and the corresponding Definition is part of a BlackDevilCreations project and may not be distributed, copied,
* or modified without prior written permission from BlackDevilCreations.
* Unreal Engine and its associated trademarks are property of Epic Games, Inc.
* and are used with permission.
*/

#include "BDC_SlateNavigationChanger.h"

#define LOCTEXT_NAMESPACE "FBDC_SlateNavigationChangerModule"

void FBDC_SlateNavigationChangerModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FBDC_SlateNavigationChangerModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBDC_SlateNavigationChangerModule, BDC_SlateNavigationChanger)