#define DMU_H
#ifndef DMU_H

#include <string.h>
#include <stdio.h>

struct DMUEntity {
  const char * key;
  const char * value;
};

struct DMUEntry parse_string(char line[]){
  struct DMUEntry entry;
  int key_start = 0;
  int key_end = 0;
  int value_start = 0;
  int value_end = strlen(line) - 1;
  for (int i = 0; i < strlen(line); i++){
    if (line[i] == "="){
      key_end = i -1;
    }
    else if (line[i] == ">"){
      value_start = i + 1;
    }
    else {}
  }
  int key_length = key_end - key_start;
  int value_length = value_end - value_start;
  char key[key_length];
  char value[value_length];
  strncpy(key, line+key_start, key_length);
  strncpy(value, line+value_start, value_length);
  entry.key = key;
  entry.value = value;
  return entry;
}

void test_parse(){
  char line[] = "'name'=>'val'";
  struct DMUEntry entry;
  entry = parse_string(line);
  printf("%s\n", entry.key);
  printf("%s\n", entry.value);
}

#endif
