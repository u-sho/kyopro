#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> B_tree(21);
std::vector<int> salary(21);

int get_salary(std::size_t i) {
    if (salary.at(i)) return salary.at(i);
    if (B_tree.at(i).empty()) {
        salary.at(i) = 1;
        return 1;
    }

    int max_salary = -100000000;
    int min_salary = 1000000000;
    for (const int b : B_tree.at(i)) {
        max_salary = std::max(max_salary, get_salary(b));
        min_salary = std::min(min_salary, get_salary(b));
    }
    return max_salary + min_salary + 1;
}

int main(void) {
    std::cin >> N;
    for (int i = 2; i <= N; ++i) {
        int bi;
        std::cin >> bi;
        B_tree.at(bi).push_back(i);
    }

    std::cout << get_salary(1) << '\n';

    return 0;
}