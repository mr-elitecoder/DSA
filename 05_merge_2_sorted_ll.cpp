#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Method 1: Iterative Approach (OPTIMAL)
// Time: O(n + m), Space: O(1)
Node* mergeSortedLists(Node* l1, Node* l2) {
    Node* dummy = new Node(0);  // Dummy node to simplify logic
    Node* current = dummy;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    // Attach remaining nodes
    if (l1) {
        current->next = l1;
    } else {
        current->next = l2;
    }
    
    Node* result = dummy->next;
    delete dummy;
    return result;
}

// Method 2: Recursive Approach
// Time: O(n + m), Space: O(n + m) - due to recursion stack
Node* mergeSortedListsRecursive(Node* l1, Node* l2) {
    // Base cases
    if (!l1) return l2;
    if (!l2) return l1;
    
    // Recursive case
    if (l1->data <= l2->data) {
        l1->next = mergeSortedListsRecursive(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeSortedListsRecursive(l1, l2->next);
        return l2;
    }
}

// Method 3: Using Comparison and Two Pointers
// Time: O(n + m), Space: O(1)
Node* mergeSortedListsTwoPointers(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    Node* head;
    if (l1->data <= l2->data) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }
    
    Node* current = head;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    current->next = l1 ? l1 : l2;
    return head;
}

// Utility: Create linked list from array
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

// Utility: Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility: Get length of list
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    // Test case 1: Both lists have elements
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    
    Node* l1 = createList(arr1, 4);
    Node* l2 = createList(arr2, 4);
    
    cout << "=== Method 1: Iterative (Dummy Node) ===" << endl;
    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);
    
    Node* merged1 = mergeSortedLists(l1, l2);
    cout << "Merged: ";
    printList(merged1);
    
    // Test case 2: Lists of different sizes
    cout << "\n=== Method 2: Recursive ===" << endl;
    int arr3[] = {1, 5, 9};
    int arr4[] = {2, 3, 4, 6, 7, 8, 10};
    
    Node* l3 = createList(arr3, 3);
    Node* l4 = createList(arr4, 7);
    
    cout << "List 1: ";
    printList(l3);
    cout << "List 2: ";
    printList(l4);
    
    Node* merged2 = mergeSortedListsRecursive(l3, l4);
    cout << "Merged: ";
    printList(merged2);
    
    // Test case 3: One list is empty
    cout << "\n=== Method 3: Two Pointers ===" << endl;
    int arr5[] = {1, 2, 3};
    
    Node* l5 = createList(arr5, 3);
    Node* l6 = NULL;
    
    cout << "List 1: ";
    printList(l5);
    cout << "List 2: ";
    printList(l6);
    
    Node* merged3 = mergeSortedListsTwoPointers(l5, l6);
    cout << "Merged: ";
    printList(merged3);
    
    return 0;
}