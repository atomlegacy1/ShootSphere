// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CollectibleBase.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ACollectibleBase : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:
	ACollectibleBase();

#pragma endregion

#pragma region Components
	
protected:
	UPROPERTY()
	USceneComponent* RootComp;
	UPROPERTY(EditInstanceOnly)
	UStaticMeshComponent* StaticMeshComp;
	UPROPERTY(EditInstanceOnly)
	USphereComponent* CollisionComp;

#pragma endregion
};
