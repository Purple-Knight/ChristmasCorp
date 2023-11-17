// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerComponent.h"
#include "ScheduleBlock.h"

// Sets default values
UWorkerComponent::UWorkerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UWorkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//Actions[CurrentBlockIndex]->DoAction(this);
}

// Called when the game starts or when spawned
void UWorkerComponent::BeginPlay()
{
	Super::BeginPlay();

	//Init Actions
	for (const TObjectPtr<UScheduleBlock> Block : Blocks)
	{
		Actions.Add(NewObject<UScheduleAction>(Block->Action));
	}

	//for (const TObjectPtr<UScheduleAction> Action : Actions)
	//{
	//	if (GEngine)
	//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Magenta, (TEXT("Action")));
	//}
}

