#include <string.h>
#include "stack.h"

void print_help(void);

int main(int argc, char **argv) {
  printf("Simple program for basic manipulation of Stack (LIFO) data structure which supports only three types: int, double, string.\n\n");
  // Create instance of Stack
  int stack_size;
  printf("Enter stack size: ");
  scanf("%d", &stack_size);
  printf("\n");

  Stack stack;

  if(create(&stack, stack_size))
    printf("Instance was created.\n");
  else {
    fprintf(stderr, "Instance could not be created.\n");
    exit(0);
  }

  int type = TYPENAME_UNSPECIFIED;
  
  printf("See \'--help\' to read about a specific available command.\n\n");

  char command[256];
  
  while(1) {
    scanf("%s", command);
    
    if(strcmp(command, "--help") == 0) {
      print_help();
    }
    else if(!strcmp(command, "exit")) {
      break;
    }
    else if(!strcmp(command, "push")) {
      char *type_name;
      char str_val[512];
      int int_val;
      double dbl_val;
      printf("\nData type: ");
      scanf("%s", type_name);
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
	fprintf(stderr, "\nStack type must be specified.");
	exit(0);
      }
      display_data(&stack);
    }
    else if(!strcmp(command, "pop")) {
      pop(&stack);
      display_data(&stack);
    }
    else if(!strcmp(command, "display")) {
      display_data(&stack);
    }
    else if(!strcmp(command, "size")) {
      printf("\nStack size: %d", size(&stack));
    }
    else if(!strcmp(command, "cap")) {
      printf("\nCurrent capacity: %d", capacity(&stack));
    }
    else if(!strcmp(command, "resize")) {
      size_t resize_n;
      printf("Enter resize amount: ");
      scanf("%u", &resize_n);
      Resize(&stack, resize_n);
      display_data(&stack);
    }
    printf("\n--------------------------------------\n");
  }
  system("cls");
  return 0;
}

void print_help(void) {
  puts("\nThese are commands for use:\n"
       "  push:     Push (add) data with a specific type and value to the node.\n"
       "  pop:      Remove data from the node.\n"
       "  size:	    Print actual size of the stack.\n"
       "  cap:	    Print capacity of the stack.\n"
       "  resize:   Resize current stack.\n"
       "  display:  Display data of the stack.\n"
       "  exit:     Exit program.\n");
}
