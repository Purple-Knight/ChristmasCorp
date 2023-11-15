// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScheduleBlock.h"
#include "Worker.generated.h"

UCLASS(Blueprintable)
class EDT_API AWorker : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UScheduleBlock>> Blocks;

	// Sets default values for this actor's properties
	AWorker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
