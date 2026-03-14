#include<iostream>
#include<vector>
using namespace std;

void sorted(vector<int> &nums){
    int n = nums.size();
    int low = 0;
    int mvPtr = 0;
    int high = n-1;
    while(mvPtr <= high ){
        if ( nums[mvPtr] == 0 ){
            swap(nums[mvPtr], nums[low]);
            low++ ; mvPtr++;
        }
        else if( nums[mvPtr] == 1){
            mvPtr++;
        }
        else{
            swap(nums[mvPtr],nums[high]);
            high--;
        }
    } 
}

int main(){
    vector<int> nums = {1,2,1,1,0,0,2,1,1,2,1,0,0,0};
    sorted(nums);
    for (int num : nums ) {
        cout<< num << " " ;
    }
}