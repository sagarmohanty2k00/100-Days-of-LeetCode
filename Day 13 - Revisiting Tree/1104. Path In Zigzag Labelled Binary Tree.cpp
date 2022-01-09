class Solution {
public:
    int original1(int level, int tempPos) {
        if (level%2 == 0) return tempPos;
        
        int begin = pow(2, level);
        int end = pow(2, level+1)-1;
        
        return begin + (end - tempPos);
    }
    
    int original(int level, int tempPos) {
        if (level%2 != 0) return tempPos;
        
        int begin = pow(2, level);
        int end = pow(2, level+1)-1;
        
        return begin + (end - tempPos);
    }
    
    vector<int> pathInZigZagTree(int label) {
        vector<int> path = {label};
        while (label > 1) {
            path.push_back(label/2);
            label /= 2;
        }
        
        reverse(path.begin(), path.end());
        
        if (path.size()%2 == 0)
            for (int i=0; i<path.size()-1; i++) path[i] = original(i, path[i]);
        else 
            for (int i=0; i<path.size()-1; i++) path[i] = original1(i, path[i]);
        
        return path;
    }
};