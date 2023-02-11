// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "SpherePlayerWeapon.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASpherePlayerWeapon : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	ASpherePlayerWeapon();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Components

	UPROPERTY(EditDefaultsOnly)
	USceneComponent* WeaponSceneRoot;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponBase;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponLights;
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* WeaponDirection;

#pragma endregion
	
};
