/*
* David Kvilora <datokviloria@gmail.com>
*/
void kvilo_help() {
  printf("\n Usage: kvilo <command> <arg> <flag>\n\n");
  printf("\tkvilo init\t\t\t\tGenerate [master] collection\n");
  printf("\tkvilo set key=value\t\t\tStore variable in master collection\n");
  printf("\tkvilo get key\t\t\t\tGet variable value\n");
  printf("\tkvilo show\t\t\t\tLoad master collection and print\n");
  printf("\tkvilo validate key value\t\tValidate variable value\n");
  printf("\tkvilo export-env > myfile.txt\t\tExport all variable to custom file\n");
  printf("\tkvilo export\t\t\t\tExport all variable to .env file\n");
  printf("\tkvilo -ee\t\t\t\tExport all variable to .env-example file\n");
  printf("\n");
}
