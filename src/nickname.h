#ifndef __NICKNAME_H__
#include <stdbool.h>

typedef struct _NICKNAMEOPTION {
  int nicknameLength;
  int numberOfNickname;
  bool allowUpperChar;
  bool allowNumber;
  bool allowSymbool;
  bool saveToFile;
} NICKNAMEOPTION;
extern const NICKNAMEOPTION NICKNAMEOPTION_DEFAULT;
char* getNickName(NICKNAMEOPTION*);
#endif