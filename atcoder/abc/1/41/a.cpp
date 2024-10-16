#include <bits/stdc++.h>
using namespace std;
int i;
string S[4] = {
    "Sunny",
    "Cloudy",
    "Rainy",
};
int main() {
    cin >> S[3];
    for (; i < 3;)
        if (S[i++] == S[3]) cout << S[i % 3];
}
