#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Method 1: Using Hash Set
// Time: O(n), Space: O(n)
bool hasCycleHashSet(Node* head) {
    unordered_set<Node*> visited;
    while (head) {
        if (visited.count(head)) return true;
        visited.insert(head);
        head = head->next;
    }
    return false;
}

// Method 2: Floyd's Cycle Detection (Tortoise and Hare)
// Time: O(n), Space: O(1) - OPTIMAL
bool hasCycleFloyd(Node* head) {
    if (!head || !head->next) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;  // Cycle detected
    }
    return false;
}

// Method 3: Find cycle start using Floyd's algorithm
Node* findCycleStart(Node* head) {
    if (!head || !head->next) return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    // If no cycle found
    if (!fast || !fast->next) return NULL;
    
    // Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;  // Cycle start node
}

// Method 4: Remove cycle
void removeCycle(Node* head) {
    if (!head || !head->next) return;
    
    Node* slow = head;
    Node* fast = head;
    
    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    // If no cycle found
    if (!fast || !fast->next) return;
    
    // Find cycle start
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Find last node in cycle
    Node* cycleStart = slow;
    while (fast->next != cycleStart) {
        fast = fast->next;
    }
    
    fast->next = NULL;  // Break the cycle
}

// Utility: Print list (with iteration limit to avoid infinite loop)
void printList(Node* head, int limit = 10) {
    int count = 0;
    while (head && count < limit) {
        cout << head->data << " -> ";
        head = head->next;
        count++;
    }
    if (head) cout << "...";
    cout << "NULL" << endl;
}

// Driver code
int main() {
    // Test case 1: List with cycle
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = head1->next;  // Cycle: 4 -> 2
    
    cout << "=== Cycle Detection ===" << endl;
    cout << "Hash Set Method: " << (hasCycleHashSet(head1) ? "Cycle Found" : "No Cycle") << endl;
    cout << "Floyd's Method: " << (hasCycleFloyd(head1) ? "Cycle Found" : "No Cycle") << endl;
    
    // Test case 2: Find cycle start
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = head2->next;  // Cycle starts at 2
    
    Node* cycleStart = findCycleStart(head2);
    cout << "\nCycle starts at: " << (cycleStart ? to_string(cycleStart->data) : "No cycle") << endl;
    
    // Test case 3: Remove cycle
    Node* head3 = new Node(1);
    head3->next = new Node(2);
    head3->next->next = new Node(3);
    head3->next->next->next = new Node(4);
    head3->next->next->next->next = head3->next;  // Cycle: 4 -> 2
    
    cout << "\n=== Remove Cycle ===" << endl;
    cout << "Before removal - Has cycle: " << (hasCycleFloyd(head3) ? "Yes" : "No") << endl;
    
    removeCycle(head3);
    
    cout << "After removal - Has cycle: " << (hasCycleFloyd(head3) ? "Yes" : "No") << endl;
    cout << "List after removing cycle: ";
    printList(head3);
    
    return 0;
}