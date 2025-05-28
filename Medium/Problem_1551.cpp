class Solution {
public:
    int minOperations(int n) {
        int cnt=0;
        if(n%2==1){
            for (int i=2 ; i<n ; i=i+2){
                cnt+=i;
            }   
        }
        else{
            for (int i=1 ; i<n ; i=i+2){
                cnt+=i;
            }
        }return cnt;
    }
};
