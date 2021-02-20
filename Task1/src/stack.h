#include <stdlib.h>
#include <stdio.h>

enum t_typename
  {
   TYPENAME_INT,
   TYPENAME_DOUBLE,
   TYPENAME_STRING,
   TYPENAME_UNSPECIFIED
  };

typedef unsigned char BOOL;

enum {FALSE, TRUE};

typedef struct node {
  void *data;
  int type;
  struct node *next;
} Node;

typedef struct _linkedList {
  Node* head; // first node
  Node* tail; // last node
  Node* curr;
  size_t capacity;
  size_t size;
} LinkedList;

typedef LinkedList Stack;

BOOL create(Stack *, size_t sz);
void push(Stack *, int, void *);
void *pop(Stack *);
int capacity(Stack *);
size_t size(const Stack*);
void Resize(Stack*, size_t);
void display_data(const Stack*);
