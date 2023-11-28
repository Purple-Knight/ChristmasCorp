// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Navigation/PathFollowingComponent.h"
#include "WorkerCharacter.generated.h"

class UScheduleBlock;
class AAIController;
struct FAIRequestID;

UCLASS(BlueprintType, Blueprintable, ClassGroup = "AI Character")
class EDT_API AWorkerCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentBlockCompletion = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentBlockIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UScheduleBlock>> Blocks;

	AWorkerCharacter();

	virtual void Tick(float DeltaTime) override;

	//UFUNCTION(BlueprintImplementableEvent)
	//void RunBlock(const UScheduleBlock* Block);

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AcceptanceRadius = 25.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool bBlockRunning = false;
	bool bTimerRunning = false;
	bool bTimelineStarted = false;

	//IA / Move
	bool bStopOnOverlap = true;
	float Timer = 0.0f;
	TObjectPtr<AAIController> AIController;

	void RunBlock(const UScheduleBlock& Block);

	UFUNCTION()
	void OnMoveCompleted(FAIRequestID ID, EPathFollowingResult::Type Type);

};
