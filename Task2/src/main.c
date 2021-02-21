#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef long long fib_64;
typedef unsigned char bool;

enum {FALSE, TRUE};
enum seq_type {DEFAULT, NEGA};

fib_64 fib(int n);
void print_help(void);
void get_command_line(char *);
bool parse(char *, int*, int*);

int main(int argc, char *argv[]) {
  printf("Calcualte the summary of n-th numbers.\n");
  printf("See \'--help\' for available commands.\n\n");

  char commands[256];
 
  while(1) {
    int n = 0;
    int type = DEFAULT;
    fib_64 sum;
    
    get_command_line(commands);
    if(parse(commands, &n, &type) == FALSE)
      return -1;

    if(n < 2) {
      fprintf(stderr, "n must be greater that 2.\n");
      return -1;
    }
    
    sum = fib(n);
    printf("The sum of Fibanacci sequence = %ll", sum);
  }
  return 0;
}

fib_64 fib(int n) {
  if(n <= 1)
    return n;
  else
    return fib(n - 2) + fib(n - 1);
}

void get_command_line(char *commands) {
  int c;
  int i = 0;

  while((c = getchar()) != EOF && c != '\n')
    commands[i++] = c;
  if(c == '\n')
    commands[i] = '\0';
  
}

bool parse(char *cmd, int* n, int* type) {
  if(!strcmp(cmd, "exit")) {
    return FALSE;
  }

  int i = 0;
  int c;
  while(cmd[i] != '\0') {
    if(cmd[i] == '-') {
      switch(cmd[++i]) {
      case 'n':
	while(cmd[++i] == ' ')
	  ;
	for(*n = 0; isdigit(cmd[i]); i++)
	  *n = 10 * *n + (cmd[i] - '0');
	break;
      case 'o':
	*type = NEGA;
	break;
      default:
	break;
      }
    }
  }
  return TRUE;
}

void print_help(void) {
  puts("\n"
       " -n [:amount]    Amount of numbers to calculate.\n"
       " -o              Yield the sequence of \'negafibonacci\' numbers.\n"
       " exit            Close the program.\n"
       "\n");
}
