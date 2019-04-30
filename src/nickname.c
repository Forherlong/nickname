#include "nickname.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH_OF_NICKNAME 50
#define MAX_NICKNAME_NUMBER 1000

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

bool saveNicknameToFile(char **nicknames, int length);

/* len [out]
   str1 [in]
   str2 [in]
   concatenate str1 and str2 then return, len is return string's length
 */
char *concatenateString(int *len, const char *str1, const char *str2)
{
  int len1 = 0, len2 = 0, len3 = 0;
  while (str1[len1] != '\0')
  {
    len1++;
  }

  while (str2[len2] != '\0')
  {
    len2++;
  }

  len3 = len1 + len2;
  *len = len3;
  char *ret = (char *)malloc(sizeof(char) * len3);
  for (int i = 0; i < len1; ++i)
  {
    ret[i] = str1[i];
  }
  for (int i = 0; i < len2; ++i)
  {
    ret[len1 + i] = str2[i];
  }

  return ret;
}

char *getNickName(NICKNAMEOPTION *nicknameOption)
{
  char *tempDict;
  int len = 0;

  /* 选择字典 */
  bool upper = nicknameOption->allowUpperChar;
  bool symbol = nicknameOption->allowSymbool;
  bool number = nicknameOption->allowNumber;
  if (upper && symbol && number)
  {
    tempDict = concatenateString(
        &len,
        concatenateString(&len, concatenateString(&len, dictLower, dictUpper),
                          dictSymbol),
        dictNumber);
  }
  else if (upper && symbol && !number)
  {
    tempDict = concatenateString(
        &len, concatenateString(&len, dictLower, dictUpper), dictSymbol);
  }
  else if (upper && !symbol && number)
  {
    tempDict = concatenateString(
        &len, concatenateString(&len, dictLower, dictUpper), dictNumber);
  }
  else if (!upper && symbol && number)
  {
    tempDict = concatenateString(
        &len, concatenateString(&len, dictLower, dictSymbol), dictNumber);
  }
  else if (!upper && !symbol && number)
  {
    tempDict = concatenateString(&len, dictLower, dictNumber);
  }
  else if (!upper && symbol && !number)
  {
    tempDict = concatenateString(&len, dictLower, dictSymbol);
  }
  else if (upper && !symbol && !number)
  {
    tempDict = concatenateString(&len, dictLower, dictUpper);
  }
  else if (!upper && !symbol && !number)
  {
    tempDict = dictLower;
    len = sizeof(tempDict) / sizeof(tempDict[0]);
  }
  else
  {
    tempDict = dictLower;
    len = sizeof(tempDict) / sizeof(tempDict[0]);
  }

  if (nicknameOption->numberOfNickname > MAX_NICKNAME_NUMBER)
  {
    printf(
        "number of nickname > max_nickname_number, rewrite number with "
        "max_nickname_number.\n");
    fflush(stdout);
    nicknameOption->numberOfNickname = MAX_NICKNAME_NUMBER;
  }

  if (nicknameOption->nicknameLength > MAX_LENGTH_OF_NICKNAME)
  {
    printf(
        "nikename length > max_length_of_nickname, rewrite nikename length "
        "with max_length_of_nickname.\n");
    fflush(stdout);
    nicknameOption->nicknameLength = MAX_LENGTH_OF_NICKNAME;
  }

  char **nicknames = malloc(sizeof(char *) * nicknameOption->numberOfNickname);
  srand((unsigned int)time(NULL));
  for (int number = 0; number < nicknameOption->numberOfNickname; ++number)
  {
    char *oneNickname =
        (char *)malloc(sizeof(char) * (nicknameOption->nicknameLength + 1));
    for (int length = 0; length < nicknameOption->nicknameLength; ++length)
    {
      *(oneNickname + length) = tempDict[rand() % len];
    }
    *(oneNickname + nicknameOption->nicknameLength) = '\0';
    printf("%s\n", oneNickname);
    *(nicknames + number) = oneNickname;
  }

  if (tempDict != dictSymbol && tempDict != dictLower &&
      tempDict != dictNumber && tempDict != dictUpper)
  {
    free(tempDict);
  }
  
  if(nicknameOption->saveToFile) {
    bool saveOk = saveNicknameToFile(nicknames, nicknameOption->numberOfNickname);
    if(!saveOk) {
      printf("save nicknames to file failed.");
    }
  }
  
  return "";
}

bool saveNicknameToFile(char **nicknames, int length)
{
  /* todo: free memory */
  char fileName[28];
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(fileName, "%d-%d-%d_%dh-%dmin-%dsec.txt", tm.tm_year + 1900, tm.tm_mon + 1,
          tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  FILE *f = fopen(fileName, "w");
  if (f == NULL)
  {
    strerror(errno);
    perror("open file error. skip write content to file.\n");
    return false;
  }

  for (int i = 0; i < length; ++i)
  {
    fprintf(f, "No.%d %s\n", i + 1, *nicknames++);
  }
  fclose(f);
  return true;
}