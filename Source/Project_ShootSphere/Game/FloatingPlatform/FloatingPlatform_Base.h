// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform_Base.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AFloatingPlatform_Base : public AActor
{
	GENERATED_BODY()

#pragma region Default
public:	
	AFloatingPlatform_Base();

#pragma endregion

#pragma region Components

	UPROPERTY()
	USceneComponent* PlatformRoot;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* PlatformMesh;

#pragma endregion 

};
