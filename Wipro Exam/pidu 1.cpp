#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cin >> n >> k;

    int items[n];
    for (int i=0; i<n; i++) {
        cin >> items[i];
    }
    
    if (k > items[n-1]) {
        cout << n << endl;
        return 0;
    }

    cout << lower_bound(items, items + n, k) - items << endl;

    return 0;
}