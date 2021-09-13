#include <bits/stdc++.h>
using namespace std;

class BreakPoint {
public:
    int start;
    int end;

    int maxProd;

    vector<int> negs;
};

class Solution {
public:
    int product(vector<int> &nums, int start, int end) {
        // cout << start << " " << end << endl;
        if (start == end) {
            return nums[start];
        }

        if (start > end) {
            return 0;
        }

        int prod = 1;
        for (int i=start; i<=end; i++) {
            prod *= nums[i];
        }

        return prod;
    }

    void break_point_product(vector<int> nums, BreakPoint &bp) {
        
        // calculate the max product for the break point 
        if (bp.start > bp.end) {
            bp.maxProd = 0;
            return;
        }
        
        if (bp.start == bp.end) {
            bp.maxProd = nums[bp.start];
            return;
        }

        if (bp.negs.size()%2 == 0) {
            bp.maxProd = product(nums, bp.start, bp.end);
            return;
        }

        bp.maxProd = max(
            product(nums, bp.negs[0] + 1, bp.end),
            product(nums, bp.start, bp.negs[bp.negs.size() - 1] - 1)
        );

        return;

    }

    int maxProduct(vector<int>& nums) {

        if (nums.size() == 1) return nums[0];

        vector<BreakPoint> break_points;
        
        int n = nums.size();
        int start = 0;

        int maxProd = 0;

        vector<int> negetive_pos;
        for (int i=0; i<n; i++) {
            if (nums[i] < 0) {
                negetive_pos.push_back(i);
            }

            else if (nums[i] == 0) {
                BreakPoint bp;
                bp.start = start;
                bp.end = i-1;
                bp.negs = negetive_pos;

                break_point_product(nums, bp);
                break_points.push_back(bp);

                start = i+1;

                negetive_pos.clear();
            }
        }

        if (start < n) {
            BreakPoint bp;
            bp.start = start;
            bp.end = n-1;
            bp.negs = negetive_pos;

            break_point_product(nums, bp);

            break_points.push_back(bp);

            negetive_pos.clear();
        }


        for (auto x : break_points) {
            cout << x.maxProd << endl;
            maxProd = max(maxProd, x.maxProd);
        }


        return maxProd;

    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for (int i=0; i<n; i++) {
        int val;
        cin >> val;

        nums.push_back(val);
    }

    Solution ob;
    cout << ob.maxProduct(nums) << endl;
}