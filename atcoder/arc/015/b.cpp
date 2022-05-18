#include <iostream>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int 猛暑日 = 0, 真夏日 = 0, 夏日 = 0, 真冬日 = 0;
    int 冬日 = 0, 熱帯夜 = 0;
    for (int i = 0; i < N; i++) {
        double MT, mT;
        cin >> MT >> mT;
        if (MT >= 35.0)
            ++猛暑日;
        else if (MT >= 30.0)
            ++真夏日;
        else if (MT >= 25.0)
            ++夏日;
        else if (MT < 0.0)
            ++真冬日;

        if (MT >= 0.0 && mT < 0.0) ++冬日;
        if (mT >= 25.0) ++熱帯夜;
    }

    cout << 猛暑日 << " " << 真夏日 << " " << 夏日 << " ";
    cout << 熱帯夜 << " " << 冬日 << " " << 真冬日 << "\n";

    return 0;
}
