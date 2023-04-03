// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/Collectibles/CollectibleBase.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "SpecialStageCoin.generated.h"


UCLASS()
class PROJECT_SHOOTSPHERE_API ASpecialStageCoin : public ACollectibleBase
{
	GENERATED_BODY()

#pragma region Default
protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Actions

public:
	UFUNCTION()
	void GiveSpecialCoinByOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
#pragma endregion 
};
