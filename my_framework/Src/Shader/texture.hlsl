float4 screen : register(b0);

struct VS_INPUT		// ���_�V�F�[�_
{
	float4 position : POSITION;
	float4 color : COLOR;
	float2 tx0 : TEXCOORD0;
};

//================================================================================
// �o�̓p�����[�^
//================================================================================
struct VS_OUTPUT	// ���_�V�F�[�_
{
	float4 position : SV_POSITION;
	float4 color: COLOR;
	float2 tx0 : TEXCOORD0;
};

//================================================================================
// ���_�V�F�[�_
//================================================================================
VS_OUTPUT vsMain(VS_INPUT input)
{
	VS_OUTPUT output;

	// ���H�Ȃ��ł��̂܂܏o��
	output.position = float4((input.position.xy + screen.zw) * screen.xy, 0.0, 1.0);
	output.color = input.color;
	output.tx0 = input.tx0;

	return output;
}

// �s�N�Z���V�F�[�_���̓p�����[�^
typedef VS_OUTPUT PS_INPUT;		// �u������

Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);

//================================================================================
// �s�N�Z���V�F�[�_
//================================================================================
float4 psMain(PS_INPUT input) : SV_TARGET
{
	float4 color = txDiffuse.Sample(samLinear, input.tx0) * input.color;

	return color;
}