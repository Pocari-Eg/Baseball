// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../BaseballProject.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Ball.generated.h"

UCLASS()
class BASEBALLPROJECT_API ABall : public AActor
{
	GENERATED_BODY()
//Var

//component
private:
	UPROPERTY(EditAnywhere,blueprintreadWrite, Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, blueprintreadWrite, Meta = (AllowPrivateAccess = true))
	USphereComponent* Collision;
//value
private:

	UPROPERTY(VisibleAnyWhere, Meta = (AllowPrivateAccess = true), Category = "POWER")
	FVector Power;
	FVector InitPos;
	FRotator InitRot;
public:	
	// Sets default values for this actor's properties
	ABall();
private:
	void InitCollisionComponent();
	void InitMeshComponent();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetAddForcePower(float X, float Y, float Z);
	void Shoot_Impulse();
	void Shoot_AddForce();
	void InitBall();
};
