// Johannes Ibald 2020


#include "PlayerControllerBase.h"

void APlayerControllerBase::SetPlayerEnabledState(bool SetPlayerEnable)
{
	if (SetPlayerEnable)
	{
		GetPawn()->EnableInput(this);
		APlayerController::bShowMouseCursor = true;
	}
	else
	{
		GetPawn()->DisableInput(this);
		APlayerController::bShowMouseCursor = false;
	}
}