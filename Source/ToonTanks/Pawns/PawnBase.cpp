// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "ToonTanks/Actors/ProjectileBase.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	//update turretmesh to face towards the LookAtTarget passed in from the child class.
	//TurretMesh->SetWorldRotation() ... 

	FVector StartLocation = TurretMesh->GetComponentLocation();
	FRotator TurretRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation, FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z));

	//rotate turret
	TurretMesh->SetWorldRotation(TurretRotation);
}

void APawnBase::Fire()
{
	//get ProjectileSpawnPoint Location && Rotation -> Spawn Projectile Class at Location towards Rotation
	//fire
	if (ProjectileClass)
	{
		FVector SpawnLocation = ProjectileSpawnPoint->GetComponentLocation();
		FRotator SpawnRotation = ProjectileSpawnPoint->GetComponentRotation();
		AProjectileBase* TempProjectile = GetWorld()->SpawnActor<AProjectileBase>(ProjectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}
}

void APawnBase::HandleDestruction()
{
	//Universal functionality ---
	// Play death effects Particle, sound and camera shake.

	//... then do unique child overrides
	// -- PawnTurret - inform gamemode turret died -> then destroy() self

	//--- PawnTank - Inform GameMode Player dies -> Then Hide() all components && stop movement Input.
}
