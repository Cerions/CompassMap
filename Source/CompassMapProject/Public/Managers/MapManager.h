// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Structures/GameplayStructures.h"
#include "MapManager.generated.h"

UCLASS()
class COMPASSMAPPROJECT_API AMapManager : public AActor
{
	GENERATED_BODY()
	
public:	

	AMapManager();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void GetAllPOI(TArray<FPOIConfigRow>& POIConfig);

	UFUNCTION()
	TArray<FName> GetDiscoveredPOIs() { return DiscoveredPOIs; }

	UFUNCTION()
	TArray<FMarkerPosition> GetDynamicMarkers() { return DynamicMarkers; }

	UFUNCTION()
	void AddToDiscoveredPOIs(FName DiscoveredPOI) { DiscoveredPOIs.AddUnique(DiscoveredPOI); }

	UFUNCTION()
	void RemoveFromDiscoveredPOIs(FName RemovedPOI) { DiscoveredPOIs.Remove(RemovedPOI); }

private:

	UPROPERTY()
	TArray<FName> DiscoveredPOIs {};

	UPROPERTY()
	TArray<FMarkerPosition> DynamicMarkers {};
};
