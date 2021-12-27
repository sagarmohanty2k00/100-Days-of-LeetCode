#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, list<int>> &g) {
    queue<int> q;
    unordered_set<int> s;

    for (auto x : g) {
        if (s.find(x.first) != )
    }
}

void dfs(unordered_map<int, list<int>> &g, unordered_set<int> &visited) {
    // 
}

int main() {
    unordered_map<int, list<int>> g;
    
    int to;
    int from;
    bool bi;

    int choice;

    while(1) {
        cout << "1. add edge\n"
             << "2. bfs\n"
             << "3. dfs\n" << endl;
        cout << "Choice : ";

        cin >> choice;

        switch(choice) {
            case 1 : cin >> to >> from >> bi;
                     g[to].push_back(from);
                     break;

            case 2 : bfs(g);
                     break;

            case 3 : dfs(g);
                     break;

            default : cout << "Wrong option" << endl;
        }
    }
}