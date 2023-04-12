// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "ShootSphereEnemy_Character.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSphereEnemy_Character : public ACharacter
{
	GENERATED_BODY()
	
#pragma region Actions 
public:
	AShootSphereEnemy_Character();

	UFUNCTION()
	void GetScoreByOverlapAndDestroy(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

#pragma endregion
	
#pragma region Components
protected:
	UPROPERTY(EditInstanceOnly)
	USphereComponent* PlayerFinderCollision;

#pragma endregion

#pragma region Variables
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "SphereSettings")
	int32 SphereScore;

#pragma endregion 
	
};
