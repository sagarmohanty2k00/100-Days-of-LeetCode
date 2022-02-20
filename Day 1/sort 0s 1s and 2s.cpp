#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> &nums) {
    int l = -1;
    int r = nums.size();

    for (int i=0; i<nums.size(); i++) {
        if (i == r) break;

        
        if (nums[i] == 0) {
            l++;
            swap(nums[i], nums[l]);

            cout << i << ": " << l << ", " << nums[l] << endl;
        }

        else if (nums[i] == 2) {
            r--;
            swap(nums[i], nums[r]);
            cout << i << ": " << r << ", " << nums[r] << endl;
            i--;
        }

    }

    for (int i=0; i<nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
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

    sort(nums);
    return 0;
}