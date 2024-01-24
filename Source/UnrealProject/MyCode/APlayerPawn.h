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

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 800.f;
	UPROPERTY(EditAnywhere)
	float RotateSpeed = 250.f;

	FVector MoveDirection;
	FQuat RotationDirection;

	void CalculateMovementInput(float Value);
	void CalculateRotationInput(float Value);
	
	void Move();
	void Rotate();


	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Tick(float DeltaSeconds) override;
};
