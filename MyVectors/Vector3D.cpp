#include "Vector3D.h"

using namespace vectors;

Vector3D::Vector3D()
{
	this->_x = 0.0f;
	this->_y = 0.0f;
	this->_z = 0.0f;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

Vector3D Vector3D::operator+(Vector3D vectorB) const
{
    return Vector3D(this->_x + vectorB._x, this->_y + vectorB._y, this->_z + vectorB._z);
}

Vector3D Vector3D::operator+=(Vector3D vectorB)
{
    this->_x += vectorB._x;
    this->_y += vectorB._y;
    this->_z += vectorB._z;

    return *this;
}

Vector3D Vector3D::operator-(Vector3D vectorB) const
{
    return Vector3D(this->_x - vectorB._x, this->_y - vectorB._y, this->_z - vectorB._z);
}

Vector3D Vector3D::operator-=(Vector3D vectorB)
{
    this->_x -= vectorB._x;
    this->_y -= vectorB._y;
    this->_z -= vectorB._z;

    return *this;
}

Vector3D Vector3D::operator*(float scalar) const
{
    return Vector3D(this->_x * scalar, this->_y * scalar, this->_z * scalar);
}

Vector3D Vector3D::operator*=(float scalar)
{
    this->_x *= scalar;
    this->_y *= scalar;
    this->_z *= scalar;

    return *this;
}

float Vector3D::DotProduct(Vector3D vectorB)
{
    return (this->GetX() * vectorB.GetX() + this->GetY() * vectorB.GetY() + this->GetZ() * vectorB.GetZ());
}

Vector3D Vector3D::CrossProduct(Vector3D vectorB)
{
    float newX = this->GetY() * vectorB.GetZ() - this->GetZ() * vectorB.GetY();
    float newY = this->GetZ() * vectorB.GetX() - this->GetX() * vectorB.GetZ();
    float newZ = this->GetX() * vectorB.GetY() - this->GetY() * vectorB.GetX();

    return Vector3D(newX, newY, newZ);
}

float Vector3D::GetMagnitude()
{
    float squaredX = this->GetX() * this->GetX();
    float squaredY = this->GetY() * this->GetY();
    float squaredZ = this->GetZ() * this->GetZ();

    return std::sqrt(squaredX + squaredY + squaredZ);
}

Vector3D Vector3D::Normalize()
{
    float magnitude = this->GetMagnitude();

    if(magnitude != 0)
    {
        float normalizedX = this->GetX() / magnitude;
        float normalizedY = this->GetY() / magnitude;
        float normalizedZ = this->GetZ() / magnitude;

        return Vector3D(normalizedX, normalizedY, normalizedZ);
    }

    std::cerr << "Vector Magnitude is 0! Operation undefined!";
    return Vector3D(0.0f, 0.0f, 0.0f);
}

float Vector3D::GetX()
{
	return this->_x;
}

float Vector3D::GetY()
{
	return this->_y;
}

float Vector3D::GetZ()
{
	return this->_z;
}


