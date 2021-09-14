#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int arr[n+1];
        memset(arr, -1, sizeof(arr));
        arr[1] = 1;
        for (int i=2; i<=n; i++) {
            if (arr[i] != -1) continue;
            
            arr[i] = INT_MAX;
            
            for (int j = 1; j*j <= i; j++) {
                arr[i] = 
                    min(arr[i], arr[i - j*j] + 1);
            }
            
            int sq = i*i;
            while (sq <= n) {
                if (sq == n) return 1;
                arr[sq] = 1;
                sq *= sq;
            }
        }
        
        
        return arr[n];
    }
};

int main() {
    Solution ob;
    int n;
    cin >> n;

    cout << ob.numSquares(n) << endl;
}