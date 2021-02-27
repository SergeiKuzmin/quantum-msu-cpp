#include "Node_list.h"

int push_before(List *l, Node *node, double value);
int push_after(List *l, Node *node, double value);
int pop(List *l, Node *node);
int push_back(List *l, double value);
int push_front(List *l, double value);
int pop_back(List *l);
int pop_front(List *l);
void print(List *l);
void clear(List *l);
