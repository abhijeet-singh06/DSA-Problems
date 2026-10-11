class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int max= nums[0];
        int ans = 0;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]>max){
                max = nums[i];
                ans=i;
            }
        }
        return ans ;
    }
};