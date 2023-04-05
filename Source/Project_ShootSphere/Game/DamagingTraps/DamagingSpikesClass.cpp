// AtomLegacy1 property


#include "Project_ShootSphere/Game/DamagingTraps/DamagingSpikesClass.h"
#include "Project_ShootSphere/Game/PlayerCharacter/ShootSpherePlayerCharacter_Base.h"
#include "Kismet/GameplayStatics.h"

ADamagingSpikesClass::ADamagingSpikesClass()
{
	MovingSpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("MovingSpikesMesh"));
	MovingSpikesMesh->SetupAttachment(RootComp);
	SpikesOutCollision = CreateDefaultSubobject<UBoxComponent>(FName("SpikesOutCollision"));
	SpikesOutCollision->SetupAttachment(RootComp);
}

void ADamagingSpikesClass::BeginPlay()
{
	Super::BeginPlay();

	SpikesMovingRate = 2;
	RangeToOut = 95;
	FVector TempVector{0,RangeToOut,0};
	SpikesMovingVector={0,SpikesMovingRate,0};
	
	SpikesStartLocation = MovingSpikesMesh->GetComponentLocation();
	SpikesOutLocation = MovingSpikesMesh->GetComponentLocation() + TempVector;
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::StartApplyDamage);
	CollisionComp->OnComponentEndOverlap.AddDynamic(this,&ThisClass::StopApplyDamage);

	SpikesOutCollision->OnComponentBeginOverlap.AddDynamic(this,&ThisClass::MoveSpikesUp);
	SpikesOutCollision->OnComponentEndOverlap.AddDynamic(this,&ThisClass::MoveSpikesDown);
}

void ADamagingSpikesClass::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SpikesCurrentLocation = MovingSpikesMesh->GetComponentLocation();
}

void ADamagingSpikesClass::StartApplyDamage(class UPrimitiveComponent* OverlappedComp,class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		CharacterToDamage = OtherActor;
		GetWorldTimerManager().SetTimer(THDamageApply,this,&ThisClass::ApplyDamageToActor,2.5f,true);
	}
}
void ADamagingSpikesClass::StopApplyDamage(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		GetWorldTimerManager().ClearTimer(THDamageApply);
	}
}
void ADamagingSpikesClass::ApplyDamageToActor()
{
	UGameplayStatics::ApplyDamage(CharacterToDamage,DamageToCause,GetInstigatorController(),
this,UDamageType::StaticClass());
}

void ADamagingSpikesClass::MoveSpikesUp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		isCharacterOverlap = true;
		if (SpikesCurrentLocation!=SpikesStartLocation)
		{
			MoveSpikes();
			//GetWorldTimerManager().SetTimer(THSpikesMove,this,&ThisClass::MoveSpikes,1.0f,true);
		}
		else
		{
			GetWorldTimerManager().ClearTimer(THSpikesMove);
		}
	}
}
void ADamagingSpikesClass::MoveSpikesDown(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == UGameplayStatics::GetPlayerCharacter(GetWorld(),0))
	{
		isCharacterOverlap = false;
		if (SpikesCurrentLocation!=SpikesOutLocation)
		{
			MoveSpikes();
			//GetWorldTimerManager().SetTimer(THSpikesMove,this,&ThisClass::MoveSpikes,1.0f,true);
		}
		else
		{
			GetWorldTimerManager().ClearTimer(THSpikesMove);
		}
	}
}
void ADamagingSpikesClass::MoveSpikes()
{
	if (isCharacterOverlap)
	{
		MovingSpikesMesh->SetWorldLocation(SpikesCurrentLocation+SpikesMovingVector);
	}
	else
	{
		MovingSpikesMesh->SetWorldLocation(SpikesCurrentLocation-SpikesMovingVector);
	}
}
