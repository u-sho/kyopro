#include <iostream>
using namespace std;

using X = pair<uint, uint>;
using Y = pair<uint, uint>;
using Z = pair<uint, uint>;

struct Cuboid {
    X x;
    Y y;
    Z z;
    Cuboid(const uint &a, const uint &b, const uint &c, const uint &d,
           const uint &e, const uint &f)
        : x({a, d}), y({b, e}), z({c, f}) {}
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint a, b, c, d, e, f;
    uint g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    const Cuboid c1(a, b, c, d, e, f);
    const Cuboid c2(g, h, i, j, k, l);

    bool hasIntersection = true;
    if (c1.x.second <= c2.x.first) hasIntersection = false;
    if (c1.x.first >= c2.x.second) hasIntersection = false;
    if (c1.y.second <= c2.y.first) hasIntersection = false;
    if (c1.y.first >= c2.y.second) hasIntersection = false;
    if (c1.z.second <= c2.z.first) hasIntersection = false;
    if (c1.z.first >= c2.z.second) hasIntersection = false;

    cout << (hasIntersection ? "Yes\n" : "No\n");
    return 0;
}
