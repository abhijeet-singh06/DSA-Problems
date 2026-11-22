class Solution {
public:
    bool checkString(string s) {
        string w = s;
        sort(w.begin(), w.end());

        if(w == s) {
            return true;
        }
        else {
            return false;
        }
    }
};