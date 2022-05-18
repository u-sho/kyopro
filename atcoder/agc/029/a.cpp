#include <ios>
// #import
long b, a;
char S[200005];
main() {
    scanf("%s", S);
    // 'W'%2==1, 'B'%2==0
    for (char c : S) c % 2 ? a += b : b++;
    printf("%ld", a);
}