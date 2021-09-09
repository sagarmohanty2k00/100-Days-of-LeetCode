#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // functional logic
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i=0; i<n-2; i++) {
            if (i == 0 or (i > 0 and nums[i] != nums[i-1])) {
                int start = i+1;
                int end = n-1;
                int target = 0 - nums[i];

                while (start < end) {
                    if (nums[start] + nums[end] == target) {
                        ans.push_back({nums[i], nums[start], nums[end]});

                        while(nums[start] == nums[start+1] and start + 1 < end) start++;
                        while(nums[end] == nums[end-1] and start + 1 < end) end--;

                        start++;
                        end--;
                    }

                    else if (nums[start] + nums[end] > target) {
                        end--;
                    }

                    else {
                        start++;
                    }
                }
            }
        }


        return ans;
    }
};

// Driver Code.
int main() {
    int t;

    cout << "no of testcases : ";
    cin >> t;

    Solution ob;

    while (t--){
        int n;

        cout << "size array : ";
        cin >> n;

        vector<int> nums;
        for (int i=0; i<n; i++) {
            int val;
            cin >> val;

            nums.push_back(val);
        }

        vector<vector<int>> arr = ob.threeSum(nums);

        cout << "triplates : ";
        for (auto i : arr) {
            cout << "[";
            for(int x : i)
                cout << x << " ";
            cout << "]";

        }cout << endl;
    }
}