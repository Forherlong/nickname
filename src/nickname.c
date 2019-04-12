#include "nickname.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char dictSymbol[] = "!@#$^&*+_-./";
char dictLower[] = "abcdefghijklmnopqrstuvwxyz";
char dictUpper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char dictLowerSymbol[] = "abcdefghijklmnopqrstuvwxyz!@#$^&*+_-./";
char dictUpperSymbol[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$^&*+_-./";
char dictLowerUpper[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char dictAll[] =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$^&*+_-./";

const NICKNAMEOPTION NICKNAMEOPTION_DEFAULT = {.nicknameLength=8, .numberOfNickname=1, .allowUpperChar=false, .allowNumber=false, .allowSymbool=false};

char* getNickName(NICKNAMEOPTION* nicknameOption) {
  char* tempDict;
  if(nicknameOption->allowNumber) {

  }
  srand((unsigned int)time(NULL));
  for (int number = 0; number < nicknameOption->numberOfNickname; ++number) {
    for (int length = 0; length < nicknameOption->nicknameLength; ++length) {
      printf("%c", dictAll[rand() % 64]);
    }
  }

  return "";
}