#ifndef __NICKNAME_H__
#include <stdbool.h>
#include "error_code.h"

typedef struct _NICKNAMEOPTION {
  int nicknameLength;
  int numberOfNickname;
  bool allowUpperChar;
  bool allowNumber;
  bool allowSymbool;
  bool allowLowerChar;
  bool saveToFile;
} NICKNAMEOPTION;
extern const NICKNAMEOPTION NICKNAMEOPTION_DEFAULT;
int nickname(NICKNAMEOPTION *nno);
#endif