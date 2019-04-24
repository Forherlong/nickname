#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nickname.h"

/* flag array length */
#define FLAG_VAR_ARRAY_LEN 5

const char *welcomeWords = "\n\n\t*** Welcome to nickname ! ***\n";
const char *warnningWords =
    "\n* If input is illegal, program will rewrite it with default value. *\n";
const char *constYESOrNo = " [Y/n] ";
const char *constYesOrNO = " [y/N] ";

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

void getInput(char *str, int length) {
  int len = 0;
  int oneChar;
  do {
    oneChar = getchar();
    *(str + len) = oneChar;
    ++len;
    /* todo: oneChar check  a....Z */
    /* read from cmd then clear buffer */
  } while (oneChar != '\n' && len < length);
  if (len < length) {
    *(str + len) = '\0';
  } else {
    *(str + len - 1) = '\0';
  }

  fflush(stdin);
}

char *toLowercase(const char *str) {
  int strLen = strlen(str);
  char *ret =
      (char *)malloc(sizeof(char) * (strLen + 1)); /* todo: free memory */
  for (int i = 0; i < strLen; ++i, ++str) {
    if (*str <= 'Z' && *str >= 'A') {
      *(ret + i) = *str + 32;
    } else {
      *(ret + i) = *str;
    }
  }
  *(ret + strLen) = '\0';
  return ret;
}

bool parseYesOrNo(const char *str) {
  bool ret = false;
  char *lowercaseStr = toLowercase(str);
  if (strcmp(lowercaseStr, "yes\n") == 0 || strcmp(lowercaseStr, "y\n") == 0 ||
      strcmp(lowercaseStr, "y") == 0 || strcmp(lowercaseStr, "yes") == 0 ||
      strcmp(lowercaseStr, "\n") == 0) {
    ret = true;
  }
  free(lowercaseStr);
  return ret;
}

void printOption(NICKNAMEOPTION *nicknameOption) {
  printf("uppercase : %d\n", nicknameOption->allowUpperChar);
  printf("number : %d\n", nicknameOption->allowNumber);
  printf("symbol : %d\n", nicknameOption->allowSymbool);
  printf("nickname length : %d\n", nicknameOption->nicknameLength);
  printf("number of nicknames : %d\n", nicknameOption->numberOfNickname);
  printf("save to file : %d\n", nicknameOption->saveToFile);
}

void askForOption(NICKNAMEOPTION *nicknameOption) {
  char upper[FLAG_VAR_ARRAY_LEN], number[FLAG_VAR_ARRAY_LEN],
      symbol[FLAG_VAR_ARRAY_LEN], nicknameLength[FLAG_VAR_ARRAY_LEN],
      numberOfNickname[FLAG_VAR_ARRAY_LEN], saveToFile[FLAG_VAR_ARRAY_LEN];

  printf("%s\n", welcomeWords);
  printf("%s\n", warnningWords);

  printf("Do you want uppercase letters?%s", constYESOrNo);
  fflush(stdout);
  getInput(upper, FLAG_VAR_ARRAY_LEN);

  printf("Do you want numbers?%s", constYESOrNo);
  fflush(stdout);
  getInput(number, FLAG_VAR_ARRAY_LEN);

  printf("Do you want symbols(!@#$^&*+_-./)?%s", constYESOrNo);
  fflush(stdout);
  getInput(symbol, FLAG_VAR_ARRAY_LEN);

  printf("How long do you want a nickname? [1~50] ");
  fflush(stdout);
  getInput(nicknameLength, FLAG_VAR_ARRAY_LEN);

  printf("How many nicknames do you want? [1~1000] ");
  fflush(stdout);
  getInput(numberOfNickname, FLAG_VAR_ARRAY_LEN);

  printf("Do you want to save nicknames to file?%s", constYesOrNO);
  fflush(stdout);
  getInput(saveToFile, FLAG_VAR_ARRAY_LEN);

  /* rewrite option value */
  nicknameOption->allowUpperChar = parseYesOrNo(upper);
  nicknameOption->allowNumber = parseYesOrNo(number);
  nicknameOption->allowSymbool = parseYesOrNo(symbol);
  nicknameOption->saveToFile = parseYesOrNo(saveToFile);

  int tempLength = atoi(nicknameLength);
  if ( tempLength != 0) {
    nicknameOption->nicknameLength = tempLength;
  }

  int tempNumber = atoi(numberOfNickname);
  if (tempNumber != 0) {
    nicknameOption->numberOfNickname = tempNumber;
  }
}

int main(int argc, char **argv) {
  if (isWithFlagValue(argc)) {
    /* 1. parse flag value. 2. define option params 3. invoke getNickname() */
  } else {
    /* 1. ask for option 2. define option params 3. invoke getNickname() */
    NICKNAMEOPTION nickNameOption = NICKNAMEOPTION_DEFAULT;
    askForOption(&nickNameOption);
    printOption(&nickNameOption);
    getNickName(&nickNameOption);
    fflush(stdout);
  }
}