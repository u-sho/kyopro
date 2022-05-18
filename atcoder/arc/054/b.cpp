#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

// double型は15桁くらい安全だった気がする
// constexpr double EPS = std::numeric_limits<double>::epsilon();
// 許容相対誤差
constexpr double EPS = 1e-9;

bool is_valid(double x, double greater_x) {
    if (x == greater_x) return true;

    // 許容絶対誤差
    double abs_err = x * EPS;

    return greater_x - x < abs_err;
}

double f(double x, double P) { return x + P / pow(2.0, 2 * x / 3.0); }

int main() {
    std::cout << std::fixed << std::setprecision(10);

    double P;
    std::cin >> P;

    double l = 0.0;
    // double r  = 90.1855078128;
    double r = 100.0;

    for (int cnt = 0; cnt < 5'000'000; ++cnt) {
        double cl = (2.0 * l + r) / 3.0;
        double cr = (l + 2.0 * r) / 3.0;

        double l_time  = f(l, P);
        double cl_time = f(cl, P);
        double cr_time = f(cr, P);
        double r_time  = f(r, P);

        if (l_time < cl_time) {
            if (is_valid(l_time, cl_time)) {
                std::cout << l_time << '\n';
                return 0;
            }
            r = cl;
            continue;
        }

        if (cl_time < cr_time) {
            if (is_valid(cl_time, cr_time)) {
                std::cout << cl_time << '\n';
                return 0;
            }
            r = cr;
            continue;
        }

        if (cr_time < r_time) {
            if (is_valid(cr_time, r_time)) {
                std::cout << cr_time << '\n';
                return 0;
            }
            l = cl;
            continue;
        }

        if (is_valid(r_time, cr_time)) {
            std::cout << r_time << '\n';
            return 0;
        }
        l = cr;
    }

    return 1;
}
