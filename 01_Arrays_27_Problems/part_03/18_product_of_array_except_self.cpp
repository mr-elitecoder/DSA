/*
        -----------------------------------------------------------------------
       # PROBLEM EXPLANATION:
        Given an integer array 'nums', return an array 'result' such that 
        result[i] is equal to the product of all the elements of 'nums' except nums[i].
        You must write an algorithm that runs in O(n) time and without using the 
        division operation.

        # ALGORITHM STEPS:

        1. Initialize a result array of the same size with 1s.
        2. Traverse the array from left to right to calculate the "left product" 
           (prefix) for each element and store it in the result array.
        3. Traverse the array from right to left to calculate the "right product" 
           (suffix). Multiply this sequentially with the existing left product 
           already stored in the result array.
        
       # TIME & SPACE COMPLEXITY:

        - Time Complexity: O(n) -> We traverse the array exactly twice (two separate loops).
        - Space Complexity: O(1) -> We only allocate memory for the output array. 
          (Note: The output array does not count towards auxiliary space complexity).

        # EDGE CASES HANDLED IMPLICITLY:
        - One Zero in Array (e.g., [1, 2, 0, 4]): The algorithm will naturally calculate 
          a product of 0 for all elements except the 0 itself, which will get the product 
          of the rest (8).
        - Multiple Zeros (e.g., [1, 0, 0, 4]): All elements in the result will correctly 
          become 0.
        - Minimum Size Array (e.g., [1, 2]): Works perfectly as prefixes and suffixes 
          will just be the single opposite elements.
        ----------------------------------------------------------------------- 
*/

// # Code 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std :: vector<int> result(n,1);

        int leftProduct = 1;
        for(int i = 0 ; i < n ; i++){
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }

        int rightProduct = 1;
        for(int i = n - 1; i >= 0 ; i--){
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
};