class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1,mid;
        while(low<=high){
            mid =(low+high)/2;
            
            if ( arr[mid] == target){
                return true;
            }
            if (arr[low]== arr[mid] && arr[mid] == arr[high]){
                low++; high--; continue; 
            }
            if (arr[mid]>=arr[low]){//left sorted
            if ( arr[mid]>= target && arr[low]<= target){
                high = mid-1;
            }
            else {
                low = mid +1;
            }
            }
            else {
                if (arr[high]>= target && arr[mid] <= target){
                    low = mid +1;
                }
                else {
                    high = mid -1 ; 
                }
                
            }
        }
        return false;
    }
};
