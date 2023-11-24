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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FString DisplayName = TEXT("NotAName");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FColor Color = FColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool Movable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BlockActionDuration = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UScheduleAction> Action;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Develloper", meta = (ClampMin = 0))
	int Index = 0;
};