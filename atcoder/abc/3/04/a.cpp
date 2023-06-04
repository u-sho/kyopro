#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

unsigned argmin(const std::vector<std::pair<std::string, unsigned>> &SA) {
    unsigned min_A    = UINT32_MAX;
    unsigned argmin_A = SA.size();
    for (unsigned i = 0; i < SA.size(); i++) {
        if (SA[i].second < min_A) {
            min_A    = SA[i].second;
            argmin_A = i;
        }
    }
    return argmin_A;
}
int main(void) {
    using namespace std;
    unsigned N;
    cin >> N;
    vector<pair<string, unsigned>> SA(N);
    for (auto &SAi : SA) cin >> SAi.first >> SAi.second;

    unsigned argmin_A = argmin(SA);
    for (unsigned i = 0; i < N; i++) {
        if (argmin_A + i < N) cout << SA[argmin_A + i].first << '\n';
        else cout << SA[argmin_A + i - N].first << '\n';
    }
}