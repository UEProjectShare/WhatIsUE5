/*
// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCustomComponentVertexFactory.h"

#include "DynamicMeshBuilder.h"
#include "TestCustomComponentVertexBuffer.h"

FTestCustomComponentVertexFactory::FTestCustomComponentVertexFactory(ERHIFeatureLevel::Type InFeatureLevel)
	: FLocalVertexFactory(InFeatureLevel, "FTestCustomComponentVertexFactory")
{
}

void FTestCustomComponentVertexFactory::Init(const FTestCustomComponentVertexBuffer* VertexBuffer)
{
	if (IsInRenderingThread())
	{
		//Initialize the vertex factory'sstream components
		FDataType NewData;
		NewData.PositionComponent = STRUCTMEMBER_VERTEXSTREAMCOMPONENT(VertexBuffer, FDynamicMeshVertex, Position, VET_Float3);
		//NewData.TextureCoordinates.Add(FVertexStreamComponent(VertexBuffer, STRUCT_OFFSET(FDynamicMeshVertex, TextureCoordinate), sizeof(FDynamicMeshVertex), VET_Float2));
		//NewData.TangentBasisComponents[0] = STRUCTMEMBER_VERTEXSTREAMCOMPONENT(VertexBuffer, FDynamicMeshVertex, TangentX, VET_PackedNormal);
		//NewData.TangentBasisComponents[1] = STRUCTMEMBER_VERTEXSTREAMCOMPONENT(VertexBuffer, FDynamicMeshVertex, TangentZ, VET_PackedNormal);
		SetData(NewData);
	}
	else
	{
		ENQUEUE_RENDER_COMMAND(TestCustomComponentVertexFactoryCommand)(
	[&VertexBuffer, this](FRHICommandListImmediate& RHICmdList)
			{
				//Initialize the vertex factory's stream componnents,
				FDataType NewData;
				NewData.PositionComponent = STRUCTMEMBER_VERTEXSTREAMCOMPONENT(VertexBuffer, FDynamicMeshVertex, Position, VET_Float3);
				//NewData.TextureCoordinates.Add(FVertexStreamComponent(VertexBuffer, STRUCT_OFFSET(FDynamicMeshVertex, TextureCoordinate), sizeof(FDynamicMeshVertex), VET_Float2));
				//NewData.TangentBasisComponents[0] = STRUCTMEMBER_VERTEXSTREAMCOMPONENT(VertexBuffer, FDynamicMeshVertex, TangentX, VET_PackedNormal);
				//NewData.TangentBasisComponents[1] = STRUCTMEMBER_VERTEXSTREAMCOMPONENT(VertexBuffer, FDynamicMeshVertex, TangentZ, VET_PackedNormal);
				SetData(NewData);
			});
	}
}
*/
