// Johannes Ibald 2020


#include "PawnTurret.h"
#include "PawnTank.h"
#include "Kismet/GameplayStatics.h"

//constructor
APawnTurret::APawnTurret()
{
	
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true, false); //FireRate how often timer gets called

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}

	RotateTurret(PlayerPawn->GetActorLocation());
}

void APawnTurret::CheckFireCondition()
{
	//if player == null || is dead then stop firing
	if (!PlayerPawn)
	{
		return;
	}
	// if player is in range then fire
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		Fire();
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	//check if we have valid reference to player
	if (!PlayerPawn)
	{
		return 0.f;
	}

	float Distance = (PlayerPawn->GetActorLocation() - GetActorLocation()).Size();
	return Distance;
}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
