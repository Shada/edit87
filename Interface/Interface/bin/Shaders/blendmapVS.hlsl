
struct VS_Input
{
	float3 position : POSITION;
	float2 tex		: TEXCOORD0;
};

VS_Input main(VS_Input input)
{
	return input;
}