	// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
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
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	USpringArmComponent* CharacterSpringArm;
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* CharacterCameraComponent;
	UPROPERTY(EditDefaultsOnly)
	UArrowComponent* WeaponDirection;

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
	void DashStop();
	UFUNCTION()
	void DashReload();
	UFUNCTION()
	void DashReloadCheck();
	
	UFUNCTION()
	void CharacterWeaponReload();
	UFUNCTION()
	void CharacterWeaponShoot();

	UFUNCTION()
	void SpawnWeapon();

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
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	int32 CurrentDashAmount{0};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	int32 MaxDashAmount{5};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	float DashRange{4000};

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	int32 CharacterCurrentHealth{0};
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Character settings")
	int32 CharacterMaxHealth{100};

#pragma endregion
};
