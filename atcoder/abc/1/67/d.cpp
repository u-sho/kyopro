#include <iostream>
#include <vector>
using namespace std;
using lli = long long;

int main() {
    size_t N;
    lli K;
    cin >> N >> K;
    vector<int> A(N);
    for (int &Ai : A) cin >> Ai;

    vector<lli> visited_town_count(N + 1UL, 0LL);

    size_t i      = 0UL;
    bool repeated = false;
    for (lli visited = 1LL; visited <= K; visited++) {
        if (visited_town_count.at(A.at(i)) == 0LL) {
            visited_town_count.at(A.at(i)) = visited;
        } else if (!repeated) {
            lli repetition = visited - visited_town_count.at(A.at(i));
            visited += ((K - visited) / repetition) * repetition;
            repeated = true;
        }
        i = A.at(i) - 1;
    }

    cout << i + 1UL << "\n";

    return 0;
}
