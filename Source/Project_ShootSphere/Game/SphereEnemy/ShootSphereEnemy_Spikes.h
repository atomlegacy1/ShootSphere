// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Character.h"
#include "ShootSphereEnemy_Spikes.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSphereEnemy_Spikes : public AShootSphereEnemy_Character
{
	GENERATED_BODY()

#pragma region Components

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* LeftSpikesMesh;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* RightSpikesMesh;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* PlayerDamageCollision;

#pragma endregion

#pragma region Actions
	
public:
	AShootSphereEnemy_Spikes();
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	UFUNCTION()
	void ApplyDamageToActor();
	UFUNCTION()
	void SpikesRotation();
	UFUNCTION()
	void StartSpikesRotation();

#pragma endregion

#pragma region Variables

private:
	UPROPERTY()
	FTimerHandle THSpikesRotation;
	UPROPERTY()
	FRotator NewSpikesRotation{};

	UPROPERTY()
	FTimerHandle THDamageCharacter;
	UPROPERTY()
	class AActor* CharacterToDamage;

protected:
	UPROPERTY(EditDefaultsOnly,Category = "SphereSettings",meta = (ClampMin = 0))
	float SpikesRotationRate{2.0f};
	UPROPERTY(EditDefaultsOnly,Category="SphereSettings",meta = (ClampMin = 0))
	float DamageWhenOverlap{2.0f};

#pragma endregion 
};
