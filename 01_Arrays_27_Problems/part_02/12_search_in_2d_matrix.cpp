class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(! matrix.size() )
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m*n-1 ;

        while(left <= right){
            int mid = left + (right-left)/2;
            int row = mid / n ;
            int col = mid % n ;
            int midVal = matrix[row][col];
            if(midVal == target)
                return true;
            else if(midVal < target)
                left = mid + 1;
            else
                right= mid - 1;
        }
        return false;
    }
};