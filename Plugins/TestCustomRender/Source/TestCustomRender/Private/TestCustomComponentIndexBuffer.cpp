/*
// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCustomComponentIndexBuffer.h"

void FTestCustomComponentIndexBuffer::InitRHI()
{
	FRHIResourceCreateInfo CreateInfo(TEXT("TestCustomComponentIndexBuffer"));
	IndexBufferRHI = RHICreateIndexBuffer(sizeof(int32), Indices.Num() * sizeof(int32), BUF_Static, CreateInfo);
	void* Buffer = RHILockBuffer(IndexBufferRHI, 0, Indices.Num() * sizeof(int32), RLM_WriteOnly);
	FMemory::Memcpy(Buffer, Indices.GetData(), Indices.Num() * sizeof(int32));
	RHIUnlockBuffer(IndexBufferRHI);
}
*/
