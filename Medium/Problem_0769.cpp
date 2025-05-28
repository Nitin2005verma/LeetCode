class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();int cnt=0;
        int sum=0;
        for(int i=0 ; i<n; i++){
            sum+=arr[i];
            if(sum == i*(i+1)*0.5 )cnt++;
        }
        return cnt;
    }
};
