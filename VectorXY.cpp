#include <iostream>
#include <math.h>
#include "VectorXY.hpp"
/////////////////////////////////////////////////////////////////
VectorXY::VectorXY(float a, float b)
{
    x = a;
    y = b;
}
/////////////////////////////////////////////////////////////////
VectorXY::VectorXY(const VectorXY& other)
{
    x = other.x;
    y = other.y;
}
/////////////////////////////////////////////////////////////////
VectorXY::VectorXY()
{
    x = 0;
    y = 0;
}
/////////////////////////////////////////////////////////////////
VectorXY::~VectorXY(){}
/////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& stream, const VectorXY& v)
{
    stream << v.x << " " << v.y;
    return stream;
}
/////////////////////////////////////////////////////////////////
std::istream& operator>>(std::istream& stream, VectorXY& v)
{
    stream >> v.x >> v.y;
    return stream;
}
/////////////////////////////////////////////////////////////////
VectorXY& VectorXY::operator=(const VectorXY& other)
{
    x = other.x;
    y = other.y;
    return *this;
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::operator+(const VectorXY& other) const
{
    return VectorXY(x + other.x, y + other.y);
}
/////////////////////////////////////////////////////////////////
VectorXY& VectorXY::operator+=(const VectorXY& other)
{
    x += other.x;
    y += other.y;
    return *this;
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::operator-(const VectorXY& other) const
{
    return VectorXY(x - other.x, y - other.y);
}
/////////////////////////////////////////////////////////////////
VectorXY& VectorXY::operator-=(const VectorXY& other)
{
    x -= other.x;
    y -= other.y;
    return *this;
}
/////////////////////////////////////////////////////////////////
float VectorXY::operator*(const VectorXY& other) const
{
    return (x * other.x) + (y * other.y);
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::operator*(float a) const
{
    return VectorXY(x * a, y * a);
}
/////////////////////////////////////////////////////////////////
VectorXY operator*(float a, const VectorXY& v)
{
    return VectorXY(v.x * a, v.y * a);
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::operator/(float a) const
{
    return VectorXY(x / a, y / a);
}
/////////////////////////////////////////////////////////////////
float VectorXY::len() const
{
    return sqrt(x * x + y * y);
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::norm() const
{
    return VectorXY(x / len(), y / len());
}
/////////////////////////////////////////////////////////////////
float VectorXY::operator^(const VectorXY& other) const
{
    return x * other.y - y * other.x;
}
/////////////////////////////////////////////////////////////////
float VectorXY::sinaxis() const
{
    return y / len();
}
/////////////////////////////////////////////////////////////////
float VectorXY::cosaxis() const
{
    return x / len();
}
/////////////////////////////////////////////////////////////////
float VectorXY::tgaxis() const
{
    return sinaxis() / cosaxis();
}
/////////////////////////////////////////////////////////////////
float sinvec(const VectorXY& v1, const VectorXY& v2)
{
    return v1.sinaxis() * v2.cosaxis() - v1.cosaxis() * v2.sinaxis();
}
/////////////////////////////////////////////////////////////////
float cosvec(const VectorXY& v1, const VectorXY& v2)
{
    return v1.cosaxis() * v2.cosaxis() + v1.sinaxis() * v2.sinaxis();
}
/////////////////////////////////////////////////////////////////
float tgvec(const VectorXY& v1, const VectorXY& v2)
{
    return sinvec(v1, v2) / cosvec(v1, v2);
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::ortho() const
{
    return VectorXY(y, -x);
}
/////////////////////////////////////////////////////////////////
float VectorXY::squarelen() const
{
    return len() * len();
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::operator-() const
{
    return VectorXY(-x, -y);
}
/////////////////////////////////////////////////////////////////
void VectorXY::rotatevec(float angle)
{
    float x1 = x;
    x = x * cos(angle) - y * sin(angle);
    y = x1 * sin(angle) + y * cos(angle);
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::getrotated(float angle) const
{
    return VectorXY(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}
