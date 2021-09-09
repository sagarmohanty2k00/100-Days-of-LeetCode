class Solution {
public:
    vector<string> dp(string digits, int i, int n, unordered_map<int, vector<string>> &memo) {
        vector<string> ans;
        if (i > n) {
            return ans;
        } 
        
        if (memo.find(i) != memo.end()) 
            return memo[i];
        
        string ops = "";
        if (digits[i] == '9') {
            ops = "wxyz";
        }
        else if (digits[i] == '7') {
            ops = "pqrs";
        }
        else if (digits[i] - '0' < 7) {
            int start = digits[i] - '0';
            start = (start-2) * 3;
            
            ops += (start + 'a');
            ops += (start + 'b');
            ops += (start + 'c');
        }
        else {
            int start = digits[i] - '0';
            start = ((start-2) * 3 ) + 1;
            
            ops += (start + 'a');
            ops += (start + 'b');
            ops += (start + 'c');
        }
        
        if (i == n) {
            string item = "";
            item += ops[0];
            for (char c : ops) {
                ans.push_back(item);
                item[0] += 1;
            }
            return ans;
        }
        
        
        vector<string> temp = dp(digits, i+1, n, memo);
        for(char c : ops) {
            for (string s : temp) {
                ans.push_back(c + s);
            }
        }
        
        return memo[i] = ans;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int, vector<string>> memo;
        int n = digits.size();
        return dp(digits, 0, n-1, memo);
    }
};


int main() {
    string s;
    cin >> s;

    Solution ob;
    vector<string> ans = ob.letterCombinations(s);

    for (string x : ans) {
        cout << x << " ";
    }

    cout << endl;
}