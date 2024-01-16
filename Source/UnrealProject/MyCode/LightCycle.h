// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LightCycle.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API ULightCycle : public UObject
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable, Category = "LightCycle")
		void TransitionToDay();
};
