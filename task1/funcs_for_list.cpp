#include <iostream>
#include "Node_list.h"
#include "funcs_for_list.h"

int push_before(List *l, Node *node, double value){
    Node *new_node = new Node;
    new_node->value = value;

    if ((l->first == nullptr) && (l->last == nullptr)) {
        l->first = new_node;
        l->last = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
    } else {
        if (l->first == node) {
            new_node->prev = nullptr;
            new_node->next = node;
            l->first = new_node;
            node->prev = new_node;
        } else {
            new_node->prev = node->prev;
            new_node->next = node;
            (node->prev)->next = new_node;
            node->prev = new_node;
        }
    }
    return 0;
}

int push_after(List *l, Node *node, double value){
    Node *new_node = new Node;
    new_node->value = value;

    if ((l->first == nullptr) && (l->last == nullptr)) {
        l->first = new_node;
        l->last = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
    } else {
        if (l->last == node) {
            new_node->prev = node;
            new_node->next = nullptr;
            l->last = new_node;
            node->next = new_node;
        } else {
            new_node->next = node->next;
            new_node->prev = node;
            (node->next)->prev = new_node;
            node->next = new_node;
        }
    }
    return 0;
}

int pop(List *l, Node *node){
    if (node != nullptr){
        if ((l->first == node) && (l->last == node)){
            l->first = nullptr;
            l->last = nullptr;
        } else {
            if (l->first == node){
                l->first = node->next;
                (node->next)->prev = nullptr;
            } else {
                if (l->last == node){
                    l->last = node->prev;
                    (node->prev)->next = nullptr;
                } else {
                    (node->prev)->next = node->next;
                    (node->next)->prev = node->prev;
                }
            }
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
    pop(l, l->last);
    return 0;
}

int pop_front(List *l){
    pop(l, l->first);
    return 0;
}

void print(List *l){
    Node *ptr = l->first;
    if (ptr == nullptr){
        std::cout << "Empty list" << std::endl;
    } else {
        std::cout << ptr->value << " ";
        do{
            ptr = ptr->next;
            std::cout << ptr->value << " ";
        }while (ptr != l->last);
    }
    std::cout << std::endl;
}

void clear(List *l) {
    Node *curr_ptr = l->first;
    while(curr_ptr != nullptr) {
        Node *next_ptr = curr_ptr->next;
        delete curr_ptr;
        curr_ptr = next_ptr;
    }
    l->first = nullptr;
    l->last = nullptr;
}
