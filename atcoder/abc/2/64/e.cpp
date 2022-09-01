#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (size_t i = 0UL; i < (n); i++)
#define REP1(i, n) for (size_t i = 1UL; i < (n); i++)

using PowerLine = pair<uint, uint>;

struct Place {
    bool is_electrified;
    uint maybe_plant_id;
    uint suplyees_count;

    Place() {}
    Place(const uint &_id) {
        is_electrified = false;
        maybe_plant_id = _id;
        suplyees_count = 1;
    }
};

bool is_plant(const uint &place_id) { return !place_id; }
bool is_city(const uint &place_id) { return place_id; }

class UnionFind {
    vector<Place> places;
    uint erectrified_cities_count;

   public:
    UnionFind(const uint &N) {
        places.resize(N + 1);
        REP(i, N + 1) places[i] = i;
        places[0].is_electrified = true;
        places[0].suplyees_count = 0;
        erectrified_cities_count = 0;
    }

    bool unite(const PowerLine &p) {
        const auto [p1, p2] = make_pair(find(p.first), find(p.second));
        if (p1 == p2) return false;

        uint maybe_plant = min(p1, p2);
        uint maybe_city = max(p1, p2);
        if (is_city(maybe_plant)) {
            uint hub_city = maybe_plant;
            uint sub_city = maybe_city;
            if (places[hub_city].suplyees_count <
                places[sub_city].suplyees_count)
                swap(hub_city, sub_city);

            places[sub_city].maybe_plant_id = hub_city;
            places[hub_city].suplyees_count += places[sub_city].suplyees_count;
        }
        if (is_plant(maybe_plant)) {
            erectrified_cities_count += places[maybe_city].suplyees_count;
            places[maybe_city].maybe_plant_id = maybe_plant;
            places[maybe_plant].suplyees_count +=
                places[maybe_city].suplyees_count;
        }
        return true;
    }

    [[nodiscard]] uint find(const uint &place_id) {
        if (places[place_id].maybe_plant_id == place_id) return place_id;
        return (places[place_id].maybe_plant_id =
                    find(places[place_id].maybe_plant_id));
    }

    [[nodiscard]] uint get_erectrified_cities_cout(void) {
        return erectrified_cities_count;
    }
};

int main() {
    // inputs
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint N, M, E;
    cin >> N >> M >> E;

    vector<PowerLine> UV(E);
    for (auto &[Ui, Vi] : UV) {
        cin >> Ui >> Vi;
        if (Ui > N) Ui = 0;
        if (Vi > N) Vi = 0;
    }

    uint Q;
    cin >> Q;
    vector<uint> X(Q);
    for (uint &Xi : X) {
        cin >> Xi;
        --Xi;
    }

    // solve
    vector<bool> is_servive(E, true);
    for (const uint &Xi : X) is_servive[Xi] = false;

    UnionFind country(N);
    REP(i, E) {
        if (is_servive[i]) country.unite(UV[i]);
    }

    vector<uint> electrified_city_count_after_X(Q);
    for (int i = Q - 1; i >= 0; i--) {
        electrified_city_count_after_X[i] =
            country.get_erectrified_cities_cout();
        country.unite(UV[X[i]]);
    }

    for (const uint &c : electrified_city_count_after_X) {
        cout << c << '\n';
    }

    return 0;
}
