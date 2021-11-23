#pragma once

//float型を３つもつ構造体
struct stVector3 {
public:
	const stVector3 operator -(stVector3& vec) {
		stVector3 temp;
		temp.x = x - vec.x;
		temp.y = y - vec.y;
		temp.z = z - vec.z;
		return temp;
	}
	const stVector3 operator +(stVector3& vec) {
		stVector3 temp;
		temp.x = x + vec.x;
		temp.y = y + vec.y;
		temp.z = z + vec.z;
		return temp;
	}
	const stVector3 operator *(stVector3& vec) {
		stVector3 temp;
		temp.x = x * vec.x;
		temp.y = y * vec.y;
		temp.z = z * vec.z;
		return temp;
	}
	const stVector3 operator /(stVector3& vec) {
		stVector3 temp;
		temp.x = x / vec.x;
		temp.y = y / vec.y;
		temp.z = z / vec.z;
		return temp;
	}
	const stVector3 operator +=(stVector3& vec) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	const stVector3 operator -=(stVector3& vec) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}
	const stVector3 operator *=(stVector3& vec) {
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
		return *this;
	}
	const stVector3 operator /=(stVector3& vec) {
		x /= vec.x;
		y /= vec.y;
		z /= vec.z;
		return *this;
	}

	const bool operator !=(int num) {
		if (x != num || y != num || z != num) return true;
		return false;
	}

	float x;
	float y;
	float z;
};

//カラー構造体
struct stColor4 {
	float r, g, b, a;
};

//2Dオブジェクト頂点構造体
struct stVertex
{
	float x, y;
	float r, g, b, a;
	float u, v;
};