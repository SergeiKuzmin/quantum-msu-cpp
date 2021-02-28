#include <iostream>
#include "Node_list.h"
#include "funcs_for_list.h"

using namespace std;

int main()
{
    List *list = new List;
    list->first = nullptr;
    list->last = nullptr;
    push_back(list, 1.0);
    push_front(list, -1.0);
    push_back(list, 2.0);
    push_front(list, -2.0);
    Node *node = (list->first)->next;
    push_after(list, node, 45.0);
    push_before(list, node, 11.0);
    print(list);
    pop(list, node);
    print(list);
    clear(list);
    print(list);
    delete(list);
    return 0;
}
