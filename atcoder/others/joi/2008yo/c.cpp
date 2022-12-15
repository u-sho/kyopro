#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef enum {
    Taro_hand,
    Hanako_hand,
    Field,
} Card;

unsigned n;
vector<Card> cards(202u, Hanako_hand);

unsigned current = 0u;
unsigned taro_points;
unsigned hanako_points;

bool play_taro() {
    for (unsigned i = current + 1u; i <= 2u * n; i++) {
        if (cards.at(i) == Taro_hand) {
            cards[i] = Field;
            current = i;
            --hanako_points;
            return hanako_points;
        }
    }
    current = 0u;
    return true;
}

bool play_hanako() {
    for (unsigned i = current + 1u; i <= 2u * n; i++) {
        if (cards.at(i) == Hanako_hand) {
            cards[i] = Field;
            current = i;
            --taro_points;
            return taro_points;
        }
    }
    current = 0u;
    return true;
}

int main(void) {
    cin >> n;
    taro_points = hanako_points = n;
    for (unsigned i = 0u; i < n; i++) {
        unsigned taro_hand;
        cin >> taro_hand;
        cards.at(taro_hand) = Taro_hand;
    }

    do {
        if (!play_taro()) break;
    } while (play_hanako());

    cout << taro_points << '\n';
    cout << hanako_points << '\n';

    return 0;
}