#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_map<int, vector<vector<int>>> memo;
        memo[0].push_back({});

        for (int x : candidates) {
            if (x <= target) {
                for (int i=0; i<=target-x; i++) {
                    if (memo.find(i) != memo.end()) {
                        for (auto tempArr : memo[i]) {
                            tempArr.push_back(x);
                            memo[x+i].push_back(tempArr);
                        }
                    }
                }
            }
        }

        if (memo.find(target) != memo.end()) return memo[target];

        return {};
    }
};

int main() {
    int size;
    cin >> size;

    vector<int> nums;
    for (int i=0; i<size; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int target;
    cin >> target;

    Solution ob;
    vector<vector<int>> combinations = ob.combinationSum(nums, target);

    if (combinations.size() != 0) {
        for (auto combination : combinations) {
            for (int val : combination) {
                cout << val << " ";
            }cout << endl;
        }
   }
   else cout << "[]" << endl;
}