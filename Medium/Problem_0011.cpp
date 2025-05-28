class Solution {
public:
    int maxArea(vector<int>& ht) {
        int n = ht.size();
        int left = 0, right = n - 1;
        int maxArea = 0;
        while (left < right) {
            // Calculate the current area between the lines at indices left and right
            int currentArea = (right - left) * min(ht[left], ht[right]);
            // Update maxArea if the current area is greater
            maxArea = max(maxArea, currentArea);
            // Move the pointer with the smaller height towards the center
            if (ht[left] < ht[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxArea;
    }
};
