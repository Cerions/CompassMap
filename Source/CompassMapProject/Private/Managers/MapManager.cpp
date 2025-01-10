// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/MapManager.h"
#include "FunctionLibraries/GameplayFunctionLibrary.h"
#include "Structures/GameplayConstants.h"

// Sets default values
AMapManager::AMapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// trasformarlo in TMAP?
void AMapManager::GetAllPOI(TArray<FPOIConfigRow>& POIConfig)
{
	UGameplayConstants* GameplayConstants = UGameplayFunctionLibrary::GetGameplayConstants(this);

	if(GameplayConstants && GameplayConstants->POITable.LoadSynchronous())
	{
		TArray<FName> DiscoveredPOIIDs {};
		DiscoveredPOIs.GenerateKeyArray(DiscoveredPOIIDs);
		for (FName POI : DiscoveredPOIIDs)
		{
			FPOIConfigRow* Row = GameplayConstants->POITable.LoadSynchronous()->FindRow<FPOIConfigRow>(POI, TEXT(""));

			if (Row)
			{
				POIConfig.Add(*Row);
			}
		}

		// Dynamic markers
		for (FMarkerPosition Marker : DynamicMarkers)
		{
			FPOIConfigRow* Row = GameplayConstants->POITable.LoadSynchronous()->FindRow<FPOIConfigRow>(Marker.Type, TEXT(""));
			if (Row)
			{
				FPOIConfigRow NewRow = *Row;

				NewRow.Location = Marker.Location;
				NewRow.Id = Marker.ObjectID;
				NewRow.AreaSize = Marker.AreaSize;
				POIConfig.Add(NewRow);
			}
		}
	}
}

FVector AMapManager::GetPOILocation(FName POIID)
{
	if (DiscoveredPOIs.Contains(POIID))
	{
		return DiscoveredPOIs[POIID];
	}

	return FVector();
}

