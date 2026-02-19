class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        if (!n)
            return 0;
        int maxTrapped = 0;
        int left = 0;
        int right = n - 1;
        while(left < right){
            int width = right - left;
            int height = min( heights [right], heights[left]);
            int trappedWater = height * width;
            maxTrapped = max(maxTrapped,trappedWater);
            if(heights[left] < heights[right]) left++;
            else
                right --;
        }
        return maxTrapped;
    }
};