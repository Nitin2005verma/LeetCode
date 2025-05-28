class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=0 ,high=n-1;int mid;
        while(low<=high){
            mid=(high+low)/2;
            if(arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
                return mid;
            }
            else if (arr[mid+1] <arr[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};
