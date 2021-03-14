#include "list.h"
#include <iostream>
#include <utility>

namespace std{
	ostream& operator<<(ostream &stream, const List &l)
	{
		for(auto val: l)
			stream << val << " ";
		/* Явный эквивалент циклу выше:
		 * for(List::Iterator iter = l.begin(); iter != l.end(); ++iter)
		 *     s << *iter << " ";
		 *
		 * Поэтому range-based цикл "for(auto val: l)" работает
		 * только потому, что у List объявлены метод begin() и end(),
		 * которые возвращают итератор, а у итератора присутствуют
		 * методы инкремента operator++, разыменовывания operator*
		 * и проверки на неравенство operator!=
		 */
		return stream;
	}
}

List::List(const List &other){
	/* Копирующий конструктор должен создать полную копию списка
	 * вместе со всеми узлами. Исходный список при этом остаётся
	 * неизменным.
	 */
	 this->clear();
	 for(auto val: other){
	    this->push_back(val);
	 }
}

List::List(List &&other){
	/* Перемещающий конструктор не производит копирования, то есть
	 * в любой момент времени существует только одна копия узлов
	 * списка. После перемещения other должен стать пустым списком.
	 */
	this->first = other.first;
	this->last = other.last;
	other.first = nullptr;
	other.last = nullptr;
}

void List::push_before(Iterator it, double value){
    Node *node = it.n;
    Node *new_node = new Node;
    new_node->value = value;
    this->cached_size++;

    if ((this->first == nullptr) && (this->last == nullptr)) {
        this->first = new_node;
        this->last = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
    } else {
        if (this->first == node) {
            new_node->prev = nullptr;
            new_node->next = node;
            this->first = new_node;
            node->prev = new_node;
        } else {
            new_node->prev = node->prev;
            new_node->next = node;
            (node->prev)->next = new_node;
            node->prev = new_node;
        }
    }
}

void List::push_after(Iterator it, double value){
    Node *node = it.n;
    Node *new_node = new Node;
    new_node->value = value;
    this->cached_size++;

    if ((this->first == nullptr) && (this->last == nullptr)) {
        this->first = new_node;
        this->last = new_node;
        new_node->prev = nullptr;
        new_node->next = nullptr;
    } else {
        if (this->last == node) {
            new_node->prev = node;
            new_node->next = nullptr;
            this->last = new_node;
            node->next = new_node;
        } else {
            new_node->next = node->next;
            new_node->prev = node;
            (node->next)->prev = new_node;
            node->next = new_node;
        }
    }
}

void List::pop(Iterator it){
    Node *node = it.n;
    this->cached_size--;
    if (node != nullptr){
        if ((this->first == node) && (this->last == node)){
            this->first = nullptr;
            this->last = nullptr;
        } else {
            if (this->first == node){
                this->first = node->next;
                (node->next)->prev = nullptr;
            } else {
                if (this->last == node){
                    this->last = node->prev;
                    (node->prev)->next = nullptr;
                } else {
                    (node->prev)->next = node->next;
                    (node->next)->prev = node->prev;
                }
            }
        }
    }
    delete node;
}

void List::push_back(double value){
    auto iter = this->last;
    List::push_after(iter, value);
}

void List::push_front(double value){
    auto iter = this->first;
    List::push_before(iter, value);
}

void List::pop_back(){
    List::pop(this->last);
}

void List::pop_front(){
    List::pop(this->first);
}

void List::clear(){
    Node *curr_ptr = this->first;
    while(curr_ptr != nullptr) {
        Node *next_ptr = curr_ptr->next;
        delete curr_ptr;
        curr_ptr = next_ptr;
    }
    this->first = nullptr;
    this->last = nullptr;
}
