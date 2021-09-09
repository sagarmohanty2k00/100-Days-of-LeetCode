#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<vector<int>> dfs(int i, vector<vector<int>>& graph, unordered_map<int, vector<vector<int>>> &memo) {
        vector<vector<int>> paths;
        if (memo.find(i) != memo.end()) {
            return memo[i];
        }
        
        if (i == graph.size()-1) {
            paths.push_back({i});
            return paths;
        }
        
        if (graph[i].size() == 0 and i < graph.size()-1) {
            paths.push_back({});
            return paths;
        }
        
        for (int node : graph[i]) {
            vector<vector<int>> temp = dfs(node, graph, memo);
            for (auto x : temp) {
                if (x.size() != 0) {
                    x.push_back(i);
                    paths.push_back(x);
                }
            }
        }

        return memo[i] = paths;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        unordered_map<int, vector<vector<int>>> memo;
        
        if (graph.size() < 2) {
            return graph;
        }
        
        paths = dfs(0, graph, memo);
        for (int i=0; i<paths.size(); i++) {
            reverse(paths[i].begin(), paths[i].end());
        }


        return paths;
    }
};

// Driver Code.
int main() {
    int t;
    cout << "no of test cases : ";
    cin >> t;

    Solution ob;

    while (t--) {
        int n;

        cout << "no of nodes : ";
        cin >> n;

        vector<vector<int>> graph;
        for (int i=0; i<n; i++) {
            graph.push_back({});
            int routs;

            cout << "no of routs from node " << i << " : "; 
            cin >> routs;

            for (int r=0; r<routs; r++) {
                int rout;
                cin >> rout;

                graph[i].push_back(rout);
            }
        }


        vector<vector<int>> all_paths = ob.allPathsSourceTarget(graph);
        cout << "ALL PATHS : " << endl;
        for (auto x : all_paths) {
            for (int a : x) {
                cout << a << " ";
            }cout << endl;
        }
    }
}