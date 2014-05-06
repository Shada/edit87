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
	float2 texBlend : TEXCOORD1;
	float3 lightInt : LIGHT;
};

VS_Output main(VS_Input input)
{
	VS_Output output = (VS_Output)0;
	//float4x4 worldviewproj = mul(proj, view);
	output.position = mul(viewProj, float4(input.position, 1));

	float4 lightPos = float4(-4000, 1600, 1000, 1);
	float3 s = normalize(lightPos - eyePos).xyz;
	float3 tnorm = input.norm;
	output.lightInt = float3(0.9,0.9,0.9) * max(dot(s,tnorm),0.0) + float3(0.65,0.65,0.65);
	//output.lightInt = 1.f;

	output.tex = input.tex;

	//128 = width / 2, 20 = pointStep
	output.texBlend.x = (input.position.x + 256 * 5) / (256 * 5);
	output.texBlend.y = (input.position.z - 256 * 5) / (-256 * 5);
	return output;
}