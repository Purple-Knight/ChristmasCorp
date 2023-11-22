// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScheduleAction.generated.h"

class UWorkerComponent;

UCLASS(Blueprintable)
class EDT_API UScheduleAction : public UObject
{
	GENERATED_BODY()

public:
	UScheduleAction() = default;

	virtual void DoAction(TObjectPtr<UWorkerComponent> Actor) PURE_VIRTUAL(UWorkerComponent::DoAction);
};


UCLASS(meta = (DisplayName = "Action Walk To A"))
class UScheduleActionWalkToA : public UScheduleAction
{
	GENERATED_BODY()

public:
	virtual void DoAction(TObjectPtr<UWorkerComponent> Actor) override;
	
};

UCLASS(meta = (DisplayName = "Action Walk To B"))
class UScheduleActionWalkToB : public UScheduleAction
{
	GENERATED_BODY()

public:
	virtual void DoAction(TObjectPtr<UWorkerComponent>  Actor) override;

};

UCLASS(meta = (DisplayName = "Action Work"))
class UScheduleActionWork : public UScheduleAction
{
	GENERATED_BODY()

public:
	virtual void DoAction(TObjectPtr<UWorkerComponent>  Actor) override;

};
