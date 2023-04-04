// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "ShootSphereEnemy_Base.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSphereEnemy_Base : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	AShootSphereEnemy_Base();

#pragma endregion

#pragma region Components
	
protected:
	UPROPERTY(EditInstanceOnly)
	USceneComponent* SphereRootComponent;
	UPROPERTY(EditInstanceOnly)
	UStaticMeshComponent* SphereStaticMesh;
	UPROPERTY(EditInstanceOnly)
	USphereComponent* SphereCollisionComponent;

#pragma endregion
	
};
