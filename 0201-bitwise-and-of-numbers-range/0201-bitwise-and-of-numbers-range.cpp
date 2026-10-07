class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift_count=0;
        while(left<right){
            left >>= 1;
            right >>= 1;
            shift_count++;
        }
        return left<<shift_count;
    }
};