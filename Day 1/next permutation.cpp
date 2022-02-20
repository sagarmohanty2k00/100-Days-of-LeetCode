#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> nums) {
    cout << "Configuration now: ";
    for (int n : nums) cout << n << " ";

    cout << endl;

    // STEP 1: find the targeted region i.e the sorted region from the end
    int pos1 = nums.size() - 2;
    while (pos1 >= 0) {
        if (nums[pos1] < nums[pos1+1]) break;

        pos1--;
    }

    // If the targeted region is the whole array then reverse 
    if (pos1 == -1) {
        reverse(nums.begin(), nums.end());
    }
    // Else rearrange the targeted region
    else {
        /* 
        ** find the element that is just greater than the pos1 element 
        ** which ensures that the number is just the next permutation of the given number 
        */
        int pos2 = nums.size() - 1;
        while (nums[pos1] > nums[pos2]) pos2--;

        cout << nums[pos1] << " " << nums[pos2] << endl;

        // swap pos1 and pos2
        swap(nums[pos1], nums[pos2]);

        // Reverse the array from pos1 to end;
        reverse(nums.begin() + pos1 + 1, nums.end());

    }

    cout << "Configutation after permutaion: ";
    for (int n : nums) cout << n << " ";
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

    nextPermutation(nums);
    return 0;
}