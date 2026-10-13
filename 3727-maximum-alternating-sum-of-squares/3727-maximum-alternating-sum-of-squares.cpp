class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
        int i=0;
        int j=nums.size()-1;
        int k =0;
        long long ans=0;

        while(i<=j){
            if(k%2==0){
                ans=ans+(1LL * nums[i] * nums[i]);
                i++;
            }
            if(k%2!=0){
                ans=ans-(1LL * nums[j] * nums[j]);
                j--;
            }   
            k++;
        }
        return ans;

    }
};