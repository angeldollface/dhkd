#include <stdlib.h>
#include <stdio.h>

int command_is(const char* command){
  int result = 0;
  if (system(command) == 0){}
  else {
    result = 1;
  }
  return result;
}

int execute_command(const char* command){
  int result = 1;
  if (command_is(command) == 0){
    result = system(command);
  }
  else {}
  return result;
}

int main() {
  if (command_is("ls") == 0){
    printf("Success!\n");
  }
  else {
    printf("Failure!\n");
  }
  return 0;
}
