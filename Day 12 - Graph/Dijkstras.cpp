#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, list<int>> g;
    g[0] = {1,2,3};
    g[1] = {2, 3};
    g[4] = {2};   
    topSort(g); // 4 3 2 1 2
}