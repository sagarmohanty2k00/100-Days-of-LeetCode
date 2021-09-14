#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> helper(string exp, int start, int end, unordered_map<string, vector<int>> &memo) {
        vector<int> evaluations;
        string key = "";
        key += to_string(start);
        key += to_string(end);

        if (memo.find(key) != memo.end()) return memo[key];

        int x = 0;
        for (int i=start; i<=end; i++) {

            x = x*10 + exp[i] - '0';

            if (exp[i] != '+' and exp[i] != '-' and exp[i] != '*') continue;

            x = 0;

            vector<int> s_eval = helper(exp, start, i-1, memo);
            vector<int> e_eval = helper(exp, i+1, end, memo);

            char op = exp[i];

            for (int x : s_eval) {
                for (int y : e_eval) {
                    if (op == '-') {
                        evaluations.push_back(x - y);
                    }
                    else if (op == '+') {
                        evaluations.push_back(x + y);
                    }
                    else if (op == '*') {
                        evaluations.push_back(x * y);
                    }
                }
            }

        }

        if (evaluations.size() == 0) {
            evaluations.push_back(x);
        }

        return memo[key] = evaluations;
    }
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        vector<int> ans = helper(expression, 0, expression.size()-1, memo);

        return ans;
    }
};

int main() {
    string s;
    cin >> s;

    Solution ob;
    vector<int> ans = ob.diffWaysToCompute(s);
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}