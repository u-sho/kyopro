#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using lli = long long;
using ulli = unsigned long long;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REPi(j, i, n) for (size_t j = (i); j < (n); j++)

struct UnionFind {
    vector<ulli> parent;
    vector<ulli> size;

    UnionFind(ulli sz) {
        REP(i, sz) parent.push_back(i);
        size.assign(sz, 1ULL);
    }

    bool unite(const ulli x, const ulli y) {
        lli xr = find(x);
        lli yr = find(y);
        if (xr == yr) return false;

        if (size[xr] > size[yr]) swap(xr, yr);
        parent[xr] = parent[yr];
        size[yr] += size[xr];
        // cout << "unite:" << x << " " << y << "\n";
        return true;
    }

    ulli find(const ulli k) {
        if (parent[k] == k) return k;
        return find(parent[k] = parent[parent[k]]);
    }
};

using point = pair<lli, lli>;
using circle = pair<point, ulli>;

template <typename T>
ulli abs_square(T x) {
    if (x < 0) return (ulli(-x) * ulli(-x));
    return (ulli(x) * ulli(x));
}

ulli distance_square(const point &p1, const point &p2) {
    return (abs_square(p1.first - p2.first) +
            abs_square(p1.second - p2.second));
}

bool has_crosspoint(const circle &c1, const circle &c2) {
    ulli d = distance_square(c1.first, c2.first);
    ulli r_plus_R = abs_square(c1.second + c2.second);
    ulli r_minus_R = abs_square(c1.second - c2.second);
    return (r_minus_R <= d && d <= r_plus_R);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ulli N;
    cin >> N;

    point s, t;
    cin >> s.first >> s.second >> t.first >> t.second;

    vector<circle> circles;
    REP(i, N) {
        lli x, y, r;
        cin >> x >> y >> r;
        circles.push_back({{x, y}, r});
    }

    // solves
    UnionFind uf((N + 2ULL));  // N: s, N+1: t
    REP(i, N) {
        if (distance_square(s, circles[i].first) ==
            abs_square(circles[i].second)) {
            uf.unite(i, N);
        }
        if (distance_square(t, circles[i].first) ==
            abs_square(circles[i].second)) {
            uf.unite(i, N + 1);
        }
        REPi(j, i + 1UL, N) {
            if (has_crosspoint(circles[i], circles[j])) {
                uf.unite(i, j);
            }
        }
    }

    bool ok = !(uf.unite(N, N + 1));
    cout << (ok ? "Yes\n" : "No\n");

    return 0;
}
