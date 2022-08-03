#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    size_t N;
    int T;
    cin >> N >> T;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    // 部分最小値
    vector<int> partial_min_A(N, A.at(0UL));
    for (size_t i = 1UL; i < N; i++) {
        if (A.at(i) <= partial_min_A.at(i - 1UL)) {
            partial_min_A.at(i) = A.at(i);
        } else {
            partial_min_A.at(i) = partial_min_A.at(i - 1UL);
        }
    }

    // りんご１個あたりの最大利益
    int max_profit_per_apple = 0;
    for (size_t i = 1UL; i < N; i++) {
        int current_town_profit = A.at(i) - partial_min_A.at(i - 1UL);
        max_profit_per_apple = max(max_profit_per_apple, current_town_profit);
    }

    // りんご１個あたりの利益が最大となる組み合わせの数
    int ans = 0;
    for (size_t i = 1UL; i < N; i++) {
        int current_town_profit = A.at(i) - partial_min_A.at(i - 1UL);
        if (max_profit_per_apple == current_town_profit) ++ans;
    }

    // 出力
    cout << ans << "\n";

    return 0;
}
