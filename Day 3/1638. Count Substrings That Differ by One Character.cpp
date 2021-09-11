#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<t.size(); j++) {
                if (s[i] == t[j]) continue;
                
                int l = 1;
                int r = 1;
                
                int S=i-1;
                int T=j-1;
                while (S<s.size() and T < t.size() and s[S] == t[T]) {
                    l++;
                    S--;
                    T--;
                }
                
                S=i+1;
                T=j+1;
                while (S<s.size() and T < t.size() and s[S] == t[T]) {
                    r++;
                    S++;
                    T++;
                }
                
                
                ans += (l * r);
            }
        }
        
        return ans;
    }
};

int main() {
    string s, t;
    cin >> s >> t;


    Solution ob;
    cout << ob.countSubstrings(s, t) << endl;

} 