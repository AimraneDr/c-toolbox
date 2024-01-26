/**
 * @file LinkedList.h
 * @brief Description
 * @date 2023-11-16
 * @author aimrane-dr aimranedr@gmail.com
*/

// INCLUDES

//  DEFINES


typedef struct LinkedListNode
{
    struct LinkedListNode *next;
    struct LinkedListNode *pre;

    void *data;
} LinkedListNode;

typedef struct LinkedList
{
    LinkedListNode *head;
    LinkedListNode *tail;

    unsigned int length;
} LinkedList;

//  FUNCTIONS
/**
 * @brief create an empty linked list
 * @return LinkedList : a new list
*/
LinkedList LinkedList_create();
/**
 * @brief free the space allocated by a list
*/
void LinkedList_destroy(LinkedList* list);

/**
 * @brief insert a node element at a specific index
*/
void LinkedList_insert(LinkedList* list, int index, int size, void* data);
/**
 * @brief insert a node element at the tail of the list
*/
void LinkedList_append(LinkedList* list, int size, void* data);
/**
 * insert a node element at the head of the list
*/
void LinkedList_push(LinkedList* list, int size, void* data);

/**
 * @brief delete a specific node element by index 
*/
void LinkedList_delete(LinkedList* list, int index);
/**
 * @brief remove a specific node element by index from the list
 * @note the returned node needs to be destroyed manually by calling Node_destroy() 
 * @return LinkedListNode* : a ptr to the removed node 
*/
LinkedListNode* LinkedList_remove(LinkedList* list, int index);
/**
 * @brief remove the tail node element from the list
 * @note the returned node needs to be destroyed manually by calling Node_destroy() 
 * @return LinkedListNode* : a ptr to the removed node 
*/
LinkedListNode* LinkedList_pop(LinkedList* list);
/**
 * @brief remove the head node element from the list
 * @note the returned node needs to be destroyed manually by calling Node_destroy() 
 * @return LinkedListNode* : a ptr to the removed node 
*/
LinkedListNode* LinkedList_shift(LinkedList* list);
/**
 * @brief get the node element at the specific index
 * @return LinedListNode : a ptr to the fetshed node
*/
LinkedListNode* LinkedList_get_node(LinkedList* list, int index);


/**
 * @brief create a zeroed out new node
 * @return LinkedListNode* : ptr to the new node
*/
LinkedListNode* Node_create_empty();

/**
 * @brief create an initialize a new node
 * @return LinkedListNode* : ptr to the new node
*/
LinkedListNode* Node_create(int size, void* data);

/**
 * @brief free up space allocated by node
*/
void Node_destroy(LinkedListNode* node);


#define LinkedListAppend(list_ptr, val_ptr) \
    LinkedList_append(list_ptr, sizeof(*val_ptr), (void*)(val_ptr));

#define LinkedListInsert(list_ptr, val_ptr, index) \
    LinkedList_insert(list_ptr, index, sizeof(*val_ptr), (void*)(val_ptr));

#define LinkedListPush(list_ptr, val_ptr) \
    LinkedList_push(list_ptr, sizeof(*val_ptr), (void*)(val_ptr));