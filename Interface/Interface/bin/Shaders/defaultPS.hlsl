//Texture2D<float4> txBlendTer : register(t0);

Texture2DArray<float4>	blendmapArray	: register(t0);
Texture2DArray<float4>	blendmaps	: register(t1);

#define max3DTextures 20

SamplerState samLinear	: register(s0);

struct PS_Input
{
	float4 position		: SV_POSITION;
	float2 tex			: TEXCOORD0;
	float2 texBlend		: TEXCOORD1;
	float3 lightInt		: LIGHT;
};

float4 main(PS_Input input) : SV_TARGET0
{


	float4 outputColor = float4(0, 0, 0, 1);
	for (int i = 0; i < 5; i++)
	{
	
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 0 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).x;
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 1 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).y;
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 2 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).z;
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 3 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).w;
	
	}
	//float4 color = txBlendTer.Sample(samLinear, input.tex);

	//return float4((color).xyz * input.lightInt, 1.f);
	return float4((outputColor).xyz * input.lightInt, 1.f);
}