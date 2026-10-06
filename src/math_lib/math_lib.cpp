#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;        
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
		if (b == 0) return a;
		return GCD(b, a % b);
	}
    // Function for solving quadratic equation ax^2 + bx + c = 0
    std::vector<double> solveQuadratic(double a, double b, double c)
    {
        if (a == 0)
        {
            throw std::invalid_argument(
                "Coefficient a cannot be zero in a quadratic equation."
            );
        }

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
        {
            return {};
        }

        if (discriminant == 0)
        {
            return { -b / (2 * a) };
        }

        double sqrtDiscriminant = std::sqrt(discriminant);

        double x1 = (-b + sqrtDiscriminant) / (2 * a);
        double x2 = (-b - sqrtDiscriminant) / (2 * a);

        return { x1, x2 };
    }
}

