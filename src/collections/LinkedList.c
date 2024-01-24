/**
 * @file LinkedList.c
 * @brief 
 * @date 2023-11-16
 * @author aimrane-dr aimranedr@gmail.com
*/

// INCLUDES
#include "collections/LinkedList.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// FUNCTIONS DEFINITIONS

LinkedList LinkedList_create(){
    LinkedList l = {
        .head = 0,
        .tail = 0,
        .length = 0
    };
    return l;
}

void LinkedList_destroy(LinkedList* list){
    //if list is empty
    if(!list->head) {
        list->length = 0;
        list->tail = 0;
        return;
    }

    //if list has node(s)
    LinkedListNode* n = list->head;
    do{
        LinkedListNode* next = n->next;
        Node_destroy(n);
        n = next;
    }while(n);
}


void LinkedList_insert(LinkedList* list, int index, int size, void* data){
    if(index > list->length){
        //error : index out of range
        return;
    }
    if(index == list->length) {
        //if the index point to the end of list, simply call append
        LinkedList_apend(list, size, data);
        return;
    }
    if(index <= list->length/2){
        // if the index lesser than than half the length of list start from itiration from the start
        LinkedListNode* new = Node_create(size, data);
        LinkedListNode* n = list->head;
        unsigned int i = 0;
        while(n){
            if (i == index) {
                n->pre->next = new;
                new->pre = n->pre;
                new->next = n;
                n->pre = new;
                list->length++;
                break;
            }
            n = n->next;
            i++;
        }
    }else if(index > list->length/2){
        // if the index greater than half the length of list start itiration from the end
        LinkedListNode* new = Node_create(size, data);
        LinkedListNode* n = list->tail;
        unsigned int i = list->length -1;
        while(n){
            if (i == index) {
                n->pre->next = new;
                new->pre = n->pre;
                new->next = n;
                n->pre = new;
                list->length++;
                break;
            }
            n = n->pre;
            i--;
        }
    }
}

void LinkedList_apend(LinkedList* list, int size, void* data){
    if(list->length == 0){
        //an empty list
        list->head = list->tail = Node_create(size, data);
    }else{
        //a filled list
        list->tail->next = Node_create(size, data);
        list->tail->next->pre = list->tail;
        list->tail = list->tail->next;
    }
    list->length++;
}

void LinkedList_remove(LinkedList* list, int index){
    if(index > list->length){
        //error : index out of range
        return;
    }
    if(index == list->length - 1) {
        //if the index point to the end of list, simply call append
        LinkedList_pop(list);
        return;
    }

    if(index <= list->length/2){
        // if the index lesser than than half the length of list start from itiration from the start
        LinkedListNode* n = list->head;
        unsigned int i = 0;
        while(n){
            if (i == index) {
                n->pre->next = n->next;
                n->next->pre = n->pre;
                Node_destroy(n);
                list->length--;
                break;
            }
            n = n->next;
            i++;
        }
    }else if(index > list->length/2){
        // if the index greater than half the length of list start itiration from the end
        LinkedListNode* n = list->tail;
        unsigned int i = list->length -1;
        while(n){
            if (i == index) {
                n->pre->next = n->next;
                n->next->pre = n->pre;
                Node_destroy(n);
                list->length--;
                break;
            }
            n = n->pre;
            i--;
        }
    }
}

LinkedListNode* LinkedList_pop(LinkedList* list){
    LinkedListNode* l = list->tail;
    list->tail = list->tail->pre;
    list->tail->next = 0;
    return l;
}

LinkedListNode* LinkedList_get_node(LinkedList* list, int index){
    unsigned int half_len = list->length/2; 
    if(index < half_len){
        unsigned int i = 0;
        LinkedListNode* n = list->head;
        while(n){
            if (i == index) return n;
            n = n->next;
            i++;
        }
    }else if(index >= half_len){
        unsigned int i = list->length - 1;
        LinkedListNode* n = list->tail;
        while(n){
            if (i == index) return n;
            n = n->pre;
            i--;
        }
    }else if (index >= list->length){
        //error : out of range
        printf("ERROR : out of rang\n");
        return 0;
    }
    printf("ERROR : unknown\n");
    return 0;
}

LinkedListNode* Node_create_empty(){
    LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    return n ? n : (void*)0;
}

LinkedListNode* Node_create(int size, void* data) {
    LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (!n) {
        fprintf(stderr, "Memory allocation failed for LinkedListNode\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for n->data
    n->data = malloc(size);
    if (!n->data) {
        fprintf(stderr, "Memory allocation failed for data\n");
        free(n);
        exit(EXIT_FAILURE);
    }

    // Copy data into n->data
    memcpy(n->data, data, size);

    n->next = NULL;
    n->pre = NULL;

    return n;
}


void Node_destroy(LinkedListNode* node){
    if(!node) return;
    if(node->data) free(node->data);
    node->data = 0;
    node->next = 0;
    node->pre = 0;
    free(node);
    return;
}
