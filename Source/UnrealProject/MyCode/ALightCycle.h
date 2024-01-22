// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Engine/DirectionalLight.h"

#include "ALightCycle.generated.h"

UCLASS()
class UNREALPROJECT_API ALightCycle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightCycle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	ADirectionalLight* DirectionalLight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double RotationDegree = 180.0f;

	bool bIsNight = false;

	UFUNCTION(BlueprintCallable, Category="Light Cycle")
	void LightCycleFlipFlop();

};
