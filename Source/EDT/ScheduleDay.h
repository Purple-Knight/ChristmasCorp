// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleBlock.h"
#include "ScheduleDay.generated.h"

USTRUCT(BlueprintType)
struct EDT_API FScheduleDay
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FScheduleBlock> blocks;

	FScheduleDay()
	{
		blocks = TArray<FScheduleBlock>();
	}
}; 
