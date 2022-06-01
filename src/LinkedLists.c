/**
 * @author qtf0x
 * @date 27.05.2022
 *
 * @brief C linked list implementation with basic functionality.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* next;
} node_t;

/**
 * @brief prints out all the nodes in a list
 *
 * @param head printing will start from this node
 */
void print_list(node_t* head);

/**
 * @brief adds a node to the end of a list
 *
 * @param head any non-NULL node in the list
 * @param val the value to put in the new node
 */
void push_back(node_t** head, int val);

/**
 * @brief adds a node to the beginning of a list
 *
 * @param head double pointer to the head of a list
 * @param val the value to put in the new node
 */
void push_front(node_t** head, int val);

/**
 * @brief removes a node from the end of a list
 *
 * @param head any non-NULL node in the list
 * @return int the value stored in the popped node
 */
int pop_back(node_t** head);

/**
 * @brief removes a node from the beginning of a list
 *
 * @param head double pointer to the head of a list
 * @return int the value stored in the popped node
 */
int pop_front(node_t** head);

/**
 * @brief removes a specific node from a list
 *
 * @param head double pointer to the head of a list
 * @param n index of the node to remove
 * @return int the value stored in the removed node
 */
int remove_by_index(node_t** head, int n);

/**
 * @brief removes the first node with the specified value from a list
 *
 * @param head double pointer to the head of a list
 * @param val value of the node to remove
 * @return int the value stored in the removed node, -1 if error
 */
int remove_by_value(node_t** head, int val);

int main() {
    /**
     * Notice that any of the functions which might update the pointer to the
     * head of the list must be passed as a double pointer to it. This reveals a
     * dirty little secret of C: Pointers are actually passed to functions by
     * reference! The function receives a copy of the memory address held by a
     * pointer argument. This is fine if all we want to do is update what is at
     * that memory address. However, if we want to point that pointer argument
     * at a different memory location, there is no way to do that without using
     * a pointer to that pointer.
     */

    // creating the first node in the list
    node_t* head = NULL;

    // test functions on bad input
    node_t** phead = NULL;
    pop_front(phead);
    pop_back(phead);
    remove_by_index(phead, -1);
    remove_by_index(phead, 0);
    remove_by_index(phead, 1);
    remove_by_value(phead, 1);

    print_list(head);
    printf("\n");

    // test functions on empty list
    pop_front(&head);
    pop_back(&head);
    remove_by_index(&head, -1);
    remove_by_index(&head, 0);
    remove_by_index(&head, 1);
    remove_by_value(&head, 1);

    // add some values to the list
    push_back(&head, 0);
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);
    push_back(&head, 4);

    print_list(head);
    printf("\n");

    // remove front, back, and middle of list
    pop_front(&head);
    pop_back(&head);
    remove_by_index(&head, 1);

    print_list(head);
    printf("\n");

    // remove by index correctly
    remove_by_index(&head, 1);
    remove_by_index(&head, 0);

    print_list(head);
    printf("\n");

    push_front(&head, 1);
    push_back(&head, 3);

    print_list(head);
    printf("\n");

    // remove by index incorrectly
    remove_by_index(&head, 0);
    remove_by_index(&head, 1);

    print_list(head);
    printf("\n");

    // remove by value length 1
    remove_by_value(&head, 3);

    print_list(head);
    printf("\n");

    push_front(&head, 0);
    push_front(&head, 1);
    push_front(&head, 2);
    push_front(&head, 3);
    push_front(&head, 4);

    print_list(head);
    printf("\n");

    // remove by value bad search
    remove_by_value(&head, 5);

    print_list(head);
    printf("\n");

    // remove by value test
    remove_by_value(&head, 4);
    remove_by_value(&head, 2);
    remove_by_value(&head, 0);

    print_list(head);
    printf("\n");

    return 0;
}

void print_list(node_t* head) {
    if (head == NULL) {
        printf("empty\n");
        return;
    }

    node_t* current = head;

    // iterate over list
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void push_back(node_t** head, int val) {
    // check for bad input
    if (head == NULL) {
        return;
    }

    // empty list
    if (*head == NULL) {
        // allocate and verify memory
        *head = malloc(sizeof(node_t));
        if (*head == NULL) {
            return;
        }

        // assign fields
        (*head)->val = val;
        (*head)->next = NULL;

        return;
    }

    node_t* current = *head;

    // iterate over list
    while (current->next != NULL) {
        current = current->next;
    }

    // allocate and verify memory
    current->next = malloc(sizeof(node_t));
    if (current->next == NULL) {
        return;
    }

    // assign fields
    current->next->val = val;
    current->next->next = NULL;
}

void push_front(node_t** head, int val) {
    // check for bad input
    if (head == NULL) {
        return;
    }

    // allocate and verify memory
    node_t* new_node = malloc(sizeof(new_node));
    if (new_node == NULL) {
        return;
    }

    // assign fields
    new_node->val = val;
    new_node->next = *head;

    // move list head
    *head = new_node;
}

int pop_back(node_t** head) {
    // check if list empty or length 1
    if (head == NULL || *head == NULL) {
        return -1;
    } else if ((*head)->next == NULL) {
        // save old head/tail value
        int old_tail_val = (*head)->val;

        // free memory, effectively emptying the list
        free(*head);
        *head = NULL;

        return old_tail_val;
    }

    // iterate over list to find second-to-last node
    node_t* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // save old tail value
    int old_tail_val = current->next->val;

    // free memory and set nullify link to old tail
    free(current->next);
    current->next = NULL;

    return old_tail_val;
}

int pop_front(node_t** head) {
    // check for bad input or empty list
    if (head == NULL || *head == NULL) {
        return -1;
    }

    // save old head fields
    int old_head_val = (*head)->val;
    node_t* new_head = (*head)->next;

    // free memory and move list head
    free(*head);
    *head = new_head;

    return old_head_val;
}

int remove_by_index(node_t** head, int n) {
    // check for bad input or empty list
    if (head == NULL || *head == NULL) {
        return -1;
    }

    // index 0 is the head node
    if (n == 0) {
        return pop_front(head);
    }

    // iterate over list to find node before node to remove
    node_t* current = *head;
    for (int i = n - 1; i > 0; --i) {
        // check for out-of-bounds
        if (current->next == NULL) {
            return -1;
        }

        current = current->next;
    }

    // check for out-of-bounds
    if (current->next == NULL) {
        return -1;
    }

    // save fields from node to remove
    int old_val = current->next->val;
    node_t* old_next = current->next->next;

    // free memory, point to one past removed node
    free(current->next);
    current->next = old_next;

    return old_val;
}

int remove_by_value(node_t** head, int val) {
    // check for bad input or empty list
    if (head == NULL || *head == NULL) {
        return -1;
    }

    // if the head node is the one to remove, use pop_front()
    if ((*head)->val == val) {
        return pop_front(head);
    }

    // iterate over list to find node before node to remove
    node_t* current = *head;
    while (current->next != NULL && current->next->val != val) {
        current = current->next;
    }

    // we reached the end of the list without finding node to remove
    if (current->next == NULL) {
        return -1;
    }

    // save fields for node to remove
    int old_val = current->next->val;
    node_t* old_next = current->next->next;

    // free memory, point to one past removed node
    free(current->next);
    current->next = old_next;

    return old_val;
}
