// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleBlock.generated.h"

UENUM(BlueprintType)
enum class EScheduleBlock : uint8
{
	EAT,
	SLEEP,
	PET_THE_CAT,
	PLAY,
	SLEEP_BUT_BETTER,
	DIE
};

USTRUCT(BlueprintType)
struct EDT_API FScheduleBlockData : public FTableRowBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Movable;
};

UCLASS(Blueprintable)
class EDT_API AScheduleBlock : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FScheduleBlockData BlockData;

	// Sets default values for this actor's properties
	AScheduleBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetBlockData();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};