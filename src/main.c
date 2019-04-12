#include <stdio.h>
#include <stdlib.h>
#include "nickname.h"

/* flag array length */
#define FLAG_VAR_ARRAY_LEN 3

const char* welcomeWords = "\t*** Welcome to nickname ! ***\n";
const char* constYesOrNo = " [y/N] ";

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
    /* todo: check if input char qualified */
  } while (oneChar != '\n' && len < length);
}

void askForOption(NICKNAMEOPTION* nickNameOption) {
  char upper[FLAG_VAR_ARRAY_LEN], number[FLAG_VAR_ARRAY_LEN],
      symbol[FLAG_VAR_ARRAY_LEN], nicknameLength[FLAG_VAR_ARRAY_LEN],
      numberOfNickname[FLAG_VAR_ARRAY_LEN], saveToFile[FLAG_VAR_ARRAY_LEN];

  printf("\n");
  printf("%s\n", welcomeWords);

  printf("Do you want uppercase letters?%s", constYesOrNo);
  fflush(stdout);
  getInput(upper, FLAG_VAR_ARRAY_LEN);

  printf("Do you want number?%s", constYesOrNo);
  fflush(stdout);
  getInput(number, FLAG_VAR_ARRAY_LEN);

  printf("Do you want symbol(!@#$^&*+_-./)?%s", constYesOrNo);
  fflush(stdout);
  getInput(symbol, FLAG_VAR_ARRAY_LEN);

  printf("How long do you want a nickname?%s", constYesOrNo);
  fflush(stdout);
  getInput(nicknameLength, FLAG_VAR_ARRAY_LEN);

  printf("How many nicknames do you want? [default %d] ",
         nickNameOption->numberOfNickname);
  fflush(stdout);
  getInput(numberOfNickname, FLAG_VAR_ARRAY_LEN);

  printf("Do you want to save nicknames to file? [default NO] ");
  fflush(stdout);
  getInput(saveToFile, FLAG_VAR_ARRAY_LEN);
}

int main(int argc, char** argv) {
  if (isWithFlagValue(argc)) {
    /* 1. parse flag value. 2. define option params 3. invoke getNickname() */

  } else {
    /* 1. ask for option 2. define option params 3. invoke getNickname() */
    NICKNAMEOPTION nickNameOption = NICKNAMEOPTION_DEFAULT;
    askForOption(&nickNameOption);
    getNickName(&nickNameOption);
    fflush(stdout);
  }
}