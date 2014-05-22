Texture2D	txDiffuse	: register(t0);
SamplerState	samLinear	: register(s0);

struct INPUT_PS
{
	float4 position : SV_POSITION;
	float4 color	: COLOR;
};

float4 main(INPUT_PS input) : SV_TARGET
{
	return input.color;
}