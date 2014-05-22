struct INPUT_VS
{
	float2 position	: POSITION;
	float2 dimension: DIMENSION;
};

struct INPUT_GS
{
	float2 position : POSITION;
	float2 dimension: DIMENSION;
};

INPUT_GS main( INPUT_VS input )
{
	INPUT_GS gs;

	gs.position 	= input.position;
	gs.dimension	= input.dimension;

	return gs;
}