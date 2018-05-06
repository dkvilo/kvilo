/*
* David Kvilora <datokviloria@gmail.com>
*/

#include <string.h>

void kvilo_validate(int argc, char *from_collection, const char *from_cli) {

  if (argc <= 2) {
    create_error(0, "Missing argument: kvilo --validate <key> <value>");
    return 1;
  }

  if (strcmp(from_collection, "NONE") == 0) {
    create_error(1, "Error: Variable not found\n");
    return 1;
  }

  rmcfs(from_collection, '\n');

  if (strcmp(from_collection, from_cli) == 0 ) {
    printf("[+] Status: [FOUND]\n");
  } else {
    printf("[+] Status: [NOT FOUND]\n");
    return 1;
  }

}
