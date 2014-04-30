struct PS_Input
{
	float4 position : SV_POSITION;
};

float4 main(PS_Input input) : SV_TARGET0
{
	return float4(1,0,0,1);
}