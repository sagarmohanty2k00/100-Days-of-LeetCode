class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        
        unordered_set<char> count;
        vector<int> ans;
        
        int last = -1;
        
        for (int i=0; i<s.size(); i++) {
            count.insert(s[i]);
            m[s[i]]--;
            if (m[s[i]] == 0) count.erase(s[i]);
            
            if (count.size() == 0) {
                ans.push_back(i-last);
                last = i;
            }
        }
        
        return ans;
    }
};