/*// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCustomComponentVertexBuffer.h"

void FTestCustomComponentVertexBuffer::InitRHI()
{
	FRHIResourceCreateInfo CreateInfo(TEXT("TestCustomComponentVertexBuffer"));
	VertexBufferRHI = RHICreateVertexBuffer(Vertices.Num() * sizeof(FDynamicMeshVertex), BUF_Static, CreateInfo);
	void* VertexBufferData = RHILockBuffer(VertexBufferRHI, 0, Vertices.Num() * sizeof(FDynamicMeshVertex), RLM_WriteOnly);
	FMemory::Memcpy(VertexBufferData, Vertices.GetData(), Vertices.Num() * sizeof(FDynamicMeshVertex));
	RHIUnlockBuffer(VertexBufferRHI);
}*/