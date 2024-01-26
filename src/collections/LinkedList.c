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
    //TODO : may want to allocate all nodes in an arena so it can be freed with a singel call
    while(list->length > 0){
        LinkedListNode* n = LinkedList_pop(list);
        Node_destroy(n);
    }
    return;
}


void LinkedList_insert(LinkedList* list, int index, int size, void* data){
    if(index > list->length){
        //error : index out of range
        printf("ERROR : insert index out of range\n");
        return;
    }
    if(index == 0) {
        //if the index point to the head of list, simply call push
        LinkedList_push(list, size, data);
        return;
    }
    if(index == list->length) {
        //if the index point to the end of list, simply call append
        LinkedList_append(list, size, data);
        return;
    }
    if(index <= list->length/2){
        // if the index lesser than than half the length of list start from itiration from the start
        LinkedListNode* new = Node_create(size, data);
        LinkedListNode* n = list->head->next;
        unsigned int i = 1;
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
        LinkedListNode* n = list->tail->pre;
        unsigned int i = list->length - 1;
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

void LinkedList_append(LinkedList* list, int size, void* data){
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

void  LinkedList_push(LinkedList* list, int size, void* data){
    if(list->length == 0){
        //an empty list
        list->head = list->tail = Node_create(size, data);
    }else{
        //a filled list
        LinkedListNode* n = Node_create(size, data);
        n->next = list->head;
        list->head->pre = n;
        list->head = n;
    }
    list->length++;
}

void LinkedList_delete(LinkedList* list, int index){
    if(list->length == 0) {
        printf("ERROR : list is empty\n");
        return;
    }
    if(index > list->length){
        //error : index out of range
        printf("ERROR : delete index out odf range\n");
        return;
    }
    if(index == list->length - 1) {
        //if the index point to the end of list, simply call append
        Node_destroy(LinkedList_pop(list));
        return;
    }
    if(index == 0){
        //if the index point to the end of list, simply call append
        Node_destroy(LinkedList_shift(list));
        return;
    }
    if(index <= list->length/2){
        // if the index lesser than than half the length of list start from itiration from the start
        LinkedListNode* n = list->head->next;
        int i = 1;
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
        LinkedListNode* n = list->tail->pre;
        unsigned int i = list->length - 2;
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

LinkedListNode* LinkedList_remove(LinkedList* list, int index){
    if(list->length == 0) {
        printf("ERROR : list is empty\n");
        return (void*)0;
    }
    
    if(index > list->length){
        //error : index out of range
        printf("ERROR : remove index out odf range\n");
        return 0;
    }
    if(index == 0){
        //if the index point to the end of list, simply call append
        return LinkedList_shift(list);
    }
    if(index == list->length - 1) {
        //if the index point to the end of list, simply call append
        return LinkedList_pop(list);
    }
    if(index <= list->length/2){
        // if the index lesser than than half the length of list start from itiration from the start
        LinkedListNode* n = list->head->next;
        int i = 1;
        while(n){
            if (i == index) {
                if(n->pre) n->pre->next = n->next;
                if(n->next) n->next->pre = n->pre;
                list->length--;
                return n;
            }
            n = n->next;
            i++;
        }
    }else if(index > list->length/2){
        // if the index greater than half the length of list start itiration from the end
        LinkedListNode* n = list->tail->pre;
        int i = list->length - 2;
        while(n){
            if (i == index) {
                if(n->pre) n->pre->next = n->next;
                if(n->next) n->next->pre = n->pre;
                list->length--;
                return n;
            }
            n = n->pre;
            i--;
        }
    }
    printf("ERROR : Unknown\n");
    return 0;
}

LinkedListNode* LinkedList_shift(LinkedList* list){
    if(list->length == 0) {
        printf("ERROR : list is empty\n");
        return (void*)0;
    }

    LinkedListNode* l = list->head;
    if(list->length == 1){
        list->head = list->tail = 0; 
    }else{
        list->head = l->next;
        list->head->pre = 0;
    }
    list->length--;
    l->next = 0;
    l->pre = 0;
    return l;
}

LinkedListNode* LinkedList_pop(LinkedList* list){
    if(list->length == 0) {
        printf("ERROR : list is empty\n");
        return (void*)0;
    }

    LinkedListNode* l = list->tail;
    if(list->length == 1){
        list->head = list->tail = 0; 
    }else{
        list->tail = l->pre;
        list->tail->next = 0;
    }
    list->length--;
    l->next = 0;
    l->pre = 0;
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
    printf("ERROR : unknown \n");
    return 0;
}

LinkedListNode* Node_create_empty(){
    return Node_create(0,0);
}

LinkedListNode* Node_create(int size, void* data) {
    LinkedListNode* n = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (!n) {
        fprintf(stderr, "Memory allocation failed for LinkedListNode\n");
        return 0;
    }

    if(size == 0){
        //if size is not defined return an empty node
        return n;
    }

    // Allocate memory for n->data
    n->data = malloc(size);
    if (!n->data) {
        fprintf(stderr, "Memory allocation failed for data\n");
        free(n);
        return 0;
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
