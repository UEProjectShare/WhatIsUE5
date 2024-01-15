/*
// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCustomComponentSceneProxy.h"
#include "MaterialDomain.h"

FTestCustomComponentSceneProxy::FTestCustomComponentSceneProxy(const UPrimitiveComponent* Component)
	: FPrimitiveSceneProxy(Component)
{
	const float BoxSize = 100.0f;

	//Ìî³ä¶¥µã
	VertexBuffer.Vertices.Add(FVector3f(0.0F));
	VertexBuffer.Vertices.Add(FVector3f(BoxSize, 0.0f, 0.0f));
	VertexBuffer.Vertices.Add(FVector3f(0.0f, BoxSize, 0.0f));
	VertexBuffer.Vertices.Add(FVector3f(0.0f, 0.0f, BoxSize));
	//Ìî³äË÷Òý
	IndexBuffer.Indices.Add(0);
	IndexBuffer.Indices.Add(1);
	IndexBuffer.Indices.Add(2);
	
	IndexBuffer.Indices.Add(0);
	IndexBuffer.Indices.Add(2);
	IndexBuffer.Indices.Add(3);

	IndexBuffer.Indices.Add(0);
	IndexBuffer.Indices.Add(3);
	IndexBuffer.Indices.Add(1);

	IndexBuffer.Indices.Add(3);
	IndexBuffer.Indices.Add(2);
	IndexBuffer.Indices.Add(1);
	
	//³õÊ¼»¯
	VertexFactory.Init(&VertexBuffer);
	BeginInitResource(&IndexBuffer);
	BeginInitResource(&VertexBuffer);
	BeginInitResource(&VertexFactory);
}

FTestCustomComponentSceneProxy::~FTestCustomComponentSceneProxy()
{
	VertexBuffer.ReleaseResource();
	IndexBuffer.ReleaseResource();
	VertexFactory.ReleaseResource();
}

uint32 FTestCustomComponentSceneProxy::GetMemoryFootprint() const
{
	return (sizeof(*this) + GetAllocatedSize());
}

void FTestCustomComponentSceneProxy::GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const
{
	const FBox TestDynamicBox = FBox(FVector(-100.0f), FVector(100.0f));
	DrawWireBox(
		Collector.GetPDI(0),
		GetLocalToWorld(),
		TestDynamicBox,
		FLinearColor::Red,
		ESceneDepthPriorityGroup::SDPG_Foreground,
		10.0f);
}

FPrimitiveViewRelevance FTestCustomComponentSceneProxy::GetViewRelevance(const FSceneView* View) const
{
	FPrimitiveViewRelevance Result;
	Result.bStaticRelevance = true;
	Result.bDrawRelevance = IsShown(View);
	Result.bDynamicRelevance = true;
	Result.bShadowRelevance = IsShadowCast(View);
	Result.bEditorPrimitiveRelevance = UseEditorCompositing(View);
	return Result;
}

SIZE_T FTestCustomComponentSceneProxy::GetTypeHash() const
{
	static size_t UniquePointer;
	return reinterpret_cast<size_t>(&UniquePointer);
}

void FTestCustomComponentSceneProxy::DrawStaticElements(FStaticPrimitiveDrawInterface* PDI)
{
	FMeshBatch Mesh;
	FMeshBatchElement& BatchElement = Mesh.Elements[0];
	Mesh.bWireframe = false;
	Mesh.VertexFactory = &VertexFactory;
	Mesh.MaterialRenderProxy = UMaterial::GetDefaultMaterial(MD_Surface)->GetRenderProxy();
	//Mesh->SetMaterial(0,);

	BatchElement.IndexBuffer = &IndexBuffer;
	BatchElement.PrimitiveUniformBuffer = CreatePrimitiveUniformBufferImmediate(GetLocalToWorld(), GetBounds(), GetLocalBounds(), FBoxSphereBounds(),true, true);
	
	BatchElement.FirstIndex = 0;
	BatchElement.NumPrimitives = IndexBuffer.Indices.Num() / 3;
	BatchElement.MinVertexIndex = 0;
	BatchElement.MaxVertexIndex = VertexBuffer.Vertices.Num() - 1;
	Mesh.ReverseCulling = IsLocalToWorldDeterminantNegative();
	Mesh.Type = PT_TriangleList;
	Mesh.DepthPriorityGroup = SDPG_Foreground;
	Mesh.bCanApplyViewModeOverrides = false;
	Mesh.bDisableBackfaceCulling = false;
	PDI->DrawMesh(Mesh, 1.0f);
}
*/
