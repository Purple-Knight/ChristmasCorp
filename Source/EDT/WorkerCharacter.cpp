// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerCharacter.h"
#include "ScheduleBlock.h"

// Sets default values
AWorkerCharacter::AWorkerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWorkerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Emerald, FString::Format(TEXT("BlockRunning : {0}"), { IsBlockRunning }));


	if (IsTimelineStarted && !IsBlockRunning)
	{
		RunBlock(Blocks[CurrentBlockIndex]);
		IsBlockRunning = true;
		//RunTimerOfCurrentBlock();
	}

	if (IsTimerRunning && IsBlockRunning)
	{
		Timer += DeltaTime;
		CurrentBlockCompletion = FMath::GetMappedRangeValueClamped<float>(UE::Math::TVector2<float>(0.0f, Blocks[CurrentBlockIndex]->BlockDuration), UE::Math::TVector2<float>(0.0f, 1.0f), Timer);
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, DeltaTime, FColor::Emerald, FString::Format(TEXT("CurrentBlockCompletion : {0}"), { CurrentBlockCompletion }));
	}
}

// Called when the game starts or when spawned
void AWorkerCharacter::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < Blocks.Num(); i++)
	{
		Blocks[i]->Index = i;
	}
}

void AWorkerCharacter::BlockActionEnded()
{
	IsBlockRunning = false;
	Timer = 0.0f;

	CurrentBlockIndex++;
	if (CurrentBlockIndex >= Blocks.Num())
	{
		CurrentBlockIndex = 0;
	}
}

void AWorkerCharacter::RunTimerOfCurrentBlock()
{
	IsTimerRunning = true;
}

void AWorkerCharacter::StartTimeline()
{
	IsTimelineStarted = true;
}

void AWorkerCharacter::StopTimeline()
{
	IsTimelineStarted = false;
	IsTimerRunning = false;
}

void AWorkerCharacter::ResumeTimeline()
{
	IsTimelineStarted = true;
	IsTimerRunning = true;
}


void AWorkerCharacter::ResetTimeline()
{
	IsTimelineStarted = false;
	IsBlockRunning = false;
	IsTimerRunning = false;
	Timer = 0.0f;
	CurrentBlockIndex = 0;
}

