// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/CMEventManager.h"

void UCMEventManager::InitManager(UCMGameInstance* InstanceOwner)
{
	if (InstanceOwner)
	{
		GInstanceRef = InstanceOwner;
	}
}

void UCMEventManager::OnCharacterRefSetEvent(ACompassMapProjectCharacter* PC)
{
	OnCharacterRefSet.Broadcast(PC);
}

void UCMEventManager::OnPOIsActivatedEvent()
{
	OnPOIsActivated.Broadcast();
}
