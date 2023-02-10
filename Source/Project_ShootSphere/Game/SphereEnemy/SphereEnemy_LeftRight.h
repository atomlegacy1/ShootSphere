// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"
#include "SphereEnemy_LeftRight.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASphereEnemy_LeftRight : public AShootSphereEnemy_Base
{
	GENERATED_BODY()

#pragma region Action
public:
	UFUNCTION()
	void MoveSphereUpDown();
	UFUNCTION()
	void MoveSphereUp();
	UFUNCTION()
	void MoveSphereDown();
	UFUNCTION()
	void RandomDirectionSelect();

	ASphereEnemy_LeftRight();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Variables
private:
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	FVector MaxMovingDistanceUp{0,100,0};
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	FVector MaxMovingDistanceDown{0,100,0};
	UPROPERTY(EditDefaultsOnly,Category = "Sphere Settings")
	FVector SphereMovingRate{0,2,0};
	UPROPERTY()
	bool isMovingUp{false};

	UPROPERTY()
	FVector SphereSpawnLocation;

#pragma endregion
	
};
