// Fill out your copyright notice in the Description page of Project Settings.


#include "BBGameInstance.h"

void UBBGameInstance::SetBall(ABall* NewBall)
{
	MainBall = NewBall;
}

void UBBGameInstance::SetBallValue(float X, float Y, float Z)
{

	MainBall->SetAddForcePower(X, Y, Z);
}

void UBBGameInstance::Shoot_Impulse()
{
	MainBall->Shoot_Impulse();

}

void UBBGameInstance::Shoot_AddForce()
{
	MainBall->Shoot_AddForce();
}

void UBBGameInstance::InitBall()
{
	MainBall->InitBall();
}
