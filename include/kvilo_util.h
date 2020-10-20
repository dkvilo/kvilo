/*
* David Kviloria <dkviloria@gmail.com>
*/
#ifndef KVILO_UTIL_H
#define KVILO_UTIL_H

#ifdef DEFINE_KVILO_UTIL_NO_STATIC
#define KVILO_UTIL_FUNC_TYPE extern inline
#else
#define KVILO_UTIL_FUNC_TYPE static inline
#endif

KVILO_UTIL_FUNC_TYPE
unsigned short len(char *string) {
	unsigned short i = 1;
	while(string[i++]);
	return i--;
}

KVILO_UTIL_FUNC_TYPE
char *substr(char *string, unsigned short from) {
  char newStr[150];
  for(unsigned short i; i < len(string) - from; i++)
      newStr[i] = string[from + i];
  char *ret = newStr;
  return ret;
}

KVILO_UTIL_FUNC_TYPE
void rmcfs(char* source, char target) {
  char *i = source;
  char *j = source;
  while(*j != 0) {
    *i = *j++;
    if(*i != target) {
      i++;
		}
  }
  *i = 0;
}

#endif
