#include <stdio.h>

long long ans(long long n)
{
    if (n == 0)
        return (long long)1;
    return n * ans(n - 1);
}

int main()
{
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", ans(n));
    return 0;
}