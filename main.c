#include <stdio.h>
#include "calculator.h"

int main(void) {
    double a = 10.0;
    double b = 3.0;

    printf("%.1f + %.1f = %.1f\n", a, b, add(a, b));
    printf("%.1f - %.1f = %.1f\n", a, b, subtract(a, b));
    printf("%.1f * %.1f = %.1f\n", a, b, multiply(a, b));
    printf("%.1f / %.1f = %.1f\n", a, b, divide(a, b));

    return 0;
}
