#include <iostream>
#pragma once
/////////////////////////////////////////////////////////////////
class VectorXY
{
    public:
        VectorXY(float a, float b);
        VectorXY(const VectorXY& other);//constructor of copying
        VectorXY();
        ~VectorXY();
        VectorXY& operator=(const VectorXY& other);
        VectorXY operator+(const VectorXY& other) const;
        VectorXY& operator+=(const VectorXY& other);
        VectorXY operator-(const VectorXY& other) const;
        VectorXY& operator-=(const VectorXY& other);
        float operator*(const VectorXY& other) const;//scalar multiply
        VectorXY operator*(float a) const;//multiply on number
        VectorXY operator/(float a) const;//divide on number
        float len() const;
        VectorXY norm() const;
        float operator^(const VectorXY& other) const;//vector multiply
        float sinaxis() const;
        float cosaxis() const;
        float tgaxis() const;
        VectorXY ortho() const;
        float squarelen() const;
        VectorXY operator-() const;
        void rotatevec(float angle);
        VectorXY getrotated(float angle) const;
        float x, y;
};
/////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& stream, const VectorXY& v);
std::istream& operator>>(std::istream& stream, VectorXY& v);
VectorXY operator*(float a, const VectorXY& v);//multiply on number
float sinvec(const VectorXY& v1, const VectorXY& v2);
float cosvec(const VectorXY& v1, const VectorXY& v2);
float tgvec(const VectorXY& v1, const VectorXY& v2);
/////////////////////////////////////////////////////////////////
