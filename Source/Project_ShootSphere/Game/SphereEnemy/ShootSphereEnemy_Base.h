// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "ShootSphereEnemy_Base.generated.h"

UCLASS(HideCategories = ("Rendering","Replication","Collision","Advanced","HLOD","Physics",
"Networking","WorldPartition","Input","Actor","Cooking","DataLayers"))
class PROJECT_SHOOTSPHERE_API AShootSphereEnemy_Base : public AActor
{
	GENERATED_BODY()

#pragma region Default
	
public:	
	AShootSphereEnemy_Base();

protected:
	virtual void BeginPlay() override;

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

#pragma region Actions
public:
	UFUNCTION()
	void GetScoreByOverlapAndDestroy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
#pragma endregion

#pragma region Variables
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "SphereSettings")
	int32 SphereScore;

#pragma endregion 
};
