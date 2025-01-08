// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameplayGameMode.generated.h"

class AHUDManager;
class ABasePlayerController;
class AMapManager;

/**
 * 
 */
UCLASS()
class COMPASSMAPPROJECT_API AGameplayGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AHUDManager> HUDManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AMapManager> MapManagerClass;

	UPROPERTY()
	AHUDManager* HUDManager {};

	UPROPERTY()
	AMapManager* MapManager {};

	UPROPERTY()
	ABasePlayerController* PlayerRef {};

private:

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	UFUNCTION()
	void SpawnManagers();
};
