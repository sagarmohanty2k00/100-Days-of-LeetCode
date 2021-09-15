#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> temps;
    for (int i=0; i<n; i++) {
        int t;
        cin >> t;

        temps.push_back(t);
    }

    for (int i=0; i<n; i++) {
        if (temps[i] < l and temps[i] > r) cout << temps[i] << " ";
    }

    cout << endl;
}