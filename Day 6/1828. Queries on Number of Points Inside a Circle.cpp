class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> points_inside;
        for (auto q : queries) {
            int points_found = 0;
            for (auto p : points) {
                
                long long required = q[2] * q[2];
                int calculated = (p[0] - q[0])*(p[0]-q[0]) + (p[1]-q[1])*(p[1]-q[1]);
                
                if (calculated <= required) points_found++;
                
            }
            
            points_inside.push_back(points_found);
        }
        
        return points_inside;
    }
};