// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibraries/GameplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameModes/GameplayGameMode.h"
#include "PlayerControllers/BasePlayerController.h"
#include "CompassMapProject/CompassMapProjectCharacter.h"
#include "System/CMGameInstance.h"
#include "Managers/MapManager.h"

UGameplayConstants* UGameplayFunctionLibrary::GetGameplayConstants(UObject* WorldContext)
{
	UCMGameInstance* GInstance = Cast<UCMGameInstance>(UGameplayStatics::GetGameInstance(WorldContext));
	if (GInstance)
	{
		return GInstance->GameplayConstants;
	}

	return nullptr;
}

ACompassMapProjectCharacter* UGameplayFunctionLibrary::GetPlayerCharacter(UObject* WorldContext)
{
	AGameplayGameMode* GameplayGameMode = Cast<AGameplayGameMode>(UGameplayStatics::GetGameMode(WorldContext));
	if (GameplayGameMode && GameplayGameMode->PlayerRef)
	{
		return GameplayGameMode->PlayerRef->CharRef;
	}

	return nullptr;
}

AMapManager* UGameplayFunctionLibrary::GetMapManagerActor(UObject* WorldContext)
{
	AMapManager* MapManagerActor = {};
	AGameplayGameMode* GM = Cast<AGameplayGameMode>(UGameplayStatics::GetGameMode(WorldContext));
	if (GM)
	{
		MapManagerActor = GM->MapManager;
	}

	return MapManagerActor;
}

void UGameplayFunctionLibrary::AddPOI(FName NewPOI, UObject* WorldContext)
{
	if (AMapManager* MapManager = GetMapManagerActor(WorldContext))
	{
		MapManager->AddToDiscoveredPOIs(NewPOI);
	}
}

void UGameplayFunctionLibrary::RemovePOI(FName NewPOI, UObject* WorldContext)
{
	if (AMapManager* MapManager = GetMapManagerActor(WorldContext))
	{
		MapManager->RemoveFromDiscoveredPOIs(NewPOI);
	}
}

bool UGameplayFunctionLibrary::IsPOIDiscovered(FName POI, UObject* WorldContext)
{
	if (AMapManager* MapManager = GetMapManagerActor(WorldContext))
	{
		return MapManager->GetDiscoveredPOIs().Contains(POI);
	}

	return false;
}

