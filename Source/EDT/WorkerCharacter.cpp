// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerCharacter.h"
#include "ScheduleBlock.h"
#include "AIController.h"
#include "Blueprint/AIAsyncTaskBlueprintProxy.h"

// Sets default values
AWorkerCharacter::AWorkerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWorkerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bTimelineStarted && !bBlockRunning)
	{
		RunBlock(*Blocks[CurrentBlockIndex]);
		bBlockRunning = true;
	}

	if (bTimerRunning && bBlockRunning)
	{
		Timer += DeltaTime;
		CurrentBlockCompletion = FMath::GetMappedRangeValueClamped<float>(UE::Math::TVector2<float>(0.0f, Blocks[CurrentBlockIndex]->BlockDuration), UE::Math::TVector2<float>(0.0f, 1.0f), Timer);

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Emerald, FString::Format(TEXT("CurrentBlockCompletion : {0}"), { CurrentBlockCompletion }));

		if (Timer >= Blocks[CurrentBlockIndex]->BlockDuration)
		{
			BlockActionEnded();
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Magenta, TEXT("CurrentBlockEnded"));
		}
	}
}

// Called when the game starts or when spawned
void AWorkerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!AIController)
	{
		AIController = GetController<AAIController>();
		AIController->ReceiveMoveCompleted.AddDynamic(this, &AWorkerCharacter::OnMoveCompleted);
	}
}

void AWorkerCharacter::BlockActionEnded()
{
	bInteract = false;
	bBlockRunning = false;
	bTimerRunning = false;
	Timer = 0.0f;

	CurrentBlockIndex++;
	if (CurrentBlockIndex >= Blocks.Num())
	{
		CurrentBlockIndex = 0;
	}
}

void AWorkerCharacter::RunTimerOfCurrentBlock()
{
	bInteract = true;
	bTimerRunning = true;
}

void AWorkerCharacter::StartTimeline()
{
	bTimelineStarted = true;
}

void AWorkerCharacter::StopTimeline()
{
	bTimelineStarted = false;
	bTimerRunning = false;
}

void AWorkerCharacter::ResumeTimeline()
{
	bTimelineStarted = true;
	bTimerRunning = true;
}

void AWorkerCharacter::ResetTimeline()
{
	bTimelineStarted = false;
	bBlockRunning = false;
	bTimerRunning = false;
	Timer = 0.0f;
	CurrentBlockIndex = 0;
}

void AWorkerCharacter::RunBlock(const UScheduleBlock& Block)
{
	if (!AIController)
	{
		AIController = GetController<AAIController>();
		AIController->ReceiveMoveCompleted.AddDynamic(this, &AWorkerCharacter::OnMoveCompleted);
	}

	FAIMoveRequest MoveReq;
	MoveReq.SetUsePathfinding(true);
	MoveReq.SetAcceptanceRadius(AcceptanceRadius);
	MoveReq.SetReachTestIncludesAgentRadius(bStopOnOverlap);
	MoveReq.SetGoalLocation(Block.LocationOfTask);
	MoveReq.SetNavigationFilter(AIController->GetDefaultNavigationFilterClass());

	FPathFollowingRequestResult ResultData = AIController->MoveTo(MoveReq);
	switch (ResultData.Code)
	{
	case EPathFollowingRequestResult::RequestSuccessful:
		UE_LOG(LogTemp, Error, TEXT("Worker Move To Goal"));
		break;

	case EPathFollowingRequestResult::AlreadyAtGoal:
		RunTimerOfCurrentBlock();
		UE_LOG(LogTemp, Error, TEXT("Worker Already At Goal"));
		break;

	case EPathFollowingRequestResult::Failed:
		UE_LOG(LogTemp, Error, TEXT("Worker fail on RunBlock"));
		break;

	default:
		UE_LOG(LogTemp, Error, TEXT("Worker fail on RunBlock"));
		break;
	}
}

void AWorkerCharacter::OnMoveCompleted(FAIRequestID ID, EPathFollowingResult::Type Type)
{
	RunTimerOfCurrentBlock();
	UE_LOG(LogTemp, Error, TEXT("Worker At Goal"));
}
