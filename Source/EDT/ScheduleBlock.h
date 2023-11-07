// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleBlock.generated.h"

USTRUCT(BlueprintType)
struct EDT_API FScheduleBlockData : public FTableRowBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ImpactOnMentalHealth;

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