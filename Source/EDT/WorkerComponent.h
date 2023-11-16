// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleBlock.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "WorkerComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EDT_API UWorkerComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UScheduleBlock>> Blocks;

	// Sets default values for this actor's properties
	UWorkerComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
