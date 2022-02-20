#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> nums) {
    int minn = nums[0];
    int profit = INT_MIN;

    for (int i=0; i<nums.size(); i++) {
        if (nums[i] > minn) profit = max(profit, nums[i] - minn);
        else minn = min(minn, nums[i]);
    }

    return profit;
}

int main()
{
    vector<int> nums;
    int size;
    cin >> size;
    for (int i=0; i<size; i++) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    cout << maxProfit(nums) << endl;
    return 0;
}