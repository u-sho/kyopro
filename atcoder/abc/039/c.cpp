#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

const string Do = "WBWBWWBWBWBWWBWBWWBW";
const string Re = "WBWWBWBWBWWBWBWWBWBW";
const string Mi = "WWBWBWBWWBWBWWBWBWBW";
const string Fa = "WBWBWBWWBWBWWBWBWBWW";
const string So = "WBWBWWBWBWWBWBWBWWBW";
const string La = "WBWWBWBWWBWBWBWWBWBW";
const string Si = "WWBWBWWBWBWBWWBWBWWB";

int main() {
    string S;
    cin >> S;

    if (S == Do) cout << "Do\n";
    if (S == Re) cout << "Re\n";
    if (S == Mi) cout << "Mi\n";
    if (S == Fa) cout << "Fa\n";
    if (S == So) cout << "So\n";
    if (S == La) cout << "La\n";
    if (S == Si) cout << "Si\n";

    return 0;
}