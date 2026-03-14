#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Method 1: Iterative Approach (Optimal)
// Time: O(n), Space: O(1)
ListNode* reverseIterative(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while (curr) {
        ListNode* nextTemp = curr->next;  // Save next node
        curr->next = prev;                 // Reverse the link
        prev = curr;                       // Move prev forward
        curr = nextTemp;                   // Move curr forward
    }
    
    return prev;  // New head
}

// Method 2: Recursive Approach
// Time: O(n), Space: O(n) due to recursion stack
ListNode* reverseRecursive(ListNode* head) {
    // Base case: empty list or single node
    if (!head || !head->next) return head;
    
    // Reverse the rest of the list
    ListNode* newHead = reverseRecursive(head->next);
    
    // Put first element at the end
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

// Method 3: Recursive with Helper
// Time: O(n), Space: O(n)
ListNode* reverseRecursiveHelper(ListNode* head, ListNode* prev = NULL) {
    if (!head) return prev;
    
    ListNode* nextNode = head->next;
    head->next = prev;
    
    return reverseRecursiveHelper(nextNode, head);
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
    
    // Test Iterative Approach
    ListNode* head1 = createList(arr, size);
    cout << "Original List: ";
    printList(head1);
    
    head1 = reverseIterative(head1);
    cout << "Reversed (Iterative): ";
    printList(head1);
    
    // Test Recursive Approach
    int arr2[] = {1, 2, 3, 4, 5};
    ListNode* head2 = createList(arr2, 5);
    cout << "\nOriginal List: ";
    printList(head2);
    
    head2 = reverseRecursive(head2);
    cout << "Reversed (Recursive): ";
    printList(head2);
    
    // Test Recursive Helper
    int arr3[] = {1, 2, 3, 4, 5};
    ListNode* head3 = createList(arr3, 5);
    cout << "\nOriginal List: ";
    printList(head3);
    
    head3 = reverseRecursiveHelper(head3);
    cout << "Reversed (Recursive Helper): ";
    printList(head3);
    
    return 0;
}