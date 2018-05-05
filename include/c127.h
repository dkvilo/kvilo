/*
* David Kviloria <dkviloria@gmail.com>
*/
#pragma once

#ifndef C127_H
#define C127_H

#define VERSION "0.0.1"

signed char i8;
typedef unsigned char ui8;

typedef signed short i16;
typedef unsigned short ui16;

typedef signed int i32;
typedef unsigned int ui32;

typedef signed long long i64;
typedef unsigned long long ui64;

typedef char* str;
typedef const char* cstr;

/*
 * @returnType: Int
 * @returnValue: str/char* length within \n
*/
int len(str string) {
	ui32 i = 1;
	while(string[i++]);
	return i--;
}

/*
 * @returnType: Int
 * @returnValue: str/char* length without \n
*/
int fixed_len(str string) {
	ui32 i = 1;
	while(string[i++]);
	return (i) - 1;
}

/*
 * @retunrType: ui8 (typedef unsigned char)
 * @returnValue: if equals 1, if not 0
*/
ui8 eq(char* s1, char* s2) {

	ui8 result = 1;
	ui8 size = fixed_len(s1);

	if ( size != fixed_len(s2) ) result = 0;

	else {
		for(ui8 i = 0; i <= size; i++)
			if(s1[i] != s2[i]) result = 0;
	}

	return result;
}


/*
 * @retunrType: int
 * @returnValue: casted int
*/
int sti(str string){
	int x = 0; int y = 1;
	for (int i = fixed_len(string) - 1; i >= 0; i--){
		x += ((int) (string[i] - '0')) * y;
		y *= 10;
	}
	return x;
}

#endif
