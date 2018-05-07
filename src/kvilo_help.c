/*
* David Kvilora <datokviloria@gmail.com>
*/
void kvilo_help() {
  printf(" Usage: kvilo <command> <arg> <flag>\n");
  printf("\tkvilo set key=value\t\tStore variable in master collection\n");
  printf("\tkvilo init\t\t\tGenerate [master] collection\n");
  printf("\tkvilo get key\t\t\tGet variable value\n");
  printf("\tkvilo validate key value\tValidate variable value\n");
  printf("\tkvilo show\t\t\tLoad master collection and print\n");
}
