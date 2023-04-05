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
	UPROPERTY(EditDefaultsOnly,Category = "SpikesSettings", meta=(ClampMin = 0))
	float SpikesMovingRate;
	
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MovingSpikesMesh;
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpikesOutCollision;
	
	UPROPERTY()
	class AActor* CharacterToDamage;
	UPROPERTY()
	FTimerHandle THDamageApply;
	
	UPROPERTY()
	FTimerHandle THSpikesMove;
	UPROPERTY()
	FVector SpikesOutLocation;
	UPROPERTY()
	FVector SpikesStartLocation;
	UPROPERTY()
	FVector SpikesMovingVector;
	UPROPERTY()
	float RangeToOut;
	UPROPERTY()
	bool isCharacterOverlap{false};

#pragma endregion

#pragma region Actions

public:
	ADamagingSpikesClass();
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
	void StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	
	UFUNCTION()
	void MoveSpikesUp(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void MoveSpikesDown(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void ApplyDamageToActor();

	UFUNCTION()
	void MoveSpikes();

#pragma endregion 
	
};
