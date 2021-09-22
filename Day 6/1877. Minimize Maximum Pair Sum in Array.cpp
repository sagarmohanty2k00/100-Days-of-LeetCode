class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxx = INT_MIN;
        int n = nums.size();
        
        for (int i=0; i<n/2; i++) {
            maxx = max(maxx, nums[i] + nums[n-1-i]);
        }
        
        return maxx;
    }
};