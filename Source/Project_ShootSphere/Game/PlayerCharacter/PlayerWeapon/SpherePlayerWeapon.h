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

#pragma endregion

#pragma region Components
	
protected:
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* WeaponSceneRoot;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponBase;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponLanterns;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponRightLight;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponLeftLight;
public:
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* WeaponDirection;

#pragma endregion
	
};
