// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleBlock.generated.h"

USTRUCT(BlueprintType)
struct EDT_API FScheduleBlock : public FTableRowBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int impactOnMentalHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool movable;

	//Constructor
	FScheduleBlock()
	{
		DisplayName = "Not A Name";
		impactOnMentalHealth = 0;
		movable = true;
	}
};
