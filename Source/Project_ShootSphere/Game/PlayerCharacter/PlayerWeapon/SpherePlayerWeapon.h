// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "WeaponProjectile/SpherePlayerWeapon_Projectile.h"
#include "SpherePlayerWeapon.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASpherePlayerWeapon : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	ASpherePlayerWeapon();

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Components
	
protected:
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* WeaponSceneRoot;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponBase;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponLights;
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* WeaponDirection;

#pragma endregion

#pragma region Variables
	
private:
	UPROPERTY(EditDefaultsOnly,Category = "WeaponSettings")
	int32 WeaponMaxAmmo{0};
	UPROPERTY()
	int32 WeaponCurrentAmmo;
	UPROPERTY(EditDefaultsOnly,Category = "WeaponSettings")
	TSubclassOf<ASpherePlayerWeapon_Projectile> ProjectileToSpawn;

#pragma endregion

#pragma region Actions
public:
	UFUNCTION()
	void WeaponReload();
	UFUNCTION()
	void WeaponShoot();

#pragma endregion
	
};
