#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = LONG_LONG_MAX;

struct Edge {
    ll u, v, goldCost, silverCost;
};

ll n, m, goldMultiplier, silverMultiplier;
vector<Edge> edges;
vector<ll> edgeIndices, mstEdgeIndices;

vector<ll> parent;

ll findSet(ll city) {
    if (parent[city] == city) {
        return city;
    }
    return parent[city] = findSet(parent[city]);
}

void kruskal(ll &maxSilverCost) {
    parent.resize(n + 1);
    for (ll i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    maxSilverCost = 0;
    ll edgeCount = 0;

    sort(edgeIndices.begin(), edgeIndices.end(), [&](ll a, ll b) {
        return edges[a].silverCost < edges[b].silverCost;
    });

    mstEdgeIndices.clear();

    for (auto idx : edgeIndices) {
        ll u = edges[idx].u;
        ll v = edges[idx].v;

        if (findSet(u) != findSet(v)) {
            maxSilverCost = max(maxSilverCost, edges[idx].silverCost);
            parent[findSet(u)] = findSet(v);
            ++edgeCount;
            mstEdgeIndices.push_back(idx);
        }
    }

    if (edgeCount < n - 1) {
        maxSilverCost = INF;
    }
    swap(edgeIndices, mstEdgeIndices);
}

int main() {
    cin >> n >> m >> goldMultiplier >> silverMultiplier;
    edges.resize(m);

    for (ll i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].goldCost >> edges[i].silverCost;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.goldCost < b.goldCost;
    });

    ll minCost = INF;

    for (ll i = 0; i < m; ++i) {
        edgeIndices.push_back(i);
        ll maxSilverCost = INF;

        kruskal(maxSilverCost);

        if (maxSilverCost != INF) {
            ll totalCost = maxSilverCost * silverMultiplier + edges[i].goldCost * goldMultiplier;
            minCost = min(minCost, totalCost);
        }
    }

    if (minCost == INF) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}
