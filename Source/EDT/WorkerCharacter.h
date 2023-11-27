// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WorkerCharacter.generated.h"

class UScheduleBlock;
class UScheduleAction;

UCLASS(BlueprintType, Blueprintable, ClassGroup = "AI Controller")
class EDT_API AWorkerCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentBlockIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UScheduleBlock>> Blocks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<UScheduleAction>> Actions;

	AWorkerCharacter();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void RunBlock(const UScheduleBlock* Block);

	UFUNCTION(BlueprintCallable)
	void BlockActionEnded();

	UFUNCTION(BlueprintCallable)
	void RunTimerOfCurrentBlock();

	UFUNCTION(BlueprintCallable)
	void StartTimeline();

	UFUNCTION(BlueprintCallable)
	void StopTimeline();

	UFUNCTION(BlueprintCallable)
	void ResumeTimeline();

	UFUNCTION(BlueprintCallable)
	void ResetTimeline();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool IsBlockRunning = false;
	bool IsTimerRunning = false;
	bool IsTimelineStarted = false;

	float Timer = 0.0f;


};
