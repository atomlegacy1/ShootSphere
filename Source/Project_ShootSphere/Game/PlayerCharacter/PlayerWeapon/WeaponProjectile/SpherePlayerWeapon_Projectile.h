// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SpherePlayerWeapon_Projectile.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASpherePlayerWeapon_Projectile : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	ASpherePlayerWeapon_Projectile();
protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Components
	
protected:
	UPROPERTY(EditDefaultsonly)
	USceneComponent* ProjectileRoot;
	UPROPERTY(EditDefaultsonly)
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* ProjectileCollision;
	UPROPERTY(EditDefaultsOnly)
	UProjectileMovementComponent* ProjectileMoveComponent;

#pragma endregion
};
