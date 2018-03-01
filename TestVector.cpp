#include "VectorXY.hpp"
#include <iostream>
#define M_PI 3.14159265358979323846

int main()
{
    VectorXY v0;
    VectorXY v1(2.0, 4.0);
    VectorXY v2;
    v2 = v1 / 2;
    std::cout << v0 << "\n" << v1 << "\n" << v2 << "\n";
    std::cin >> v0;
    std::cout << v0 << "\n";
    v0 = v1 + v2;
    std::cout << v0 << "\n";
    v0 -= v1;
    std::cout << v0 << "\n";
    v0 += v1;
    std::cout << v0 << "\n";
    v0 = v1 - v2;
    std::cout << v0 << "\n";
    v0 = v2 * 3;
    std::cout << v0 << "\n";
    v0 = 5 * v2 / 3;
    std::cout << v0 << "\n";
    std::cout << v1 * v2 << "\n";
    float a = v1 ^ v2;
    std::cout << a << "\n";
    std::cout << v1.norm() << "\n";
    std::cout << v1.len() << "\n";
    std::cout << v2.sinaxis() << "\n";
    std::cout << v2.cosaxis() << "\n";
    std::cout << v2.tgaxis() << "\n";
    std::cout << sinvec(v1,v2) << "\n";
    std::cout << cosvec(v1,v2) << "\n";
    std::cout << tgvec(v1,v2) << "\n";
    std::cout << v1.ortho() << "\n";
    std::cout << v1.squarelen() << "\n";
    std::cout << -v1 << "\n";
    v1.rotatevec(M_PI / 2);
    std::cout << v1 << "\n";
    std::cout << v1.getrotated(M_PI / 2) << "\n";
    return 0;
}
