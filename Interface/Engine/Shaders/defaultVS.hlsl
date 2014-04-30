struct VS_Input
{
	float3 position : POSITION;
};

struct VS_Output
{
	float4 position : SV_POSITION;
};

VS_Input main(VS_Input input)
{
	return input;
}