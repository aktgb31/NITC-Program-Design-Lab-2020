#include <stdio.h>
#include <math.h>

//function to calculate gcd
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0 && b == 0)
    {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", gcd(fabs(a), fabs(b)));
}