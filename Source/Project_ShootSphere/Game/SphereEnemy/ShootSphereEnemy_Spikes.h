// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"
#include "ShootSphereEnemy_Spikes.generated.h"


UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSphereEnemy_Spikes : public AShootSphereEnemy_Base
{
	GENERATED_BODY()

#pragma region Components

protected:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* LeftSpikesMesh;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* RightSpikesMesh;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* PlayerFinderColl;

#pragma endregion

#pragma region Actions
	
public:
	AShootSphereEnemy_Spikes();
	
protected:
	virtual void BeginPlay() override;

private:
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

protected:
	UPROPERTY(EditDefaultsOnly,Category = "SphereSettings",meta = (ClampMin = 0))
	float SpikesRotationRate{2.0f};

#pragma endregion 
};
