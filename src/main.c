#include <stdio.h>
#include <stdlib.h>
#include "nickname.h"

const char* welcomeWords = "\t*** Welcome to nickname ! ***\n";

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

bool isWithFlagValue(int argc) { return argc >= 2; }

void getInput(char* str, int length) {
  int len = 0;
  int oneChar;
  do {
    oneChar = getchar();
    str[len] = oneChar;
    ++len;
  } while (oneChar != '\n' && len < length);
}

int main(int argc, char** argv) {
  if (isWithFlagValue(argc)) {
    /* 1. parse flag value. 2. define option params 3. invoke getNickname() */

  } else {
    /* 1. ask for option 2. define option params 3. invoke getNickname() */
    printf("\n");
    printf("%s\n", welcomeWords);
    char number[3], symbol[3], upper[3];
    printf("Do you want uppercase letters?" " [y/N] ");
    fflush(stdout);
    getInput(upper, 3);
    printf("Do you want number?" " [y/N] ");
    fflush(stdout);
    getInput(number, 3);
    printf("Do you want uppercase symbol(!@#$^&*+_-./)?" " [y/N] ");
    fflush(stdout);
    getInput(symbol, 3);

    // printf("%s %s %s", upper, number, symbol);
    fflush(stdout);
  }

  NICKNAMEOPTION nickNameOption = NICKNAMEOPTION_DEFAULT;
  nickNameOption.allowNumber = true;
  getNickName(&nickNameOption);
}