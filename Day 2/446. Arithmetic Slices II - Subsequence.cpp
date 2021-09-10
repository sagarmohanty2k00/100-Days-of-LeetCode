#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) {
            return 0;
        }
        
        int total = 0;
        vector<unordered_map<long long int,int>> dp(nums.size());
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                long long int dif = (long)nums[i] - (long)nums[j];
                dp[i][dif] += 1;

                if(dp[j].find(dif) != dp[j].end())
                {
                    dp[i][dif] += dp[j][dif];
                    total += dp[j][dif];
                }
            }
        }
        
        return total;
    }
};

int main() {
    int t;
    cin >> t;

    Solution ob;

    while(t--) {
        int n;
        cin n;

        vector<int> nums;
        while (n--) {
            int val;
            cin >> val;

            nums.push_back(val);
        }
        cout << ob.numberOfArithmeticSlices(nums) << endl;
    }
}