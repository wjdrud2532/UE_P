// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;

    // UE_LOG(LogTemp, Display, TEXT("Construct"));
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();

    // UE_LOG(LogTemp, Display, TEXT("Trigger Component Live"));
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // UE_LOG(LogTemp, Display, TEXT("Trigger Component Is Ticking"));
    
    if (Mover == nullptr)
    {
        return;
    }

    AActor *Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UE_LOG(LogTemp, Display, TEXT("true -------"));
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if(Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
        // UE_LOG(LogTemp, Display, TEXT("unlocking2222222222"));
    }
    else
    {
        UE_LOG(LogTemp, Display, TEXT("false -----"));
        Mover->SetShouldMove(false);
        // UE_LOG(LogTemp, Display, TEXT("Relocking111111"));
    }
}

void UTriggerComponent::SetMover(UMover *NewMover)
{
    Mover = NewMover;
}

AActor *UTriggerComponent::GetAcceptableActor() const
{
    // AActor* ReturnActor = nullptr;
    TArray<AActor *> Actors;
    GetOverlappingActors(Actors);

    // for(int32 i = 0; i < Actors.Num(); i ++)
    // {
    //     FString ActorName = Actors[i]->GetActorNameOrLabel();
    //     UE_LOG(LogTemp, Display, TEXT("Overlapping: %s"), *ActorName);
    // }

    for (AActor *Actor : Actors)
    {
        if (Actor->ActorHasTag(AcceptableActorTag))
        {
            UE_LOG(LogTemp, Display, TEXT("actor cccccc"));
            return Actor;
            //
            // ReturnActor = Actor;
            // FString ActorName = Actor->GetActorNameOrLabel();
            // UE_LOG(LogTemp, Display, TEXT("Unlocking -_____"));
        }
    }

    return nullptr;
}
