// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetStaticActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class COMPASSMAPPROJECT_API ATargetStaticActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetStaticActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* StaticMeshComp {};

public:

	UPROPERTY(EditAnywhere)
	FName POIID = "";

};
