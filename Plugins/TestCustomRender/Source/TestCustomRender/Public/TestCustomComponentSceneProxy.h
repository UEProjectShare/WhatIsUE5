/*
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PrimitiveSceneProxy.h"
#include "TestCustomComponentIndexBuffer.h"
#include "TestCustomComponentVertexBuffer.h"
#include "TestCustomComponentVertexFactory.h"

class FTestCustomComponentSceneProxy : public FPrimitiveSceneProxy
{
public:
	FTestCustomComponentIndexBuffer IndexBuffer;
	FTestCustomComponentVertexBuffer VertexBuffer;
	FTestCustomComponentVertexFactory VertexFactory = FTestCustomComponentVertexFactory(ERHIFeatureLevel::Type::SM6);
	
	FTestCustomComponentSceneProxy(const UPrimitiveComponent* Component);

	virtual ~FTestCustomComponentSceneProxy() override;
	
	virtual uint32 GetMemoryFootprint() const override;
 
	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, class FMeshElementCollector& Collector) const override;
 
	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView * View) const  override;

	virtual SIZE_T GetTypeHash() const override;
	
	virtual void DrawStaticElements(FStaticPrimitiveDrawInterface*PDI)override;
};
*/
