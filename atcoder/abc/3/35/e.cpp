#include <bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define SORT(v) std::ranges::sort(v)

#define REP(i, n)  for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i <= (n); i++)

struct Node {
    // A[v] <= A[children[i]]
    unsigned v;
    set<unsigned> children;
    Node(unsigned V) : v(V){};
};

struct NiceTree {
    // root = vertex[0]
    vector<Node> vertex;

    NiceTree(unsigned N) { REP(i, N) vertex.push_back(Node(i)); }
};

// root(=0) から goal(=N-1) に到達するときの頂点数(A[i]が同じやつは同一視)
unsigned solve(const NiceTree& nt) { unsigned ans = 1U; }

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    unsigned N, M;
    cin >> N >> M;
    vector<unsigned> A(N);
    for (unsigned& Ai : A) cin >> Ai;

    NiceTree nt(N);
    REP(i, M) {
        unsigned U, V;
        cin >> U >> V;
        U--, V--;
        if (A[0] > A[U] || A[0] > A[V]) continue;
        if (A[U] > A[V]) swap(U, V);
        nt.vertex[U].children.insert(V);
        if (A[U] == A[V]) nt.vertex[V].children.insert(U);
    }

    cout << solve(nt) << '\n';

    return 0;
}
