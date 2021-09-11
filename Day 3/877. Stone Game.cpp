#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};


int main() {
    int n;
    cin >> n;

    vector<int> piles;
    for (int i=0; i<n; i++) {
        int val;
        cin >> val;

        piles.push_back(val);
    }
    Solution ob;
    if (ob.stoneGame(piles)) cout << "Alice Wins." << endl;
    else cout << "Bob wins." << endl;
}