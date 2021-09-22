class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        for (int i=0; i<groupSizes.size(); i++) {
            m[groupSizes[i]].push_back(i);
        }
        
        vector<vector<int>> groups;
        for (auto x : m) {
            int n=x.second.size();
            
            int parts = n/x.first;
            for (int i=0; i<parts; i++) {
                vector<int> group;
                for (int j=i*x.first; j<(i+1)*x.first; j++) {
                    group.push_back(x.second[j]);
                }
                
                groups.push_back(group);
            }
        }
        
        return groups;
    }
};