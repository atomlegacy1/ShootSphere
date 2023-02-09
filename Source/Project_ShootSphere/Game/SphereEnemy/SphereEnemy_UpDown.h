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

#pragma endregion

#pragma region Variables
private:
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MaxMovingDistanceUp{0};
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MaxMovingDistanceDown{0};

	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MinMovingDistanceUp{0};
	UPROPERTY(EditAnywhere,Category = "Sphere Settings")
	float MinMovingDistanceDown{0};

#pragma endregion
	
};
