#include <iostream>
#include "Node_list.h"
#include "funcs_for_list.h"

int push_before(List *l, Node *node, double value){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->next = node;
    if (l->first == node) {
        new_node->prev = nullptr;
        l->first = new_node;
    } else {
        new_node->prev = node->prev;
        node->prev = new_node;
    }
    return 0;
}

int push_after(List *l, Node *node, double value){
    Node *new_node = new Node;
    new_node->value = value;
    new_node->prev = node;
    if (l->last == node){
        new_node->next = nullptr;
        l->last = new_node;
    } else {
        new_node->next = node->next;
        node->next = new_node;
    }
    return 0;
}

int pop(List *l, Node *node){
    if (l->first == node){
        l->first = node->next;
        (node->next)->prev = nullptr;
    } else {
        if (l->last == node) {
            l->last = node->prev;
            (node->prev)->next = nullptr;
        } else {
            (node->prev)->next = node->next;
            (node->next)->prev = node->prev;
        }
    }
    delete node;
    return 0;
}

int push_back(List *l, double value){
    push_after(l, l->last, value);
    return 0;
}

int push_front(List *l, double value){
    push_before(l, l->first, value);
    return 0;
}

int pop_back(List *l){
    pop(l, l->first);
    return 0;
}
int pop_front(List *l){
    pop(l, l->last);
    return 0;
}

void print(List *l){
    Node *ptr = l->first;
    if (ptr == nullptr){
        std::cout << "Empty list" << std::endl;
    } else {
        do{
            std::cout << ptr->value << std::endl;
            ptr = ptr->next;
        }while (ptr != l->last);
    }
}

void clear(List *l){
    Node *ptr = l->first;
    do{
        if (ptr != l->last) {
            Node *cur_ptr = ptr;
            ptr = ptr->next;
            delete cur_ptr;
        }
    }while (ptr != l->last);
}
