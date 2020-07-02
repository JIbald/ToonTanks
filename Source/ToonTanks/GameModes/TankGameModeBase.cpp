// Johannes Ibald 2020


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	//get references and game win/lose conditions.
	//call HandleGameStart to initialise the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//check what type of actor died, if turret, tally, if player -> go to lose condition
}

void ATankGameModeBase::HandleGameStart()
{
	//initialise the start countdown, turret activation, pawn check etc.
	//call blueprint version GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	//see if the player has destroyed all the turrets, show win result.
	//else if turret destroyed player, show lose result.
	//call blueprint version GameOver();
}
