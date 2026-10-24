class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        vector<int>ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        int j=0;
        int k=0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                ans.push_back(pos[j]);
                j++;
            }
            else{
                ans.push_back(neg[k]);
                k++;
            }
        }
        return ans;
        

    }
};