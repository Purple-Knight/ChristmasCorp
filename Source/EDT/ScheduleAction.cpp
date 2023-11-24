// Fill out your copyright notice in the Description page of Project Settings.


#include "ScheduleAction.h"

void UScheduleActionWalkToA::DoAction(TObjectPtr<UWorkerComponent> Actor) 
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Walk to A"));

}

void UScheduleActionWalkToB::DoAction(TObjectPtr<UWorkerComponent> Actor) 
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Walk to B"));

}

void UScheduleActionWork::DoAction(TObjectPtr<UWorkerComponent> Actor) 
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Work"));
}
