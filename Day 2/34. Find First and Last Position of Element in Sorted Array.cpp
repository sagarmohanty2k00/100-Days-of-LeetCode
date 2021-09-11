#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (binary_search(nums.begin(), nums.end(), target)) {
            int n = nums.size();
            int s = 0;
            int e = n-1;
            int a, b;
            while (s <= e) {
                int t = (s + e)/2;
                if (nums[t] == target) {
                    a = t;
                }
                
                if (nums[t] < target) {
                    s = t+1;
                }
                else {
                    e = t-1;
                }
            }
            
            s = 0;
            e = n-1;
            while (s <= e) {
                int t = (s + e)/2;
                if (nums[t] == target) {
                    b = t;
                }
                
                if (nums[t] <= target) {
                    s = t+1;
                }
                else {
                    e = t-1;
                }
            }
            
            return {a, b};
        }
        
        
        return {-1, -1};
    }
};

int main() {
    int size;
    cin >> size;

    vector<int> nums;
    for (int i=0; i<size; i++) {
        int val;
        nums.push_back(val);
    }

    int target;
    cin >> target;

    Solution ob;
    vector<int> ans = ob.searchRange(nums, target);

    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
}