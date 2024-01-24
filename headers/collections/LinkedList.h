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

LinkedList LinkedList_create();
void LinkedList_destroy(LinkedList* list);

void LinkedList_insert(LinkedList* list, int index, int size, void* data);
void LinkedList_apend(LinkedList* list, int size, void* data);
void LinkedList_remove(LinkedList* list, int index);
LinkedListNode* LinkedList_pop(LinkedList* list);

LinkedListNode* LinkedList_get_node(LinkedList* list, int index);
LinkedListNode* Node_create_empty();
LinkedListNode* Node_create(int size, void* data);
void Node_destroy(LinkedListNode* node);


#define LinkedListAppend(list, val) \
    LinkedList_apend(list, sizeof(*val), (void*)(val));