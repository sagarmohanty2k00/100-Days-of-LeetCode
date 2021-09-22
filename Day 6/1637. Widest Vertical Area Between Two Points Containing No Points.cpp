class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        unordered_set<int> m;
        for (auto x : points) {
            m.insert(x[0]);
        }
        
        vector<int> p;
        for (int x : m) {
            p.push_back(x);
        }
        
        sort(p.begin(), p.end());
        int maxWidth = 0;
        for (int i=1; i<p.size(); i++) {
            maxWidth = max(maxWidth, p[i] - p[i-1]);
        }
        
        
        return maxWidth;
    }
};