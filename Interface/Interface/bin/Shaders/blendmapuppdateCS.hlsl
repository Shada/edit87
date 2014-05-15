#define max3DTextures 5

cbuffer config
{
	float radius;
	float intensity;
	float2 origin;
	float2 textureIndex; // (depth,texture)
	float2 pad;
}

RWTexture3D<float4>	blendmaps	: register(u0);
//Texture3D<float4>	blendmapTextures	: register(t0);

[numthreads(32, 32, 1)]
void main(uint3 threadID : SV_DispatchThreadID)
{
	float4 outputColor = float4(0, 0, 0, 1);

	float2 terrainPos = threadID.xy;

	float2 distVec = origin - terrainPos;

	float distFromOrigin = length(distVec);

	if (distFromOrigin < radius)
	{
		float deminish = 1 - intensity;

		/*blendmaps[float3(threadID.xy, 0)] = blendmapTextures[float3(threadID.xy, 0)] * deminish;
		blendmaps[float3(threadID.xy, 1)] = blendmapTextures[float3(threadID.xy, 1)] * deminish;
		blendmaps[float3(threadID.xy, 2)] = blendmapTextures[float3(threadID.xy, 2)] * deminish;
		blendmaps[float3(threadID.xy, 3)] = blendmapTextures[float3(threadID.xy, 3)] * deminish;
		blendmaps[float3(threadID.xy, 4)] = blendmapTextures[float3(threadID.xy, 4)] * deminish;
		*/
		float result[4];
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
		result[3] = 0;
		result[textureIndex.y] = intensity;

		float4 endResult = float4(result[0], result[1], result[2], result[3]);

		blendmaps[float3(threadID.xy, textureIndex.x)] = endResult;
		
		//blendmaps[float3(threadID.xy, 0)] = float4(1,0,0,0);

	}



	blendmaps[float3(threadID.xy, 0)] = float4(1, 0, 0, 0);
	blendmaps[float3(threadID.xy, 1)] = float4(0, 0, 0, 0);
	blendmaps[float3(threadID.xy, 2)] = float4(0, 0, 0, 0);
	blendmaps[float3(threadID.xy, 3)] = float4(0, 0, 0, 0);
	blendmaps[float3(threadID.xy, 4)] = float4(0, 0, 0, 0);


}