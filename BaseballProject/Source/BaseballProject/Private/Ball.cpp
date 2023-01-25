// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "BBGameInstance.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = Collision;

	Mesh->SetupAttachment(RootComponent);
	InitCollisionComponent();
	InitMeshComponent();

	Power = FVector(0.0f, 0.0f, 0.0f);

}

void ABall::InitCollisionComponent()
{
	//setCollision
	Collision->SetSphereRadius(23.3f);
	Collision->SetCollisionProfileName("BlockAll");
	Collision->SetGenerateOverlapEvents(true);
	Collision->SetNotifyRigidBodyCollision(true);
	//setPhysics
	Collision->SetSimulatePhysics(true);
	Collision->SetMassOverrideInKg(NAME_None, 0.145f, true);
	Collision->SetLinearDamping(1.0f);
	Collision->SetAngularDamping(1.0f);
	Collision->SetEnableGravity(false);
}

void ABall::InitMeshComponent()
{
	//setTransform
	Mesh->SetWorldScale3D(FVector(54.0f, 54.0f, 54.0f));
	
	//setCollision
	Mesh->SetGenerateOverlapEvents(false);
	Mesh->SetCollisionProfileName("NoCollision");
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	auto Instance = Cast<UBBGameInstance>(GetGameInstance());
	if (Instance != nullptr)Instance->SetBall(this);


	InitPos = GetActorLocation();
	InitRot = GetActorRotation();
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::SetAddForcePower(float X, float Y, float Z)
{
	Power.X = X;
	Power.Y = Y;
	Power.Z = Z;
}

void ABall::Shoot_Impulse()
{
	Collision->SetSimulatePhysics(true);
	Collision->SetEnableGravity(true);
	Collision->AddImpulse(Power, NAME_None, false);
	BBLOG(Warning, TEXT("Shoot_Impulse"));
}

void ABall::Shoot_AddForce()
{
	Collision->SetSimulatePhysics(true);
	Collision->SetEnableGravity(true);
	Collision->AddForce(Power*100.0f);
	BBLOG(Warning, TEXT("Shoot_AddForce"));
}

void ABall::InitBall()
{
	Collision->SetSimulatePhysics(false);
	SetActorLocation(InitPos);
	SetActorRotation(InitRot);
	Collision->SetEnableGravity(false);
}

