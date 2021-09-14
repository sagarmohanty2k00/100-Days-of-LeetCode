#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;

        while (i < j) {
            while (!letter(s[i])) i++;
            while (!letter(s[j])) j--;

            // s[i] = s[j];
            swap(s[i], s[j]);

            i++;
            j--;
        }

        return s;
    }

    bool letter(char c) {
        if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <='z')) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution ob;
    string n;
    cin >> n;

    cout << ob.reverseOnlyLetters(n) << endl;
}