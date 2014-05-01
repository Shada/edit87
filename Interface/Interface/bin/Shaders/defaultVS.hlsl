cbuffer once : register(b0)
{
	float4x4 proj;
};

cbuffer onChanges : register(b1)
{
	float4x4 world;
	float4x4 view;
	float4 eyePos;
};

struct VS_Input
{
	float3 position : POSITION;
};

struct VS_Output
{
	float4 position : SV_POSITION;
};

VS_Output main(VS_Input input)
{
	VS_Output output = (VS_Output)0;
	float4x4 worldviewproj = mul(mul(world, view), proj);
	output.position = mul(worldviewproj, float4(input.position, 1));
	return output;
}