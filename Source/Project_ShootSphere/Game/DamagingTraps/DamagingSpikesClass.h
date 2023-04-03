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
	UPROPERTY(EditDefaultsOnly,Category = "SpikesSettings", meta=(ClampMin = 0))
	float DamageToCause{10};
private:
	UPROPERTY()
	class AActor* CharacterToDamage;
	UPROPERTY()
	FTimerHandle THDamageApply;

#pragma endregion

#pragma region Actions

public:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
	UFUNCTION()
	void ApplyDamageToActor();

#pragma endregion 
	
};
