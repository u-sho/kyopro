#include <stdio.h>
int main(void) {
    long long a, bf, bb;
    scanf("%lld %lld.%lld", &a, &bf, &bb);

    long long ans = (a * (bf * 100LL + bb)) / 100LL;

    printf("%lld\n", ans);

    return 0;
}