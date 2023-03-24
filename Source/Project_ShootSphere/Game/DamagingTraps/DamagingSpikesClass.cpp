// AtomLegacy1 property


#include "Project_ShootSphere/Game/DamagingTraps/DamagingSpikesClass.h"
#include "Kismet/GameplayStatics.h"

float ADamagingSpikesClass::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
	AController* EventInstigator, AActor* DamageCauser)
{
	
	UGameplayStatics::ApplyDamage(PlayerCharacterToDamage.GetDefaultObject(),
		DamageToCause,EventInstigator,this,UDamageType::StaticClass());
	return DamageToCause;
}
