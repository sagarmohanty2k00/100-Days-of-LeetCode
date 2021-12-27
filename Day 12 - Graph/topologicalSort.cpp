#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &g, unordered_set<int> &visited) {
    visited.insert(node);

    for (int x : g[node]) {
        if (visited.find(x) == visited.end()) dfs(x, g, visited);
    }

    cout << node << " ";
}

void topSort(unordered_map<int, list<int>> &g) {
    unordered_set<int> visited;
    for (auto x : g) {
        if (visited.find(x.first) == visited.end())
            dfs(x.first, g, visited);
    }
}

int main() {
    unordered_map<int, list<int>> g;
    g[0] = {1,2,3};
    g[1] = {2, 3};
    g[4] = {2};   
    topSort(g); // 4 3 2 1 2
}