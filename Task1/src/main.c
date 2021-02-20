#include <string.h>
#include "stack.h"

void print_help(void);

int main(int argc, char **argv) {
  printf("Simple program for basic manipulation of Stack (LIFO) data structure which supports only primitive types.\n\n");
  printf("******WARNING! You can create only one instance of a specific object type: int, double, char *.******\n\n");
  // Create instance of Stack
  int stack_size;
  printf("Size: ");
  scanf("%d", &stack_size);
  printf("\n");

  printf("%d\n", stack_size);

  Stack stack;

  if(create(&stack, stack_size))
    printf("Instance was created.\n");
  else {
    fprintf(stderr, "Instance could not be created.\n");
    exit(0);
  }

  int int1 = 12;
  push(&stack, TYPENAME_INT, &int1);
  int1 = 25;
  push(&stack, TYPENAME_INT, &int1);

  int type = TYPENAME_UNSPECIFIED;
  
  printf("See \'--help\' to read about a specific available command.\n\n");

  char command[256];
  
  while(1) {
    scanf("%s", command);
    
    if(strcmp(command, "--help") == 0) {
      print_help();
    } else if(!strcmp(command, "exit")) {
      break;
    } else if(!strcmp(command, "push")) {
      char *type_name;
      char str_val[512];
      int int_val;
      double dbl_val;
      printf("Data type: ");
      scanf("%s", type_name);
      printf("\n");
      if(!strcmp(type_name, "int")) {
	printf("Enter int value: ");
	scanf("%d", &int_val);
	push(&stack, TYPENAME_INT, &int_val);
      }
      else if(!strcmp(type_name, "double")) {
	printf("Enter double value: ");
	scanf("%lf", &dbl_val);
	push(&stack, TYPENAME_DOUBLE, &dbl_val);
      }
      else if(!strcmp(type_name, "string")) {
	printf("Enter string value: ");
	scanf("%s", str_val);
	push(&stack, TYPENAME_STRING, str_val);
      }
      else {
	fprintf(stderr, "Stack type must be specified.");
	exit(0);
      }
    } else if(!strcmp(command, "display")) {
      display_data(&stack);
    } else if(!strcmp(command, "size")) {
      printf("%d\n", size(&stack));
    }
  }
  system("cls");
  return 0;
}

void print_help(void) {
  puts("\nThese are commands for use:\n"
       "  create:   Create stack object with specific size.\n"
       "  push:     Push (add) data to the node.\n"
       "  pop:      Remove data from the node.\n"
       "  size:	    Print actual size of the stack.\n"
       "  cap:	    Print capacity of the stack.\n"
       "  resize:   Resize current stack.\n"
       "  display:  Display data of the stack.\n"
       "  exit:     Exit program.\n");
}
