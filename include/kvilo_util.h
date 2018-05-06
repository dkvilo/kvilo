/*
* David Kviloria <dkviloria@gmail.com>
*/
#pragma once

#ifndef KVILO_UTIL_H
#define KVILO_UTIL_H

#define VERSION "0.0.1"

unsigned short len(char *string) {
	unsigned short i = 1;
	while(string[i++]);
	return i--;
}

char *substr(char *string, unsigned short from) {
  char newStr[150];
  for(unsigned short i; i < len(string) - from; i++)
      newStr[i] = string[from + i];
  char *ret = newStr;
  return ret;
}

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
