class Solution {
public:
    bool isPerfectSquare(int num) {
        int s =0;
        int e =num;
        int ans=0;
        while(s <= e ){
            long long mid = (s+e)/2;
            if(mid*mid > num){
                e=mid-1;
            }
            if(mid*mid < num){
                s=mid+1;
            }
            if(mid*mid==num){
                return true;
            }

        }
        return false;
    }
};