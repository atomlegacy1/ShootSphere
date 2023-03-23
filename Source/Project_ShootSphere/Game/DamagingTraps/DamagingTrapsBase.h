// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "DamagingTrapsBase.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ADamagingTrapsBase : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:
	ADamagingTrapsBase();

#pragma endregion

#pragma region Components

protected:
	
	UPROPERTY()
	USceneComponent* RootComp;
	UPROPERTY()
	UStaticMeshComponent* MeshComp;
	UPROPERTY()
	UBoxComponent* CollisionComp;

#pragma endregion 
};
