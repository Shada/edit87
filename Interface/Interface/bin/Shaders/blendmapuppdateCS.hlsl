#define max3DTextures 5

RWTexture3D<float4>	blendmaps	: register(u0);

[numthreads(32, 32, 1)]
void main(uint3 threadID : SV_DispatchThreadID)
{
	float4 outputColor = float4(0, 0, 0, 1);

	//------------------------------------------------------- logic for uppdate later

	//-------------------------------------------------------

	blendmaps[float3(threadID.xy, 0)] = float4(1, 0, 0, 0);;
	blendmaps[float3(threadID.xy, 1)] = float4(0, 1, 0, 0);;
	blendmaps[float3(threadID.xy, 2)] = float4(0, 0, 1, 0);;
	blendmaps[float3(threadID.xy, 3)] = float4(0, 0, 0, 1);;
	blendmaps[float3(threadID.xy, 4)] = float4(1, 0, 0, 1);;

}