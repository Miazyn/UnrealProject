// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UInventoryComponent.h"
#include "GameFramework/Character.h"
#include "UI/InventoryItemWidget.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class UNREALPROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = true))
	UInventoryComponent* PlayerInventory;

	int InventorySize = 32;
	int ItemCap = 99;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	TArray<UInventoryItemWidget*> ItemWidgets;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	TSubclassOf<class UInventoryWidget> InventoryWidget;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "LightCycle")
	TSubclassOf<class ALightCycle> LightCycle;
private:
	void MoveForward(float AxisValue);
	void LookUp(float AxisValue);

	void MoveRight(float AxisValue);
	void LookRight(float AxisValue);

	void Interact();
};
