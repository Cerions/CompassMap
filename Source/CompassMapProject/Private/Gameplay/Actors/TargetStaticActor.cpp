// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Actors/TargetStaticActor.h"

ATargetStaticActor::ATargetStaticActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComp->SetGenerateOverlapEvents(false);
	StaticMeshComp->SetupAttachment(RootComponent);
}

void ATargetStaticActor::BeginPlay()
{
	Super::BeginPlay();
	
}

