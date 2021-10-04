class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        
        int bob = 0;
        int you = piles.size()-2;
        
        int ans = 0;
        
        while (bob < you) {
            ans += piles[you];
            
            bob++;
            you -= 2;
        }
        
        return ans;
    }
};