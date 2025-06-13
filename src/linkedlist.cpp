#include "linkedlist.hpp"

void LinkedList::clear()
{
    Node2* current = head;
    // check if the current Node is not a nullptr
    while (current != nullptr)
    {
        // get the next node
        Node2* next = current->getNext();
        // delete the current node
        delete current;
        // make the next node the current one
        current = next;
    }
    // optional: house-keeping
    head = tail = nullptr;
    length = 0;
}

LinkedList::LinkedList(int value)
{
    // create a new Node (first node)
    head = new Node2(value);
    tail = head;
    length = 1;
}

LinkedList::~LinkedList() { LinkedList::clear(); }

// LinkedList APIs

void LinkedList::append(const int value)
{
    /*
        * Appends a new node containing the given value to the end of the linked list.
        *
        * Behavior:
        * - If the list is empty, the new node becomes both the head and the tail.
        * - Otherwise, the current tail node's next pointer is updated to point to the new node,
        *   and the tail reference is updated accordingly.
        * - The length of the list is incremented.
        *
        * Parameters:
        * - value: The integer data to store in the newly appended node.
    */

    Node2* newNode = new Node2(value);
    if (length == 0)
    {
        // LinkedList is empty
        head = newNode;
        tail = newNode;
    }
    else
    {
        // LinkedList has existing nodes
        tail->setNext(newNode);
        tail = newNode;
    }
    ++length;
}

void LinkedList::prepend(const int value)
{
    /*
     * Inserts a new node containing the given value at the beginning of the list.
     *
     * Handles two cases:
     * 1. The list is empty — the new node becomes both head and tail.
     * 2. The list has one or more nodes — the new node points to the current head,
     *    and then becomes the new head.
     *
     * Increments the list length after insertion.
     */

    Node2* newNode = new Node2(value);

    if (length == 0)
    {
        // Empty list: new node is both head and tail
        head = tail = newNode;
    }
    else
    {
        // Non-empty list: insert before current head
        newNode->setNext(head);
        head = newNode;
    }

    ++length;
}


void LinkedList::deleteLast()
{
    /*
     * There are 3 scenarios to cover here:
     * 1. when the linkedlist is empty
     * 2. when the linkedlist has only one node (edge case)
     * 3. when the linkedlist has 2 or more nodes,
     */

    /*
     * Removes the last node from the linked list.
     *
     * Handles three cases:
     * 1. The list is empty — nothing to delete.
     * 2. The list has only one node — both head and tail are set to nullptr.
     * 3. The list has two or more nodes — iterate to the second-to-last node,
     *    update tail, and disconnect the last node.
     */

    if (length == 0) return; // Case 1: list is empty

    Node2* temp = head;

    if (length == 1)
    {
        // Case 2: only one node in the list
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        // Case 3: two or more nodes
        Node2* prev = nullptr;
        while (temp->getNext())
        {
            prev = temp;
            temp = temp->getNext();
        }
        tail = prev;
        tail->setNext(nullptr);
    }

    delete temp;
    --length;
}

void LinkedList::deleteFirst()
{
    /*
        * There are 3 scenarios to cover here:
        * 1. when the linkedlist is empty (edge case)
        * 2. when the linkedlist has only one node (edge case)
        * 3. when the linkedlist has 2 or more nodes,
    */

    /*
     * Removes the first node from the linked list.
     *
     * Handles three cases:
     * 1. The list is empty — nothing to delete.
     * 2. The list has only one node — both head and tail are set to nullptr.
     * 3. The list has two or more nodes — head is advanced to the next node.
     *
     * Frees the memory occupied by the removed node and updates the list length.
     */

    if (length == 0) return; // Case 1: empty list

    Node2* temp = head;

    if (length == 1)
    {
        // Case 2: only one node
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        // Case 3: two or more nodes
        head = head->getNext();
    }

    delete temp;
    --length;
}


void LinkedList::deleteNode(const int index)
{
    /*
     * Deletes the node at the specified index from the linked list.
     *
     * Valid index range: [0, length - 1] (Note: length - 1 is the index of the last valid node).
     * - index == 0: Use deleteFirst() to remove the head.
     * - index == length - 1: Use deleteLast() to remove the tail.
     * - Otherwise: Locate the previous node, unlink the target node, and free its memory.
     *
     * Parameters:
     * - index: The position of the node to delete.
     *
     * No action is taken if the index is invalid.
     */

    if (index < 0 || index >= length) return;

    if (index == 0)
    {
        deleteFirst();
        return;
    }

    if (index == length - 1)
    {
        deleteLast();
        return;
    }

    // Deleting a node in the middle
    Node2* prev = get(index - 1);
    Node2* target = prev->getNext();

    prev->setNext(target->getNext());
    delete target;
    --length;
}


Node2* LinkedList::get(const int index) const
{
    /*
        * LinkedList nodes are not stored in contiguous memory like C++ arrays,
        * so index-based access must be simulated via iteration from the head node.
        *
        * Preconditions:
        * - The index must be non-negative.
        * - The index must be strictly less than the current length of the list.
        *
        * Returns:
        * - A pointer to the node at the specified index, or nullptr if the index is invalid.
     */

    if (index < 0 || index >= length) return nullptr;

    Node2* result = head;
    for (int i = 0; i < index; ++i)
    {
        result = result->getNext();
    }
    return result;
}

bool LinkedList::set(const int index, const int value)
{
    /*
        * Updates the data of the node at the specified index.
        *
        * This method uses the get(index) method as a helper to locate the node, since
        * LinkedList nodes are not stored contiguously and must be accessed via iteration.
        *
        * Parameters:
        * - index: Position of the node to update (must be within bounds).
        * - value: New value to set in the node.
        *
        * Returns:
        * - true if the node was found and updated successfully.
        * - false if the index is invalid (out of bounds).
    */

    Node2* target = get(index);

    if (target)
    {
        target->setData(value);
        return true;
    }
    return false;
}


bool LinkedList::insert(const int index, const int value)
{
    /*
        * Inserts a new node containing the given value at the specified index.
        *
        * Valid index range: [0, length]
        * - index == 0: Insert at the beginning using prepend().
        * - index == length: Insert at the end using append().
        * - Otherwise: Insert in the middle by locating the previous node,
        *   linking the new node, and adjusting pointers.
        *
        * Parameters:
        * - index: Position at which to insert the new node.
        * - value: The value to store in the new node.
        *
        * Returns:
        * - true if the insertion was successful.
        * - false if the index is out of bounds.
     */

    if (index < 0 || index > length) return false;

    if (index == 0)
    {
        prepend(value);
        return true;
    }

    if (index == length)
    {
        append(value);
        return true;
    }

    // Insert in the middle
    Node2* newNode = new Node2(value);
    Node2* prev = get(index - 1);
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
    ++length;

    return true;
}


void LinkedList::reverse()
{
    /*
     * steps:
     *  - swap head and tail nodes
     *  - you need three temporary variables to make the linkedlist reversal: "temp", "after temp", "before temp"
     *  - use a for loop that runs through the length of the linked list to perform the reversal of pointer direction
     * */

    // step 1: switch head and tail node pointers
    Node2* temp = head;
    head = tail;
    tail = temp;

    // reverse the nodes
    Node2* after = temp->getNext();
    Node2* before = nullptr;

    for (int i = 0; i < length; i++)
    {
        after = temp->getNext(); // Store next node
        temp->setNext(before); // Reverse the link
        before = temp; // Move before forward
        temp = after; // Move temp forward
    }
}

Node2* LinkedList::findMiddleNode() const
{
    if (head == nullptr) return nullptr;

    Node2* slow = head;
    Node2* fast = head;

    while (fast != nullptr && fast->getNext() != nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    }
    return slow;
}

// Floyd's cycle-finding algorithm (also known as the "tortoise and the hare" algorithm) to detect the loop
bool LinkedList::hasLoop() const
{
    if (head == nullptr) return false;

    Node2* slow = head;
    Node2* fast = head;

    while (fast != nullptr && fast->getNext() != nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
        if (slow == fast) return true;
    }
    return false;
}

// find the Kth node from the end
Node2* LinkedList::findKthFromEnd(int k) const
{
    if (k < 1) return nullptr; // Edge case: invalid K

    Node2* slow = head;
    Node2* fast = head;

    // step 1: Advance 'fast' by k steps
    for (int i = 0; i < k; ++i)
    {
        if (fast == nullptr) return nullptr; // K > length of linkedlist
        fast = fast->getNext();
    }

    // step 2: Mover both slow and faster pointers until fast reaches the end (nullptr)
    while (fast != nullptr)
    {
        slow = slow->getNext();
        fast = fast->getNext();
    }

    // slow pointer now points to the kth node
    return slow;
}

// find and delete nodes with duplicate value
void LinkedList::removeDuplicates()
{
    if (head == nullptr) return;

    Node2* current = head;

    while (current != nullptr)
    {
        Node2* runner = current;
        while (runner->getNext() != nullptr)
        {
            if (runner->getNext()->getData() == current->getData())
            {
                // duplicate found: delete the node
                Node2* duplicate = runner->getNext();
                runner->setNext(duplicate->getNext());
                delete duplicate;
                --length;
            }
            else
            {
                runner = runner->getNext();
            }
        }
        current = current->getNext();
    }
}

// BinaryToDecimal
int LinkedList::binaryToDecimal() const
{
    Node2* current = head;
    int num = 0;

    while (current != nullptr)
    {
        num = num * 2 + current->getData();
        current = current->getNext();
    }

    return num;
}

// Partition List

void LinkedList::partitionList(const int limit)
{
    /*
     * GOAL:
     * Reorder the linked list so that all nodes with values < limit
     * come before nodes with values >= limit, while preserving the original relative order.
     *
     * STEPS:
     *
     * 1. Initialize two dummy head nodes for two partitions:
     *    - `lessHead`: for nodes with values < limit
     *    - `greaterHead`: for nodes with values >= limit
     *
     * 2. Create two tail pointers to build the two partitions:
     *    - `lessTail` starts at `lessHead`
     *    - `greaterTail` starts at `greaterHead`
     *
     * 3. Traverse the original list with a pointer `current`:
     *    a. For each node:
     *       - Detach it from the original list (`current->setNext(nullptr)`)
     *       - Append it to either:
     *         - `lessTail->next` if node->data < limit
     *         - `greaterTail->next` otherwise
     *       - Move the respective tail forward
     *
     * 4. After traversal:
     *    - Connect `lessTail->next` to `greaterHead->next`
     *    - Update the list's `head` to `lessHead->next`
     *
     * 5. Clean up:
     *    - Delete the dummy nodes (`lessHead` and `greaterHead`) to avoid memory leaks
     *
     * Notes:
     * - Original nodes are reused (no new data allocation).
     * - This method ensures O(n) time and O(1) extra space (excluding dummy pointers).
     */

    if (head == nullptr) return;

    // Dummy heads for two new partitions
    Node2* lessHead = new Node2(0); // Holds nodes < limit
    Node2* greaterHead = new Node2(0); // Holds nodes >= limit

    // Tails to append nodes to the above dummy heads
    Node2* lessTail = lessHead;
    Node2* greaterTail = greaterHead;

    // Traverse the original list
    Node2* current = head;

    while (current != nullptr)
    {
        Node2* nextNode = current->getNext(); // Save the next node
        current->setNext(nullptr); // Detach current node

        if (current->getData() < limit)
        {
            lessTail->setNext(current);
            lessTail = current;
        }
        else
        {
            greaterTail->setNext(current);
            greaterTail = current;
        }

        current = nextNode;
    }

    // Connect the two partitions
    lessTail->setNext(greaterHead->getNext());

    // Update the original head
    head = lessHead->getNext();

    // update the original tail
    tail = greaterTail;

    // Clean up dummy nodes
    delete lessHead;
    delete greaterHead;
}


// Reverse Between

void LinkedList::reverseBetween(int m, int n)
{
    /*
     * Reverse the linked list nodes between index m and n (inclusive).
     * Assumes m and n are valid (within bounds and m ≤ n).
     * The algorithm uses a dummy node to simplify edge cases,
     * especially when m = 0 (reversing from the head).
     */

    if (!head || m == n) return;

    Node2* dummy = new Node2(0);
    dummy->setNext(head);

    Node2* prev = dummy;

    // Step 1: Move prev to the node before index m
    for (int i = 0; i < m; ++i)
    {
        prev = prev->getNext();
    }

    // Step 2: Reverse sublist from m to n
    Node2* start = prev->getNext(); // node at position m
    Node2* then = start->getNext(); // node at position m + 1

    for (int i = 0; i < n - m; ++i)
    {
        start->setNext(then->getNext());
        then->setNext(prev->getNext());
        prev->setNext(then);
        then = start->getNext();
    }

    // Step 3: Update head if m == 0
    head = dummy->getNext();

    // step 4: update tail pointer
    Node2* temp = head;
    while (temp && temp->getNext()) temp = temp->getNext();
    tail = temp;

    delete dummy;
}

// swap pairs of nodes
void LinkedList::swapPairs()
{
    /*
     * Step-by-step explanation:
     *
     * 1. Edge Case Handling:
     *    - If the list is empty or contains only one node, there's nothing to swap.
     */
    if (!head || !head->getNext()) return;

    /*
     * 2. Dummy Node Initialization:
     *    - A dummy node is created and points to the head of the original list.
     *    - This simplifies edge cases when swapping the first pair (i.e., involving the head).
     *    - 'prev' pointer starts at dummy and will help re-link swapped nodes.
     */
    Node2* dummy = new Node2(0);
    dummy->setNext(head);
    Node2* prev = dummy;

    /*
     * 3. Main Loop to Traverse and Swap Pairs:
     *    - Iterate while both 'first' and 'second' nodes exist.
     *    - 'first' is the current node to be swapped.
     *    - 'second' is the node immediately after 'first'.
     *    - We perform the swap by updating the `.next` pointers in the correct order:
     *        a. first->next = second->next
     *        b. second->next = first
     *        c. prev->next = second
     *    - Then move 'prev' forward to 'first', which is now the second node after swapping.
     */
    while (prev->getNext() && prev->getNext()->getNext())
    {
        Node2* first = prev->getNext();
        Node2* second = first->getNext();

        // Perform the swap by re-linking next pointers
        first->setNext(second->getNext()); // Step a
        second->setNext(first); // Step b
        prev->setNext(second); // Step c

        // Move 'prev' forward for next pair
        prev = first;
    }

    /*
     * 4. Update the head pointer:
     *    - The new head is the next of dummy node (which points to the new head after swaps).
     */
    head = dummy->getNext();

    /*
     * 5. Update tail pointer
     *
     */
    Node2* temp = head;
    while (temp && temp->getNext()) temp = temp->getNext();
    tail = temp;

    /*
     * 5. Clean up:
     *    - Delete the  dummy node to prevent memory leak.
     */

    delete dummy;
}

// Accessors and Mutators
Node2* LinkedList::getHead() const { return head; }
Node2* LinkedList::getTail() const { return tail; }
int LinkedList::getLength() const { return length; }

void LinkedList::setHead(Node2* node) { head = node; }
void LinkedList::setTail(Node2* node) { tail = node; }
void LinkedList::setLength(int len) { length = len; }

void LinkedList::incrementLength() { ++length; }
void LinkedList::decrementLength() { --length; }

// copy constructor
LinkedList::LinkedList(const LinkedList& other)
{
    //
    if (other.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    else
    {
        head = new Node2(other.head->getData());
        Node2* current = head;
        Node2* otherCurrent = other.head->getNext();
        while (otherCurrent != nullptr)
        {
            current->setNext(new Node2(otherCurrent->getData()));
            current = current->getNext();
            otherCurrent = otherCurrent->getNext();
        }
        tail = current;
        length = other.length;
    }
}

// copy assignment operator
LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this != &other)
    {
        LinkedList::clear();
    }
    if (other.head == nullptr)
    {
        head = tail = nullptr;
        length = 0;
    }
    else
    {
        head = new Node2(other.head->getData());
        Node2* current = head;
        Node2* otherCurrent = other.head->getNext();
        while (otherCurrent != nullptr)
        {
            current->setNext(new Node2(otherCurrent->getData()));
            current = current->getNext();
            otherCurrent = otherCurrent->getNext();
        }
        tail = current;
        length = other.length;
    }

    return *this;
}


// move constructor
LinkedList::LinkedList(LinkedList&& other) noexcept : head(other.head), tail(other.tail), length(other.length)
{
    other.head = other.tail = nullptr;
    other.length = 0;
}

// move assignment operator
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept
{
    if (this != &other)
    {
        clear();
    }
    head = other.head;
    tail = other.tail;
    length = other.length;
    other.head = other.tail = nullptr;
    other.length = 0;

    return *this;
}


// Stream Insertion Operator: Outputs list elements space-separated
std::ostream& operator<<(std::ostream& stream, const LinkedList& ll)
{
    if (ll.length == 0)
    {
        stream << "{}"; // Output nothing for empty list
    }
    else
    {
        stream << "{";
        Node2* current = ll.getHead();
        while (current != nullptr)
        {
            stream << current->getData();
            current = current->getNext();
            if (current)
                stream << ", "; // Space between elements
        }
        stream << "}";
    }

    return stream;
}

// Stream Extraction Operator: Clears the list and reads integers from the stream
std::istream& operator>>(std::istream& stream, LinkedList& ll)
{
    // Clear existing list
    ll.clear();

    // Read integers and append to the list
    int value;
    while (stream >> value)
    {
        Node2* newNode = new Node2(value);
        if (ll.getHead() == nullptr)
        {
            ll.setHead(newNode);
            ll.setTail(newNode);
        }
        else
        {
            ll.getTail()->setNext(newNode);
            ll.setTail(newNode);
        }
        ll.incrementLength();
    }

    // Clear fail state if eof is not reached (e.g., non-integer input)
    if (!stream.eof())
        stream.clear();
    return stream;
}
