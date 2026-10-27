class Solution {
public:
    vector<string> createGrid(int m, int n) {
        if(m==1){
            string s(n, '.');
            return {s};
        }

        if(n==1){
            vector<string>ans;
            for(int i=0; i<m ; i++){
                string s = ".";
                ans.push_back(s);
            }
            return ans;
        }

        vector<string>ans;
        for(int i=0; i<m-1; i++){
            string s(n, '#');
            s[0]='.';
            ans.push_back(s);
        }
        string s(n, '.');
        ans.push_back(s);
        return ans;



        
    }
};