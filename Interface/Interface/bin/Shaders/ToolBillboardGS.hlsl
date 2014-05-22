struct INPUT_GS
{
	float2 position : POSITION;
	float2 dimension: DIMENSION;
	float4 color	: COLOR;
};

struct INPUT_PS
{
	float4 position : SV_POSITION;
	float4 color	: COLOR;
};

[maxvertexcount(4)]
void main( point INPUT_GS input[1], inout TriangleStream<INPUT_PS> tri )
{
	INPUT_PS ps;

	// left bottom
	ps.position = float4(input[0].position.x - input[0].dimension.x, input[0].position.y - input[0].dimension.y, 0, 1);
	ps.color = input[0].color;
	tri.Append(ps);

	// left top
	ps.position = float4(input[0].position.x - input[0].dimension.x, input[0].position.y + input[0].dimension.y, 0, 1);
	ps.color = input[0].color;
	tri.Append(ps);

	// right bottom
	ps.position = float4(input[0].position.x + input[0].dimension.x, input[0].position.y - input[0].dimension.y, 0, 1);
	ps.color = input[0].color;
	tri.Append(ps);

	// right top
	ps.position = float4(input[0].position.x + input[0].dimension.x, input[0].position.y + input[0].dimension.y, 0, 1);
	ps.color = input[0].color;
	tri.Append(ps);
};