#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat;

    for (int i=0; i<n; i++) {
        mat.push_back({});
        for (int j=0; j<=i; j++) {
            if (j == 0 or j == i) {
                mat[i].push_back(1);
            }else {
                mat[i].push_back(mat[i-1][j-1] + mat[i-1][j]);
            }
        }
    }

    for (auto row : mat) {
        for (int i : row) {
            cout << i << " ";
        }cout << endl;
    }

    return 0;
}