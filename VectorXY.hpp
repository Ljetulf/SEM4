#include <iostream>
#include <math.h>
#pragma once
/////////////////////////////////////////////////////////////////
class VectorXY
{
    private:
        float x, y;
    public:
        VectorXY(float a, float b);
        explicit VectorXY(const VectorXY& other);//constructor of copying
        VectorXY();
        ~VectorXY();
        std::ostream& operator<<(std::ostream& stream, const VectorXY& v);
        std::istream& operator>>(std::istream& stream, VectorXY& v);
        VectorXY& operator=(const VectorXY& other);
        VectorXY operator+(const VectorXY& other) const;
        VectorXY& operator+=(const VectorXY& other);
        VectorXY operator-(const VectorXY& other) const;
        VectorXY& operator-=(const VectorXY& other);
        float operator*(const VectorXY& other) const;//scalar multiply
        VectorXY operator*(float a) const;//multiply on number
        VectorXY operator*(float a, const VectorXY& v);//multiply on number
        VectorXY operator/(float a) const;//divide on number
        float len() const;
        VectorXY norm() const;
        float operator^(const VectorXY& other) const;//vector multiply
        float sinaxis() const;
        float cosaxis() const;
        float tgaxis() const;
        float sinvec(const VectorXY& v) const;
        float cosvec(const VectorXY& v) const;
        float tgvec(const VectorXY& v) const;
        VectorXY ortho() const;
        float squarelen() const;
        VectorXY operator-() const;
        void rotatevec(float angle);
        VectorXY getrotated(float angle) const;
};
/////////////////////////////////////////////////////////////////
VectorXY::VectorXY(float a, float b)
{
    x = a;
    y = b;
    return *this;
}
/////////////////////////////////////////////////////////////////
explicit VectorXY::VectorXY(const VectorXY& other)
{
    x = other.x;
    y = other.y;
    return *this;
}
/////////////////////////////////////////////////////////////////
VectorXY::VectorXY()
{
    x = 0;
    y = 0;
    return *this;
}
/////////////////////////////////////////////////////////////////
VectorXY::~VectorXY(){}
/////////////////////////////////////////////////////////////////
std::ostream& VectorXY::operator<<(std::ostream& stream, const VectorXY& v)
{
    stream << v.x << " " << v.y;
    return stream;
}
/////////////////////////////////////////////////////////////////
std::istream& VectorXY::operator>>(std::istream& stream, VectorXY& v)
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
VectorXY VectorXY::operator*(float a, const VectorXY& v)
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
float VectorXY::sinvec(const VectorXY& v) const
{
    return sinaxis() * v.cosaxis() - cosaxis() * v.sinaxis();
}
/////////////////////////////////////////////////////////////////
float VectorXY::cosvec(const VectorXY& v) const
{
    return cosaxis() * v.cosaxis() + sinaxis() * v.sinaxis();
}
/////////////////////////////////////////////////////////////////
float VectorXY::tgvec(const VectorXY& v) const
{
    return sinvec(v) / cosvec(v);
}
/////////////////////////////////////////////////////////////////
VectorXY VectorXY::ortho() const
{
    return VectorXY(y, -x);
}
/////////////////////////////////////////////////////////////////
float squarelen() const
{
    return len() * len();
}
/////////////////////////////////////////////////////////////////
VectorXY operator-() const
{
    return VectorXY(-x, -y);
}
/////////////////////////////////////////////////////////////////
void rotatevec(float angle)
{
    float x1 = x;
    x = x * cos(angle) - y * sin(angle);
    y = x1 * sin(angle) + y * cos(angle);
}
/////////////////////////////////////////////////////////////////
VectorXY getrotated(float angle) const
{
    return VectorXY(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
}
