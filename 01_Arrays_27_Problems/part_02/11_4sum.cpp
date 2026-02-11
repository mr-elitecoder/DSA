#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> s;
    
    for(int i = 0; i < n-3; i++){
        // Skip duplicates for i
        if(i > 0 && nums[i] == nums[i-1]) continue;
        
        for(int j = i+1; j < n-2; j++){
            // Skip duplicates for j
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            
            int low = j+1;
            int high = n-1;
            
            while(low < high){
                // Use long long to prevent overflow
                long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];
                
                if(sum == target){
                    vector<int> pair = {nums[i], nums[j], nums[low], nums[high]};
                    s.insert(pair);
                    
                    // Move both pointers after finding a valid pair
                    low++;
                    high--;
                    
                    // Skip duplicates for low and high
                    while(low < high && nums[low] == nums[low-1]) low++;
                    while(low < high && nums[high] == nums[high+1]) high--;
                    
                } else if(sum < target) {
                    low++;
                } else {
                    high--;
                }
            }
        }
    }
    
    vector<vector<int>> result(s.begin(), s.end());
    return result;
}

int main(){
    vector<int> nums = {1, 2, 3, 1, 4, 5, 2, -3, -1, -2};
    int target = 8;
    vector<vector<int>> result = fourSum(nums, target);
    
    for(vector<int> quad : result){
        cout << "[ ";
        for(int num : quad)
            cout << num << " ";
        cout << "]" << endl;
    };
    return 0;
}