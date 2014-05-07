Texture2D txBlendTer	: register(t0);

SamplerState samLinear	: register(s0);

struct VS_Input
{
	float3 position : POSITION;
	float2 tex		: TEXCOORD0;
};

float4 main(VS_Input input) : SV_TARGET0
{
	//float4 blendTexCol = txBlendTer.Sample(samLinear, input.texBlend);
	//float inverseTotal = 1.f / (blendTexCol.x);// + blendTexCol.y + blendTexCol.z + blendTexCol.w);

	//float4 terCol0 = txBlendTer.Sample(samLinear, input.tex);
	////float4 terCol1 = txDiffuse[1].Sample(samLinear, input.tex);
	////float4 terCol2 = txDiffuse[2].Sample(samLinear, input.tex);
	////float4 terCol3 = txDiffuse[3].Sample(samLinear, input.tex);

	////terCol0 *= blendTexCol.x * inverseTotal;
	////terCol1 *= blendTexCol.y * inverseTotal;
	////terCol2 *= blendTexCol.z * inverseTotal;
	////terCol3 *= blendTexCol.w * inverseTotal;

	////return float4((terCol0 + terCol1 + terCol2).xyz * input.lightInt, 1.f);
	//return float4((terCol0).xyz * input.lightInt, 1.f);
	return float4(0,0,0,0);
}