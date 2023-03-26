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

#pragma region Variables

protected:
	UPROPERTY(EditDefaultsOnly,Category = "SpikesSettigns")
	TSubclassOf<AShootSpherePlayerCharacter_Base> CharacterToDamage;
	UPROPERTY(EditDefaultsOnly,Category = "SpikesSettings", meta=(ClampMin = 0))
	float DamageToCause{10};
	UPROPERTY(BlueprintReadOnly)
	bool isSpikesReady{false};

#pragma endregion

#pragma region Actions

public:
	ADamagingSpikesClass();
	UFUNCTION()
	void ApplyDamageByOverlap(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


#pragma endregion 
	
};
