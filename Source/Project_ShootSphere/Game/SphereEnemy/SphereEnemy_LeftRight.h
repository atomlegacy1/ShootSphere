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
	void MoveSphereLeftRight();

#pragma endregion

#pragma region Variables
private:
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MaxMovingDistanceLeft{0};
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MaxMovingDistanceRight{0};

	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MinMovingDistanceLeft{0};
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MinMovingDistanceRight{0};

#pragma endregion
	
};
