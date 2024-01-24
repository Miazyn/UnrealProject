// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "APawnBase.h"
#include "UInventoryComponent.h"
#include "APlayerPawn.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API AAPlayerPawn : public AAPawnBase
{
	GENERATED_BODY()

public:
	AAPlayerPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = true))
	UInventoryComponent* InventoryComp;
};
