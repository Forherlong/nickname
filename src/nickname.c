#include "nickname.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH_OF_NICKNAME 50
#define MAX_NICKNAME_NUMBER 1000

const char *dictSymbol = "!@#$^&*+_-./";
const char *dictLower = "abcdefghijklmnopqrstuvwxyz";
const char *dictUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *dictNumber = "1234567890";

const NICKNAMEOPTION NICKNAMEOPTION_DEFAULT = { .nicknameLength = 8,
						.numberOfNickname = 1,
						.allowUpperChar = false,
						.allowNumber = false,
						.allowSymbool = false,
						.allowLowerChar = false,
						.saveToFile = false };

bool saveNicknameToFile(char **nicknames, int length);

/* 根据 4 个布尔值计算对应字符串拼接在一起后长度 */
int wanted_dic_len(bool wantNum, bool wantUpp, bool wantSym, bool wantLow)
{
	int destlen = 0;
	if (wantNum == true) {
		destlen += strlen(dictNumber);
	}

	if (wantUpp == true) {
		destlen += strlen(dictUpper);
	}

	if (wantSym == true) {
		destlen += strlen(dictSymbol);
	}

	if (wantLow == true) {
		destlen += strlen(dictLower);
	}
	return destlen;
}

/* 根据 4 个布尔值判断对应的字符串是否加入到返回结果里 
	 第一个参数调用时传入 NULL 
	 调用完函数后 wantedDict 被赋予拼接好的字符串，使用完 wantedDict 后需要手动 free(wantedDict) */
int conc_wanted_dic(char **wantedDict, bool wantNum, bool wantUpp, bool wantSym,
		    bool wantLow)
{
	*wantedDict = NULL;
	/* + 1 存储 '\0' */
	int destlen = wanted_dic_len(wantNum, wantUpp, wantSym, wantLow) + 1;
	*wantedDict = malloc(sizeof(char) * destlen);
	/* 即使 bool 值都是 false wantedDict 也没有垃圾数据 */
	memset(*wantedDict, '\0', destlen);
	if (wantNum == true) {
		strcat(*wantedDict, dictNumber);
	}

	if (wantUpp == true) {
		strcat(*wantedDict, dictUpper);
	}

	if (wantSym == true) {
		strcat(*wantedDict, dictSymbol);
	}

	if (wantLow == true) {
		strcat(*wantedDict, dictLower);
	}
	return SUCCESS;
}

/* 生成一个 nickname 
	 onenn 需要传入 NULL，调用函数后 onenn 被赋值，使用后需要手动 free(onenn) */
void pickOneNickname(char **onenn, int nnlen, char *wantedDict)
{
	int i;
	*onenn = NULL;
	int wantedDictLen = strlen(wantedDict);

	/* + 1 存储 '\0' */
	*onenn = malloc(sizeof(char) * (nnlen + 1));

	for (i = 0; i < nnlen; ++i) {
		*(*onenn + i) = wantedDict[rand() % wantedDictLen];
	}
	*(*onenn + nnlen) = '\0';
}

void printnns(char **nns, int nnslen)
{
	int i;
	for (i = 0; i < nnslen; ++i) {
		printf("%s\n", *(nns + i));
	}
}

/* generate nickname. 选择组成昵称的成员，不选择默认使用数字 + 
	 大写英文字母 */
int nickname(NICKNAMEOPTION *nno)
{
	int i;
	bool wantNum = nno->allowNumber;
	bool wantUpp = nno->allowUpperChar;
	bool wantSym = nno->allowSymbool;
	bool wantLow = nno->allowLowerChar;
	/* 全局调用一次，否则随机数种子都是当前时间，可能导致随机数相同 */
	srand((unsigned int)time(NULL));

	/* nn 元素集合 */
	char *wantedDict = NULL;
	conc_wanted_dic(&wantedDict, wantNum, wantUpp, wantSym, wantLow);

	/* +1 存储 '\0' */
	char **nns = malloc(sizeof(char *) * (nno->numberOfNickname + 1));
	for (i = 0; i < nno->numberOfNickname; ++i) {
		pickOneNickname(&*(nns + i), nno->nicknameLength, wantedDict);
	}
	*(nns + nno->numberOfNickname) = '\0';
	printnns(nns, nno->numberOfNickname);

	free(wantedDict);
}

bool saveNicknameToFile(char **nicknames, int length)
{
	/* todo: free memory */
	char fileName[28];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(fileName, "%d-%d-%d_%dh-%dmin-%dsec.txt", tm.tm_year + 1900,
		tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	FILE *f = fopen(fileName, "w");
	if (f == NULL) {
		perror("open file error. skip write content to file.\n");
		return false;
	}

	for (int i = 0; i < length; ++i) {
		fprintf(f, "No.%d %s\n", i + 1, *nicknames++);
	}
	fclose(f);
	return true;
}