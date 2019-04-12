#include <stdio.h>
#include <stdlib.h>
#include "nickname.h"

void help() {
  printf("usage:\n");
  printf("\t-n: need number,default no number\n");
  printf("\t-u: need uppdercase,default lowercase\n");
  printf("\t-s: need symbol,default no symbol(!@#$^&*+_-./)\n");
  printf("\t-N: generate specified number nickname\n");
  printf("\t-l: specified number of nickname's length\n");
  printf("\t-h: print help infomation\n");
  printf("\t-f: save result to file\n");
}

int main(int argc, char **argv) {
  printf("hello, world.\n");
  for (int i = 0; i < argc; ++i) {
    printf("i = %d, value = %s\n", i, *argv++);
  }
  help();
  NICKNAMEOPTION nickNameOption = NICKNAMEOPTION_DEFAULT;
  getNickName(&nickNameOption);
}