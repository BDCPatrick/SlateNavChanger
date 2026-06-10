/* Copyright © beginning at 2026 - BlackDevilCreations
* Author: Patrick Wenzel
* All rights reserved.
* This file and the corresponding Definition is part of a BlackDevilCreations project and may not be distributed, copied,
* or modified without prior written permission from BlackDevilCreations.
* Unreal Engine and its associated trademarks are property of Epic Games, Inc.
* and are used with permission.
*/

#pragma once

#include "CoreMinimal.h"
#include "InputCoreTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SlateChangerLibrary.generated.h"

USTRUCT(BlueprintType)
struct FSlateNavigationKeys
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey Up;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey Down;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey Left;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey Right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey Next;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey Previous;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey AcceptKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey BackKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey AnalogHorizontalKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BDC|Slate Navigation")
	FKey AnalogVerticalKey;

	FSlateNavigationKeys()
	{
		Up = EKeys::Gamepad_DPad_Up;
		Down = EKeys::Gamepad_DPad_Down;
		Left = EKeys::Gamepad_DPad_Left;
		Right = EKeys::Gamepad_DPad_Right;
		Next = EKeys::Tab;
		Previous = EKeys::Backslash;
		AcceptKey = EKeys::Gamepad_FaceButton_Bottom;
		BackKey = EKeys::Gamepad_FaceButton_Right;
		AnalogHorizontalKey = EKeys::Gamepad_LeftX;
		AnalogVerticalKey = EKeys::Gamepad_LeftY;
	}
};

/**
 * Blueprint Function Library for changing Slate Navigation configuration.
 */
UCLASS()
class BDC_SLATENAVIGATIONCHANGER_API USlateChangerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Updates the global Slate Navigation Configuration with custom keys.
	 * @param NavigationKeys The new key bindings for Slate navigation.
	 */
	UFUNCTION(BlueprintCallable, Category = "BDC|Slate Navigation")
	static void UpdateSlateNavigationConfig(const FSlateNavigationKeys& NavigationKeys);

	/**
	 * Gets the current Slate Navigation Configuration keys.
	 * @param CurrentKeys The current key bindings.
	 */
	UFUNCTION(BlueprintPure, Category = "BDC|Slate Navigation")
	static void GetCurrentSlateNavigationConfig(FSlateNavigationKeys& CurrentKeys);
};
