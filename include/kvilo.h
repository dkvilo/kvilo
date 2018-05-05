/*
* David Kviloria <datokviloria@gmail.com>
*/
#pragma once

#ifndef KVILO_H
#define KVILO_H

void create_error(unsigned short type, const char *message);
void create_message(const char *message);
char *getConfig(char *target_key);
void remove_from_string(char* source, char target);

#endif
