// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "ScheduleBlock.h"
#include "GameSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game, defaultconfig, meta = (ClassName = "Game Settings"))
class EDT_API UGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "Schedule")
	TSoftObjectPtr<UDataTable> BlockList = nullptr;
};
