#include "nickname.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char dictSymbol[] = "!@#$^&*+_-./";
const char dictLower[] = "abcdefghijklmnopqrstuvwxyz";
const char dictUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char dictNumber[] = "1234567890";

const NICKNAMEOPTION NICKNAMEOPTION_DEFAULT = {.nicknameLength = 8,
                                               .numberOfNickname = 1,
                                               .allowUpperChar = false,
                                               .allowNumber = false,
                                               .allowSymbool = false,
                                               .saveToFile = false};
/* len [out]
   str1 [in]
   str2 [in]
 */
char* concatenateString(int* len, const char* str1, const char* str2) {
  int len1 = 0, len2 = 0, len3 = 0;
  while (str1[len1] != '\0') {
    len1++;
  }

  while (str2[len2] != '\0') {
    len2++;
  }

  len3 = len1 + len2;
  *len = len3;
  char* ret = (char*)malloc(sizeof(char) * len3);
  for (int i = 0; i < len1; ++i) {
    ret[i] = str1[i];
  }
  for (int i = 0; i < len2; ++i) {
    ret[len1 + i] = str2[i];
  }

  return ret;
}

char* getNickName(NICKNAMEOPTION* nicknameOption) {
  char* tempDict;
  int len = 0;
  
  /* 选择字典 */
  bool upper = nicknameOption->allowUpperChar;
  bool symbol = nicknameOption->allowSymbool;
  bool number = nicknameOption->allowNumber;
  if (upper && symbol && number) {
    tempDict = concatenateString(
        &len,
        concatenateString(&len, concatenateString(&len, dictLower, dictUpper),
                          dictSymbol),
        dictNumber);
  } else if (upper && symbol && !number) {
    tempDict = concatenateString(
        &len, concatenateString(&len, dictLower, dictUpper), dictSymbol);
  } else if (upper && !symbol && number) {
    tempDict = concatenateString(
        &len, concatenateString(&len, dictLower, dictUpper), dictNumber);
  } else if (!upper && symbol && number) {
    tempDict = concatenateString(
        &len, concatenateString(&len, dictLower, dictSymbol), dictNumber);
  } else if (!upper && !symbol && number) {
    tempDict = concatenateString(&len, dictLower, dictNumber);
  } else if (!upper && symbol && !number) {
    tempDict = concatenateString(&len, dictLower, dictSymbol);
  } else if (upper && !symbol && !number) {
    tempDict = concatenateString(&len, dictLower, dictUpper);
  } else if (!upper && !symbol && !number) {
    tempDict = dictLower;
    len = sizeof(tempDict) / sizeof(tempDict[0]);
  } else {
    tempDict = dictLower;
    len = sizeof(tempDict) / sizeof(tempDict[0]);
  }

  srand((unsigned int)time(NULL));
  for (int number = 0; number < nicknameOption->numberOfNickname; ++number) {
    for (int length = 0; length < nicknameOption->nicknameLength; ++length) {
      printf("%c", tempDict[rand() % len]);
    }
  }

  free(tempDict);
  return "";
}