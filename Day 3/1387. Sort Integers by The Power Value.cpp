#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
class Solution {
public:
    int convert_to_1(int num, unordered_map<int, int> &memo) {
        if (num == 1) {
            return 1;
        }
        
        if (num%2 == 0)
            memo[num] = 1 + convert_to_1(num/2, memo);
        else 
            memo[num] = 1 + convert_to_1(3*num + 1, memo);
        
        return memo[num];
    }
    int getKth(int lo, int hi, int k) {
        
        unordered_map<int, int> memo;
        vector<pair<int, int>> arr;
        for (int i=lo; i<=hi; i++) {
            if (memo.find(i) == memo.end()) {
                if (i%2 == 0)
                    memo[i] = 1 + convert_to_1(i/2, memo);
                else 
                    memo[i] = 1 + convert_to_1(3*i + 1, memo);
            }
            
            arr.push_back({i, memo[i]});
        }
        
        
        sort(arr.begin(), arr.end(), comp);
        
        return arr[k-1].first;
    }
};

int main() {
    int lo, hi, k;
    cin >> lo >> hi >> k;

    Solution ob;
    cout << ob.getKth(lo, hi, k) << endl;
}