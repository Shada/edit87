cbuffer onChanges : register(b0)
{
	float4x4 viewProj;
	float4x4 world;
	float4 eyePos;
};

struct VS_Input
{
	float3 position : POSITION;
	float3 norm		: NORMAL;
	float2 tex		: TEXCOORD0;
};

struct VS_Output
{
	float4 position : SV_POSITION;
	float2 tex		: TEXCOORD0;
	float3 lightInt : LIGHT;
};

VS_Output main(VS_Input input)
{
	VS_Output output = (VS_Output)0;
	output.position = mul(world, float4(input.position, 1));
	output.position = mul(viewProj, output.position);

	float4 lightPos = float4(-4000, 600, 1000, 1);
	float3 s = normalize(lightPos - eyePos).xyz;
	float3 tnorm = input.norm;
	output.lightInt = float3(0.9,0.9,0.9) * max(dot(s,tnorm),0.0) + float3(0.35,0.35,0.35);

	output.tex = input.tex;

	return output;
}