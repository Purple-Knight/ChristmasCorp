// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "WorkerComponent.generated.h"

class UScheduleBlock;
class UScheduleAction;

UCLASS(BlueprintType, Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class EDT_API UWorkerComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentBlockIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UScheduleBlock>> Blocks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UScheduleAction>> Actions;

	UWorkerComponent();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
