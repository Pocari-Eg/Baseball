// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../BaseballProject.h"
#include "Engine/GameInstance.h"
#include "Ball.h"
#include "BBGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BASEBALLPROJECT_API UBBGameInstance : public UGameInstance
{
	GENERATED_BODY()
//var	
private:
	ABall* MainBall;
//func
public:
	void SetBall(ABall* NewBall);

	UFUNCTION(BluePrintCallable)
	void SetBallValue(float X,float Y,float Z);
	UFUNCTION(BluePrintCallable)
	void Shoot_Impulse();
	UFUNCTION(BluePrintCallable)
	void Shoot_AddForce();
	UFUNCTION(BluePrintCallable)
	void InitBall();
	
};
