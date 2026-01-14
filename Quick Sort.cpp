#include<iostream>
#include<vector>
using namespace std;

int partition( vector<int>& arr, int start, int end){
    
    // use two pointer idx that tracks the one part &
    // when part is on the left done is swaps with the 
    // pivot index to make the pivot center and one part
    // on the left one part on the right
    // and curr that itrates from to previous element of pivot
    
    int pivot = arr[end];
    int idx = start-1; // just before the start point     
    
    for( int curr = start; curr < end; curr++){
        if( arr[curr] <= pivot){  
        // <= places smaller to left & array sorted accending here
        // >= if we use then greater element place left and sorted in decending
            idx++;
            swap(arr[curr], arr[idx]);
        }
    } 
    
    // now here we place the pivot to its correct position
    // at the center -  like this -> part left + pivot + right part
    idx++;
    swap(arr[idx], arr[end]);
    
    return idx;
}
void quickSort( vector<int> &arr, int start, int end){
    if(start >= end) return ; // base case : here we stop
    // as when there is only on element or no element
    int pivotIdx = partition( arr, start, end );
    quickSort(arr, start, pivotIdx - 1);
    // left half recursive call
    quickSort(arr, pivotIdx + 1, end);
    // right half recursive call
}

int main(){
    
    vector<int> arr = {5,1,3,6,2,4};
    quickSort(arr, 0, arr.size()-1);
    for( int num : arr){
        cout << num << " " ;
    }
    return 0;
}