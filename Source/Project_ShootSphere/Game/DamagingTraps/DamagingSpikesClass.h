// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/DamagingTraps/DamagingTrapsBase.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "DamagingSpikesClass.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ADamagingSpikesClass : public ADamagingTrapsBase
{
	GENERATED_BODY()

#pragma region Actions
	
public:
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent,
		AController* EventInstigator, AActor* DamageCauser) override;

#pragma endregion

#pragma region Variables

protected:
	UPROPERTY(EditDefaultsOnly,Category = "SpikesSettings", meta=(ClampMin = 0))
	float DamageToCause{10};
	UPROPERTY(EditDefaultsOnly,Category = "SpikesSettings")
	TSubclassOf<AShootSpherePlayerCharacter_Base> PlayerCharacterToDamage;

#pragma endregion 
	
};
