#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
#include <windows.h>
#include <dirent.h>
#include <string.h>

void print_elems_full_path(char *f_name);
void print_folder_elems(char *f_name);
//void get_folder_info(char *f_name, int (*operation)(char *));
void get_full_path(char *, char *, char **);

enum {COUNT_ELEMS, GET_FULL_PATH};

int main(int argc, char *argv[]) {
  if(argc < 2) {
    fprintf(stderr, "Folder path's does not specify.\n");
    exit(0);
  }

  char *f_name = *++argv;
  //pthread_t thread1, thread2;
  

  if((d = opendir(f_name)) != NULL) {
    int elems = 0;
    while((dir = readdir(d)) != NULL) {
      char *dir_name = dir->d_name;
      if(!strcmp(dir_name, "."))
	continue;
      if(!strcmp(dir_name, ".."))
	continue;
      char *fp;
      get_full_path(f_name, dir_name, &fp);
      printf("%s\n", fp);
      elems++;
      free(fp);
    }
    printf("\nElements in folder: %d", elems);
    closedir(d);
  }
  return 0;
}

void get_full_path(char *f_name, char *dir_name, char **fullPath) {
  *fullPath = (char *)malloc(strlen(f_name) + strlen(dir_name) + 2);
  strcpy(*fullPath, f_name);
  strcat(*fullPath, "\\\\");
  strcat(*fullPath, dir_name);
}

/* void get_folder_info(char *f_name, int (*operation)(char *)) { */

/* } */

void print_folder_elems(char *f_name) {
  DIR *d;
  struct dirent *dir;
  if((d = opendir(f_name)) != NULL) {
  int elems = 0;
  while((dir = readdir(d)) != NULL) {
    char *dir_name = dir->d_name;
    if(!strcmp(dir_name, "."))
      continue;
    if(!strcmp(dir_name, ".."))
      continue;
    elems++;
  }
  printf("Folder contains %d elements.\n", elems);
  closedir(d);  
}

void print_elems_full_path(char *f_name) {
  DIR *d;
  struct dirent *dir;
  if((d = opendir(f_name)) != NULL) {
    char *fullPath;
    while((dir = readdir(d)) != NULL) {
      char *dir_name = dir->d_name;
      if(!strcmp(dir_name, "."))
	continue;
      if(!strcmp(dir_name, ".."))
	continue;
      get_full_path(f_name, dir_name);
      printf("[%s]\n", fullPath);
      free(fullPath);
    }
  }
  closedir(d);
}
