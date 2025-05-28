class Solution {
public:
    int reverse(long long x) {
        if (x>INT_MAX)return 0;
        long long rev=0; long long rem=0;
        if(x>0){
        while(x>0){
            rem = x%10;
            rev = rev *10 + rem;
            if(rev>INT_MAX)return 0;
            x=x/10;
        }
        }
        if(x<0){
            x = -1*x;
            if(x>INT_MAX)return 0;
            while(x>0){
            rem = x%10;
            rev = rev *10 + rem;
            if(rev>INT_MAX)return 0;
            x=x/10;
        }
        rev = -1 *rev ;
        }
        if(rev>INT_MAX)return 0;
        return rev;
    }
};
