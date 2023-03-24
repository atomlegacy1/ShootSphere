// AtomLegacy1 property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShootSphereGameMode.generated.h"

UCLASS()
class PROJECT_SHOOTSPHERE_API AShootSphereGameMode : public AGameModeBase
{
	GENERATED_BODY()

#pragma region Variables
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	int32 TotalPlayerPoints{0};

#pragma endregion 
};
