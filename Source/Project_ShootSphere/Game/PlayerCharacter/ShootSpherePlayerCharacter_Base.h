	// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerWeapon/SpherePlayerWeapon.h"
#include "Project_ShootSphere/Game/PlayerCharacter/PlayerWeapon/WeaponProjectile/SpherePlayerWeapon_Projectile.h"
#include "ShootSpherePlayerCharacter_Base.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSpherePlayerCharacter_Base : public ACharacter
{
	GENERATED_BODY()

#pragma region Default
	
public:
	AShootSpherePlayerCharacter_Base();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Components
	
protected:
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* WeaponDirection;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* WeaponBattery;

#pragma endregion

#pragma region Action
	
public:
	UFUNCTION()
	void CharacterMoveForward(float Value);
	UFUNCTION()
	void CharacterMoveRight(float Value);
	UFUNCTION()
	void CharacterJump();

	UFUNCTION()
	void CharacterDash();
	
	UFUNCTION()
	void CharacterWeaponReload();
	UFUNCTION()
	void CharacterWeaponShoot();
	
	UFUNCTION()
	void CharacterTakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType,
		class AController* InstigatedBy, AActor* DamageCauser);

private:
	UFUNCTION()
	void SpawnWeapon();
	UFUNCTION()
	void HideBatteryAfterReload();

	UFUNCTION()
	void DashStop();
	UFUNCTION()
	void DashReload();
	UFUNCTION()
	void DashReloadCheck();

#pragma endregion

#pragma region Variables

protected:
	UPROPERTY(EditDefaultsOnly,Category = "Character weapon settings")
	TSubclassOf<ASpherePlayerWeapon> WeaponToSpawn;
	UPROPERTY(EditDefaultsOnly,Category = "Character weapon settings")
	TSubclassOf<ASpherePlayerWeapon_Projectile> WeaponProjectile;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category= "Character weapon settings")
	int32 WeaponCurrentAmmo{0};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category= "Character weapon settings")
	int32 WeaponMaxAmmo{30};

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Character settings")
	int32 CurrentDashAmount{0};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	int32 MaxDashAmount{2};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	float DashRange{2500};
	UPROPERTY();
	bool isDashReady{true};

	UPROPERTY(BlueprintReadOnly,Category = "Character settings")
	float CharacterCurrentHealth{0};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings",meta = (ClampMin = 0))
	float CharacterMaxHealth{100};
	UPROPERTY(BlueprintReadOnly)
	bool isDead{false};

	UPROPERTY(EditDefaultsOnly,Category = "Character weapon settings")
	UAnimMontage* WeaponReloadMontage;
public:
	UPROPERTY()
	int32 SpecialCoinsCollected{0};

private:
	UPROPERTY()
	bool isReloading;

#pragma endregion
};
