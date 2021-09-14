#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPft(int isBuy, vector<int>& prices, int idx,map<string,int> &m) {
        if(idx >= prices.size()) {
            return 0;
        }
        string key;
        key = to_string(idx)+"_"+to_string(isBuy);
        if(m.count(key) > 0) {
            return m[key];
        }
        
        int x = 0;
        if(isBuy == 0) {
            int b = maxPft(1,prices,idx+1,m)-prices[idx];
            int nb = maxPft(0,prices,idx+1,m);
            x = max(b,nb);
        } else {
            int s = maxPft(0,prices,idx+2,m)+prices[idx];
            int ns = maxPft(1,prices,idx+1,m);
            x = max(s,ns);
        }
        m[key]=x;
        return x;
        
    }
    int maxProfit(vector<int>& prices) {
        map<string,int> m;
        int ans = maxPft(0,prices,0,m);
        return ans;
    }
};

int main() {
    Solution ob;
    int n;
    cin >> n;

    vector<int> prices;
    for (int i=0; i<n; i++) {
        int val;
        cin >> val;

        prices.push_back(val);
    }

    prices = {48,12,60,93,97,42,25,64,17,56,85,93,9,48,52,42,58,85,81,84,69,36,1,54,23,15,72,15,11,94};

    cout << ob.maxProfit(prices) << endl;
}