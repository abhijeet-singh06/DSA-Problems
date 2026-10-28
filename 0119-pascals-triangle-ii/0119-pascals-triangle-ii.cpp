class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> row;
        for(int i=0; i<=rowIndex; i++){
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i){
                    row.push_back(1);
                }
                else{
                    row.push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
            ans.push_back(row);
            row.clear();
        }
        return ans[rowIndex];
    }
};