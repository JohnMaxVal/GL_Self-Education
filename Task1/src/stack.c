#include "stack.h"

static int stack_type = 0;

void initLinkedList(Stack *, size_t);

BOOL create(Stack *stack, size_t sz) {
  initLinkedList(stack, sz);
  return !stack ? FALSE : TRUE;
}

void addHead(LinkedList* list, int type, void* data) {
  if(list->capacity >= list->size) {
    fprintf(stderr, "No more nodes could be created, please resize your stack.");
    return;
  }
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->type = type;
  if(list->head == NULL) {
    list->tail = node;
    node->next = NULL;
  } else {
    node->next = list->head;
  }
  list->head = node;
  list->capacity++;
}

void initLinkedList(LinkedList* list, size_t sz) {
  list->head = NULL;
  list->tail = NULL;
  list->capacity = 0;
  list->size = sz;
}

void push(Stack* stack, int type, void *data) {
  addHead(stack, type, data);
}

void *pop(Stack* stack) {
  Node* node = stack->head;
  if(node == NULL) {
    return NULL;
  } else if(node == stack->tail) {
    stack->head = stack->tail = NULL;
    stack->capacity--;
    void *data = node->data;
    return data;
  } else {
    stack->head = stack->head->next;
    stack->capacity--;
    void *data = node->data;
    free(node);
    return data;
  }
}

int capacity(Stack* stack) {
  if(!stack) {
    fprintf(stderr, "capacity: Argument is not defined.\n");
    return -1;
  }
  return stack->capacity;
}

size_t size(const Stack* stack) {
  return stack->size;
}

void Resize(Stack* stack, size_t n) {
  if(stack->size < n || stack->capacity < n)
    stack->size = n;
  else {
    while(stack->capacity != n) {
      pop(stack);
    }
    stack->size = n;
  }
}

void display_data(const Stack* stack) {
  printf("Display stack data:\n");
  Node* node = stack->head;
  while(node != NULL) {
    switch(node->type) {
    case TYPENAME_INT:
      printf("- %d\n", *((int*)node->data));
      break;
    case TYPENAME_DOUBLE:
      printf("- %lf\n",*((double*)node->data));
      break;
    case TYPENAME_STRING:
      printf("- %s\n", (char *)node->data);
    }
    node = node->next;
  }
}
