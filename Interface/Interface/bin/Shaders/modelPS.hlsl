Texture2D txDiffuse		: register(t0);

SamplerState samLinear	: register(s0);


struct PS_Input
{
	float4 position		: SV_POSITION;
	float2 tex			: TEXCOORD0;
	float3 lightInt		: LIGHT;
	float4 highlight	: COLOR;
};

float4 main(PS_Input input) : SV_TARGET0
{
	float4 color = txDiffuse.Sample(samLinear, input.tex) * input.highlight;
	color = saturate(color);
	return float4((color).xyz * input.lightInt, 1.f);
}