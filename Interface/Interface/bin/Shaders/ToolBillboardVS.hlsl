struct INPUT_VS
{
	float2 position	: POSITION;
	float2 dimension: DIMENSION;
	float4 color	: COLOR;
};

struct INPUT_GS
{
	float2 position : POSITION;
	float2 dimension: DIMENSION;
	float4 color	: COLOR;
};

INPUT_GS main( INPUT_VS input )
{
	INPUT_GS gs;

	gs.position 	= input.position;
	gs.dimension	= input.dimension;
	gs.color	= input.color;

	return gs;
}