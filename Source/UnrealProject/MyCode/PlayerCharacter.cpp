// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "APickUp.h"
#include "UItem.h"
#include "UInventoryComponent.h"
#include "UI/InventoryWidget.h"
#include "UObject/ObjectRename.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));

	PlayerInventory->InventorySlots.SetNumZeroed(InventorySize);

	PlayerInventory->ItemCap = this->ItemCap;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerCharacter::LookRight);

	PlayerInputComponent->BindAction("Interact", IE_Pressed,this,  &APlayerCharacter::Interact);
}

void APlayerCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void APlayerCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void APlayerCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void APlayerCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}

void APlayerCharacter::Interact()
{
	TArray<AActor*> OverlappingActors;

	GetOverlappingActors(OverlappingActors, AAPickUp::StaticClass());

	for (AActor* OverlappingActor : OverlappingActors)
	{
		AAPickUp* PickedUpActor = Cast<AAPickUp>(OverlappingActor);
		
			UItem* NewItem = NewObject<UItem>(this, UItem::StaticClass());

			FItemStruct ItemStruct = PickedUpActor->ItemDataAsset->GetItemInfo();

			NewItem->ItemName = ItemStruct.ItemName;
			NewItem->ItemDescription = ItemStruct.ItemDescription;
			NewItem->ItemId = ItemStruct.ItemId;
			NewItem->ItemType = ItemStruct.ItemType;
			NewItem->ItemImage = ItemStruct.ItemIcon;

			UE_LOG(LogTemp, Warning, TEXT("Working PickUp. %s Also %s"), *NewItem->ItemName, *NewItem->ItemDescription);

		if(PlayerInventory)
		{
			if(PlayerInventory->AddItem(NewItem, 1))
			{
				if(InventoryWidget)
				{
					InventoryWidget.GetDefaultObject()->AddItemToInventory(
						NewItem,
						PlayerInventory->GetSlotNum(NewItem)
					);
				}
				PickedUpActor->Destroy();
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("PlayerInventory is nullptr"));
		}
	}

}




