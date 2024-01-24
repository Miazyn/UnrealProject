// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.h"
#include "GameFramework/Actor.h"
#include "APickUp.generated.h"

class UCapsuleComponent;

UCLASS()
class UNREALPROJECT_API AAPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAPickUp();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = true))
	UCapsuleComponent* CapsuleComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta= (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory");
	UItem* ItemPickUp;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
