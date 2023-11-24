// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleAction.h"
#include "ScheduleBlock.generated.h"

UCLASS(Blueprintable)
class EDT_API UScheduleBlock : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayName = TEXT("NotAName");

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FColor Color = FColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlockDuration = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Movable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UScheduleAction> Action;
};