class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int s=1;
        int e=x;
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            long long int square=pow(mid,2);
            if(square == x){
                return mid;
            }else if(square>x){
                e=mid-1;
            }else {
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
};