#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Method 1: Two Pass Approach
// First pass: count the total nodes
// Second pass: find the middle
ListNode* findMiddle_TwoPass(ListNode* head) {
    if (!head || !head->next) return head;
    
    // Count total nodes
    int count = 0;
    ListNode* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    
    // Find middle node
    int mid = count / 2;
    temp = head;
    for (int i = 0; i < mid; i++) {
        temp = temp->next;
    }
    
    return temp;
}

// Method 2: Slow and Fast Pointer Approach (Optimal)
// Time: O(n), Space: O(1)
ListNode* findMiddle_TwoPointer(ListNode* head) {
    if (!head || !head->next) return head;
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // Move fast pointer by 2 and slow by 1
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

// Utility function to create a linked list
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Driver code
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createList(arr, size);
    
    cout << "Linked List: ";
    printList(head);
    
    ListNode* middle = findMiddle_TwoPointer(head);
    cout << "Middle element: " << middle->val << endl;
    
    return 0;
}