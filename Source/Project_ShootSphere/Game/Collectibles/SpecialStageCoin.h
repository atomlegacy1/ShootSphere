// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/Collectibles/CollectibleBase.h"
#include "SpecialStageCoin.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASpecialStageCoin : public ACollectibleBase
{
	GENERATED_BODY()

#pragma region Default
public:
	ASpecialStageCoin();

#pragma endregion

#pragma region Actions

public:
	UFUNCTION()
	void GiveSpecialCoinByOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
#pragma endregion 
};
