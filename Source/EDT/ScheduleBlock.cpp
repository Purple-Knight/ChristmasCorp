// Fill out your copyright notice in the Description page of Project Settings.


#include "ScheduleBlock.h"
#include "GameSettings.h"
#include "Logging/StructuredLog.h"

// Sets default values
AScheduleBlock::AScheduleBlock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetBlockData();
}

// Called when the game starts or when spawned
void AScheduleBlock::BeginPlay()
{
	Super::BeginPlay();

}

void AScheduleBlock::GetBlockData()
{

	UE_LOGFMT(LogTemp, Log, "Get Block Data");
	const UGameSettings* GameSettings = GetDefault<UGameSettings>();
	check(GameSettings);

	UDataTable* BlockListInstance = GameSettings->BlockList.LoadSynchronous();

	if (BlockListInstance != nullptr)
	{
		BlockData.DisplayName = BlockListInstance->FindRow<FScheduleBlockData>(TEXT("Eat"), TEXT("Find data"))->DisplayName;
		BlockData.Movable = BlockListInstance->FindRow<FScheduleBlockData>(TEXT("Eat"), TEXT("Find data"))->Movable;
		UE_LOGFMT(LogTemp, Log, "Block data : DisplayName : {0} Movable : {1}", BlockData.DisplayName, BlockData.Movable);
	}
}

// Called every frame
void AScheduleBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
