cbuffer CBIcon
{
	float4 color;
	float4 offset;
	float4 dimension;
	float4 flag2;
};

struct INPUT_GS
{
	float2 position : POSITION;
};

struct INPUT_PS
{
	float4 position : SV_POSITION;
	float4 color	: COLOR;
	float2 uv	: TEXCOORD;
};

[maxvertexcount(4)]
void main( point INPUT_GS input[1], inout TriangleStream<INPUT_PS> tri )
{
	INPUT_PS ps;

	// left bottom
	ps.position = float4(input[0].position.x + offset.x - dimension.x, input[0].position.y + offset.y - dimension.y, 	0, 1);
	ps.color= color;
	ps.uv	= float2(0,1);
	tri.Append(ps);

	// left top
	ps.position = float4(input[0].position.x + offset.x - dimension.x, input[0].position.y + offset.y  + dimension.y, 0, 1);
	ps.color= color;
	ps.uv	= float2(0,0);
	tri.Append(ps);

	// right bottom
	ps.position = float4(input[0].position.x + offset.x  + dimension.x, input[0].position.y + offset.y  - dimension.y, 0, 1);
	ps.color= color;
	ps.uv	= float2(1,1);
	tri.Append(ps);

	// right top
	ps.position = float4(input[0].position.x + offset.x  + dimension.x, input[0].position.y + offset.y  + dimension.y, 	0, 1);
	ps.color= color;
	ps.uv	= float2(1,0);
	tri.Append(ps);
};