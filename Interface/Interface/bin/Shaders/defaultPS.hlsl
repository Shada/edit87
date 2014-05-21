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
	//float4 blendTexCol = txBlendTer.Sample(samLinear, input.texBlend);
	//float inverseTotal = 1.f / (blendTexCol.x);// + blendTexCol.y + blendTexCol.z + blendTexCol.w);

	//float4 terCol0 = txBlendTer.Sample(samLinear, input.tex);
	//float4 terCol1 = txDiffuse[1].Sample(samLinear, input.tex);
	//float4 terCol2 = txDiffuse[2].Sample(samLinear, input.tex);
	//float4 terCol3 = txDiffuse[3].Sample(samLinear, input.tex);

	//terCol0 *= blendTexCol.x * inverseTotal;
	//terCol1 *= blendTexCol.y * inverseTotal;
	//terCol2 *= blendTexCol.z * inverseTotal;
	//terCol3 *= blendTexCol.w * inverseTotal;

	float4 outputColor = float4(0, 0, 0, 1);
	for (int i = 0; i < 5; i++)
	{

		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 0 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).x;
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 1 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).y;
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 2 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).z;
		outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 3 + i * 4)) * blendmaps.Sample(samLinear, float3(input.texBlend, i)).w;


	/*	outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 0 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].x;
		outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 1 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].y;
		outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 2 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].z;
		outputColor += blendmapArray[float3(threadID.x / 2, threadID.y / 2, 3 + i * 4)] * blendmaps[float3(float3(threadID.x / 2, threadID.y / 2, i))].w;*/
	}

	//outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 0));
	//outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 1));
	//outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 2));
	//outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 3));
	//outputColor += blendmapArray.Sample(samLinear, float3(input.texBlend, 4));


	//outputColor += blendmaps.Sample(samLinear, float3(input.texBlend, 0));
	//outputColor = blendmaps.Sample(samLinear, float3(input.texBlend, 1));
	//outputColor += blendmaps.Sample(samLinear, float3(input.texBlend, 2));
	//outputColor += blendmaps.Sample(samLinear, float3(input.texBlend, 3));
	//outputColor = blendmaps.Sample(samLinear, float3(input.texBlend, 4));

	//saturate(outputColor);

	//return outputColor;


	//return float4((terCol0 + terCol1 + terCol2).xyz * input.lightInt, 1.f);
	return float4((outputColor).xyz * input.lightInt, 1.f);
}