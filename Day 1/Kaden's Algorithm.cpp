#include<bits/stdc++.h>
using namespace std;

int maxSumSubArray(vector<int> nums) {
    int maxx = INT_MIN;
    int sum = 0;

    for (int i=0; i<nums.size(); i++) {
        sum += nums[i];
        maxx = max(maxx, sum);

        if (sum < 0) sum = 0;
    }

    return maxx;
}

int main()
{
    vector<int> nums;
    int ele = 0;

    while (1) {
        cin >> ele;
        if (ele == -1) break;

        nums.push_back(ele);
    }

    cout << maxSumSubArray(nums) << endl;
    return 0;
}