// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "Project_ShootSphere/Game/SphereEnemy/ShootSphereEnemy_Base.h"
#include "SphereEnemy_UpDown.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API ASphereEnemy_UpDown : public AShootSphereEnemy_Base
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

	ASphereEnemy_UpDown();
	virtual void Tick(float DeltaSeconds) override;
protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region Variables
private:
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	FVector MaxMovingDistanceUp{0,0,100};
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	FVector MaxMovingDistanceDown{0,0,100};
	UPROPERTY(EditDefaultsOnly,Category = "Sphere Settings")
	FVector SphereMovingRate{0,0,2};
	UPROPERTY()
	bool isMovingUp{false};

	UPROPERTY()
	FVector SphereSpawnLocation;

#pragma endregion
	
};
