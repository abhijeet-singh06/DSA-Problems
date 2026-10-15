class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int freq[1001] = {0};
        for(int i=0; i<nums1.size(); i++){
            freq[nums1[i]]++;
        }
        for(int j=0; j<nums2.size(); j++){
            if(freq[nums2[j]]>0){
                ans.push_back(nums2[j]);
                freq[nums2[j]]--;
            }
        }
        return ans;
    }
};