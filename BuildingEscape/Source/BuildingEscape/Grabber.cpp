// Copyright King Crawford 2016.

#include "BuildingEscape.h"
#include "Grabber.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
    
	UE_LOG(LogTemp, Warning, TEXT("Grabber reporting for duty!"));
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT playerViewpointLoc, OUT playerViewpointRot);
    
    FString pVL = playerViewpointLoc.ToString();
    FString pVR = playerViewpointRot.ToString();
    
    UE_LOG(LogTemp, Warning, TEXT("loc: %s, rot: %s"), *pVL, *pVR)
}

