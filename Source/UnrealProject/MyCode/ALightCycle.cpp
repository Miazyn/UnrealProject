// Fill out your copyright notice in the Description page of Project Settings.


#include "ALightCycle.h"

// Sets default values
ALightCycle::ALightCycle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALightCycle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightCycle::LightCycleFlipFlop()
{
	if (DirectionalLight)
	{
		if (bIsNight)
		{
			DirectionalLight->AddActorLocalRotation(FRotator(0, RotationDegree, 0));
		}
		else
		{
			DirectionalLight->AddActorLocalRotation(FRotator(0, -RotationDegree, 0));
		}
		bIsNight = !bIsNight;
	}
	if (!DirectionalLight)
	{
		UE_LOG(LogTemp, Warning, TEXT("No DirectionalLight found."));
	}
}

