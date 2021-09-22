bool compare(vector<int>&v1,vector<int>&v2){
        if(v1[0]==v2[0])
            return v1[1]<v2[1];
        return v1[0]>v2[0];
    }
class Solution {
public:
    
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),compare);
        int maxdefense=INT_MIN;
        int idx=0,ans=0;
        while(idx<arr.size()){
            if(arr[idx][1]<maxdefense)
                ans++;
            else
                maxdefense=max(arr[idx][1],maxdefense);
            idx++;
        }
        return ans;
    }
};