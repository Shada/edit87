#define max3DTextures 5

cbuffer config
{
	float radius;
	float intensity;
	float2 origin;
	float2 textureIndex; // (depth,texture)
	float2 pad;
}

//RWTexture3D<float4>	blendmaps	: register(u0);
RWTexture2DArray<float4>	blendmaps	: register(u0);
//Texture3D<float4>	blendmapTextures	: register(t0);

[numthreads(32, 32, 1)]
void main(uint3 threadID : SV_DispatchThreadID)
{


	blendmaps[float3(threadID.xy, 0)] = float4(intensity, 0, 0, 0);
	blendmaps[float3(threadID.xy, 1)] = float4(0,0,0,0);
	blendmaps[float3(threadID.xy, 2)] = float4(0,0,0,0);
	blendmaps[float3(threadID.xy, 3)] = float4(0,0,0,0);
	blendmaps[float3(threadID.xy, 4)] = float4(0,0,0,0);

	/*blendmaps[float3(threadID.xy, 0)] = float4(1,1,1,1);
	blendmaps[float3(threadID.xy, 1)] = float4(1,1,1,1);
	blendmaps[float3(threadID.xy, 2)] = float4(1,1,1,1);
	blendmaps[float3(threadID.xy, 3)] = float4(1,1,1,1);
	blendmaps[float3(threadID.xy, 4)] = float4(1,1,1,1);*/

}