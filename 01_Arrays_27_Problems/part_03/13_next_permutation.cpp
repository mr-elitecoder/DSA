
/*

# ALGORITHM:

->  Move from right to find first increasing pair.

->  Find smallest number greater than pivot on right.
->  Swap.

->  Reverse right side.

# EXPLANATION:

To find the lexicographical successor of an array, I use a three-step in-place transformation that ensures the smallest possible increment.

IDENTIFY THE PIVOT: I scan the array from right to left to find the Pivot—the first element that is smaller than its right-hand neighbor. This is the inflection point where the sequence ceases to be descending.

LOCATE THE SUCCESSOR: I then search the suffix (the elements to the right of the pivot) for the Successor. This is the smallest value that is strictly greater than the pivot. Swapping these two ensures a marginal increase in the overall value.

MINIMIZE THE SUFFIX: Finally, I reverse the suffix. Since the suffix was in descending order, reversing it makes it ascending, which is the smallest possible arrangement for those digits.


# EDGE CASES

CASE A: THE "TERMINAL" SEQUENCE
What happens if the array is already in descending order (e.g., [3, 2, 1])?

Explanation:
 In this scenario, our search for a pivot will fail (it will reach -1).

The Resolution:
 According to the problem constraints, we must return the lowest possible order. Our code handles this gracefully: since the if (pivot >= 0) block is skipped, we simply reverse the entire array to get [1, 2, 3].

IELTS Vocabulary:
 Gracefully (smoothly/without error), Terminal (final/end of a series).

CASE B: DUPLICATE ELEMENTS
What if the array contains identical values (e.g., [1, 5, 1])?

Explanation:
 Our logic uses nums[j] <= nums[pivot] to find the successor. This ensures we skip over elements that are equal to the pivot.

The Resolution:
 We must find a value strictly greater than the pivot to ensure a genuine lexicographical increase.

IELTS Vocabulary:
 Identical (exactly the same), Strictly (used here to mean "with no exceptions").

# CODE

*/

class Solution {
public:
    void nextPermutation(vector<int>& nums)      
   {
     int n = nums.size();
     if ( ! n ) return;
     int pivot = n - 2;

     while (
      pivot >= 0 &&
      nums[pivot] >= nums[pivot+1]
     )
     pivot--;

     if( pivot >= 0 ){
       int successor = n - 1;

       while (
          successor > pivot &&
          nums[successor] <= nums[pivot]
     )       successor-- ;

        swap(
             nums[successor],
             nums[pivot]
           );
     }
     reverse(
            nums.begin()+pivot+1,
            nums.end()
             );
   }
};


