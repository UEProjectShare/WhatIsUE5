#include "WhiteNoiseConsumer.h"

#include "Kismet/GameplayStatics.h"
#include "CustomShadersDeclarations/Private/ComputeShaderDeclaration.h"

// Sets default values
AWhiteNoiseConsumer::AWhiteNoiseConsumer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	StaticMesh->SetupAttachment(RootComponent);

	TimeStamp = 0;
}

// Called when the game starts or when spawned
void AWhiteNoiseConsumer::BeginPlay()
{
	Super::BeginPlay();
	FWhiteNoiseCSManager::Get()->BeginRendering();
	
	//Assuming that the static mesh is already using the material that we're targeting, we create an instance and assign it to it
	if(UMaterialInstanceDynamic* MID = StaticMesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		MID->SetTextureParameterValue("InputTexture", (UTexture*)RenderTarget);
	}
}

void AWhiteNoiseConsumer::BeginDestroy()
{
	FWhiteNoiseCSManager::Get()->EndRendering();
	Super::BeginDestroy();
}

// Called every frame
void AWhiteNoiseConsumer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Update parameters
	FWhiteNoiseCSParameters Parameters(RenderTarget);
	TimeStamp++;
	Parameters.TimeStamp = TimeStamp;
	FWhiteNoiseCSManager::Get()->UpdateParameters(Parameters);
}
