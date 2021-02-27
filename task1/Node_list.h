#ifndef NODE_LIST
#define NODE_LIST

typedef struct Node
{
    double value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct List
{
    struct Node *first;
    struct Node *last;
} List;

#endif
