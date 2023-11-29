// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTags.h"
#include "ScheduleBlock.generated.h"

UCLASS(Blueprintable)
class EDT_API UScheduleBlock : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	FString DisplayName = TEXT("NotAName");

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	FColor Color = FColor::White;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	bool Movable = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BlockDuration = 5.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag ActorToInteract;
};