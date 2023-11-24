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

	if (IsTimelineStarted && !IsBlockRunning)
	{
		IsBlockRunning = true;
		RunBlock(Blocks[CurrentBlockIndex]);
		//RunTimerOfCurrentBlock();
	}

	if (IsTimerRunning)
	{
		Timer += DeltaTime;
		if (Timer >= Blocks[CurrentBlockIndex]->BlockDuration)
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Emerald, FString::Format(TEXT("Block {0}, end !"), {Blocks[CurrentBlockIndex]->DisplayName}));
			//BlockActionEnded();
		}
	}
}

// Called when the game starts or when spawned
void AWorkerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Init Actions
	//for (const TObjectPtr<UScheduleBlock>& Block : Blocks)
	//{
	//	Actions.Add(NewObject<UScheduleAction>(Block, Block->Action));
	//}
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

