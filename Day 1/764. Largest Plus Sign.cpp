#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        // Initialize the field array
        vector<vector<vector<int>>> memo;
        for (int i=0; i<n; i++) {
            memo.push_back({});
            for (int j=0; j<n; j++) {
                memo[i].push_back({-1, -1, -1, -1});
            }
        }

        // mark the mines
        for (auto x : mines) {
            memo[x[0]][x[1]] = {0, 0, 0, 0};
        }

        // mark top-left
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (memo[i][j][0] == 0) {
                    continue;
                }

                if (i == 0) {
                    memo[i][j][1] = 1;
                }
                else {
                    memo[i][j][1] = memo[i-1][j][1] + 1;
                }

                if (j == 0) {
                    memo[i][j][0] = 1;
                }
                else {
                    memo[i][j][0] = memo[i][j-1][0] + 1;
                }
            }
        }

        // mark bottom-right
        for (int i=n-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                if (memo[i][j][0] == 0) {
                    continue;
                }

                if (i == n-1) {
                    memo[i][j][2] = 1;
                }
                else {
                    memo[i][j][2] = memo[i+1][j][2] + 1;
                }

                if (j == n-1) {
                    memo[i][j][3] = 1;
                }
                else {
                    memo[i][j][3] = memo[i][j+1][3] + 1;
                }
            }
        }

        // calculate the largest + possible
        int largestPlus = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                largestPlus = max(
                    largestPlus, min(
                        memo[i][j][0], min(
                            memo[i][j][1], min(
                                memo[i][j][2], memo[i][j][3]
                            )
                        )
                    )
                );
            }
        }

        return largestPlus;
    }
};

int main() {
    Solution ob;
    int n;
    cin >> n;

    vector<vector<int>> mines;
    int m; cin >> m;

    for (int i=0; i<m; i++) {
        int r, c;
        cin >> r >> c;


        mines.push_back({r, c});
    }

    cout << ob.orderOfLargestPlusSign(n, mines);
}