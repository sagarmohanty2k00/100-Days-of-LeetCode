class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> UAM(k);
        for (int i=0; i<k; i++) UAM[i] = 0;
        
        unordered_map<int, set<int>> user_logs;
        for (auto x : logs) user_logs[x[0]].insert(x[1]);
        
        for (auto x : user_logs) UAM[x.second.size()-1]++;
        
        return UAM;
    }
};