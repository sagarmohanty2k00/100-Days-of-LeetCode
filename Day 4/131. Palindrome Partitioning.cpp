#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> memo;
        int n = s.size();

        // Iterate over the entire string in each iteration we'll add a blank vector
        for (int i=0; i<n; i++) {

            // adding a vector {{}}
            memo.push_back({});
            string a = "";

            // Reverse Iterate the string from i - 0 to check pallindromes
            for (int j=i; j>=0; j--) {
                a = s[j] + a;
                string str1 = a;
                string str2 = a;
                reverse(str1.begin(), str1.end());

                // if generated string is not a palindrome then ignore
                if (str1 != str2) continue;

                // if palindrome then add a vector.
                if (j != 0) {
                    for (int k=0; k<memo[j-1].size(); k++) {
                        vector<string> x;
                        for (auto str : memo[j-1][k]) {
                            x.push_back(str);
                        }
                        x.push_back(a);
                        memo[i].push_back(x);
                    }
                }

                else {
                    memo[i].push_back({a});
                }
            }
        }


        return memo[n-1];
    }
};

int main() {
    string s;
    cin >> s;

    Solution ob;
    vector<vector<string>> partition = ob.partition(s);
    for (auto arr : partition) {
        for (string str : arr) {
            cout << "'" << str << "' ";
        }

        cout << arr.size() << endl;
    }
}