#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nickname.h"

/* flag array length */
#define FLAG_VAR_ARRAY_LEN 3

const char *welcomeWords = "\n\n\t*** Welcome to nickname ! ***\n";
const char *warnningWords =
    "\n*If input is illegal, program will repalce it with default value.*\n";
const char *constYesOrNo = " [y/N] ";

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
    str[len] = oneChar;
    ++len;
  } while (oneChar != '\n' && len < length);
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

bool parseNumber(const char *str, double *num) {
  bool ret = false;
  double tempNum = 1;
  int place = 1;
  int strLen = sizeof(str) / sizeof(char);
  while (*str != '\0') ++str;

  for (int i = strLen; i >= 0; --i) {
    if (*str >= 48 && *str <= 57) {
      tempNum = tempNum + place * *str;
      *num = tempNum;
    } else if (*str == '\n') {
      ret = true;
      return ret;
    } else {
      ret = false;
      return ret;
    }
    ++str;
    ++place;
  }
  ret = true;
  return ret;
}

void printOption(NICKNAMEOPTION *nicknameOption) {
  printf("uppercase : %d\n", nicknameOption->allowUpperChar);
  printf("number : %d\n", nicknameOption->allowNumber);
  printf("symbol : %d\n", nicknameOption->allowSymbool);
  printf("nickname length : %d\n", nicknameOption->nicknameLength);
  printf("number of nicknames : %d\n", nicknameOption->numberOfNickname);
}

void askForOption(NICKNAMEOPTION *nicknameOption) {
  char upper[FLAG_VAR_ARRAY_LEN], number[FLAG_VAR_ARRAY_LEN],
      symbol[FLAG_VAR_ARRAY_LEN], nicknameLength[FLAG_VAR_ARRAY_LEN],
      numberOfNickname[FLAG_VAR_ARRAY_LEN], saveToFile[FLAG_VAR_ARRAY_LEN];

  printf("%s\n", welcomeWords);
  printf("%s\n", warnningWords);

  printf("Do you want uppercase letters?%s", constYesOrNo);
  fflush(stdout);
  getInput(upper, FLAG_VAR_ARRAY_LEN);

  printf("Do you want number?%s", constYesOrNo);
  fflush(stdout);
  getInput(number, FLAG_VAR_ARRAY_LEN);

  printf("Do you want symbol(!@#$^&*+_-./)?%s", constYesOrNo);
  fflush(stdout);
  getInput(symbol, FLAG_VAR_ARRAY_LEN);

  printf("How long do you want a nickname? [1~50] ");
  fflush(stdout);
  getInput(nicknameLength, FLAG_VAR_ARRAY_LEN);

  printf("How many nicknames do you want? [1~100000] ");
  fflush(stdout);
  getInput(numberOfNickname, FLAG_VAR_ARRAY_LEN);

  printf("Do you want to save nicknames to file?%s", constYesOrNo);
  fflush(stdout);
  getInput(saveToFile, FLAG_VAR_ARRAY_LEN);

  /* rewrite option value */
  nicknameOption->allowUpperChar = parseYesOrNo(upper);
  nicknameOption->allowNumber = parseYesOrNo(number);
  nicknameOption->allowSymbool = parseYesOrNo(symbol);
  nicknameOption->saveToFile = parseYesOrNo(saveToFile);

  double nicknameLength_ = nicknameOption->nicknameLength;
  if (parseNumber(nicknameLength, &nicknameLength_)) {
    nicknameOption->nicknameLength = nicknameLength_;
  }

  double numberOfNickname_ = nicknameOption->numberOfNickname;
  if (parseNumber(numberOfNickname, &numberOfNickname_)) {
    nicknameOption->numberOfNickname = numberOfNickname_;
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

int back_f(int argc) {}

void testLowercase() {
  char *str = "Yes\n";
  char *lowercaseStr = toLowercase(str);
  printf("%s\n", lowercaseStr);
  if (strcmp(lowercaseStr, "yes") == 0) {
    printf("1. true---yes  ");
  }

  if (strcmp(lowercaseStr, "yes\n") == 0) {
    printf("2. true  ");
  }

  if (strcmp("\n", "\n") == 0) {
    printf("3. true  ");
  }
}