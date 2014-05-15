#define max3DTextures 5

RWTexture2D<float4>	blendDone	: register(u0);
Texture2DArray<float4>	blendmapArray	: register(t0);
Texture3D<float4>	blendmaps	: register(t1);

[numthreads(32, 32, 1)]
void main(uint3 threadID : SV_DispatchThreadID)
{
	float4 outputColor = float4(0, 0, 0, 1);

	for (int i = 0; i < max3DTextures; i++)
	{
		outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 0 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, 4))].x;
		//outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 1 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].y;
		//outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 2 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].z;
		//outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 3 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].w;
	}

	
	//outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 3)];
	/*outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 0)];
	outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 0)];
	outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 0)];*/
	

	blendDone[threadID.xy] = outputColor;
}