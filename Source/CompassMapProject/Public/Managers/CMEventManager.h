// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CMEventManager.generated.h"

class UCMGameInstance;
class ACompassMapProjectCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterRefSet, ACompassMapProjectCharacter*, PC);

/**
 * 
 */
UCLASS()
class COMPASSMAPPROJECT_API UCMEventManager : public UObject
{
	GENERATED_BODY()
	
public:

	UFUNCTION()
	void InitManager(UCMGameInstance* InstanceOwner);


	void OnCharacterRefSetEvent(ACompassMapProjectCharacter* PC);
	FOnCharacterRefSet OnCharacterRefSet;

protected:

	UPROPERTY()
	UCMGameInstance* GInstanceRef {};
};
