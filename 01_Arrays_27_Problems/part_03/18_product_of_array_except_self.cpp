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


#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
     
        int n = nums.size();
        
        // Allocate the result array and initialize all elements to 1.
        std::vector<int> result(n, 1);

        // STEP 1: Compute Left Products
        int leftProduct = 1;
        for(int i = 0; i < n; i++) {
            // Store the product of all elements to the left of index 'i'
            result[i] = leftProduct;
            // Subsequently update the leftProduct for the next iteration
            leftProduct *= nums[i];
        }

        // STEP 2: Compute Right Products & Final Result
        int rightProduct = 1;
        for(int i = n - 1; i >= 0; i--) {
            // Multiply the stored left product by the product of all elements to the right
            result[i] *= rightProduct;
            // Subsequently update the rightProduct for the next iteration
            rightProduct *= nums[i];
        }

        // Return the finalized array
        return result;
    }
};
