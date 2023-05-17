#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    double side_a;
    double side_b;
    double side_c;

    printf("Enter Side of A: ");
    scanf("%lf", &side_a);

    printf("Enter Side of B: ");
    scanf("%lf", &side_b);

    side_c = sqrt(side_a * side_a + side_b * side_b);
    printf("Side of C: %lf", side_c);

    return 0;
}
