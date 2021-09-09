#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        // if not reversed
        if (nums[0] <= nums[n-1]) {
            if (binary_search(nums.begin(), nums.end(), target)) {
                return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            }
            else {
                return -1;
            }
        }

        //search mid
        int mid = 0;
        while (nums[mid]  < nums[mid+1]) mid++;

        cout << "mid " << mid << endl;

        // search element in first half
        if (binary_search(nums.begin(), nums.begin() + mid + 1, target)) {
            return lower_bound(nums.begin(), nums.begin() + mid + 1, target) - nums.begin();
        }

        // search element in second half
        if (binary_search(nums.begin() + mid + 1, nums.end(), target)) {
            return lower_bound(nums.begin() + mid + 1, nums.end(), target) - nums.begin();
        }

        return -1;
    }
};

int main() {
    int t;
    cout << "test cases : ";
    cin >> t;
    cout << endl;

    Solution ob;

    while (t--) {
        int size;
        cout << "enter the size : ";
        cin >> size;

        vector<int> nums;

        for (int i=0; i<size; i++) {
            int val;
            cin >> val;
            nums.push_back(val);
        }

        int target;
        cout << "target : ";
        cin >> target;

        cout << ob.search(nums, target) << endl;;
    }
}