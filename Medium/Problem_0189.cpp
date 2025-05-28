class Solution {
void reverse(vector<int>&nums, int h , int k ){
    int i=h ; int j=k ;
    while(i<j){
        swap(nums[i],nums[j]);
        i++;j--;
    }
}
    
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();k%=n;
        if(!k || k==n)return ;
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1-k);
        reverse(nums,0,n-1);
    }
};
