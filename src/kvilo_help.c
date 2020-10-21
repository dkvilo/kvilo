/*
* David Kvilora <datokviloria@gmail.com>
*/
void kvilo_help() {
  printf("\n Usage: kvilo <action|macro> <?coll> <arg1> <arg2> <flag>\n\n");
  printf("\tinit        [-i]                    create collection\n");
  printf("\tinit        [-i]  [-f]              Force Init\n");
  printf("\tset         [-s]  <key>=<value>     Store variable\n");
  printf("\tunset       [-u]  <key>             Remove variable\n");
  printf("\tget         [-g]  <key>             Get variable\n");
  printf("\tshow                                See collection\n");
  printf("\tls                                See collection\n");
  printf("\tval         [-v]  <key> <value>     Validate variable\n");
  printf("\texp-env     [-e-env] > filename     Write collection to file\n");
  printf("\texp         [-e]                    Export .env file\n");
  printf("\texp-example [-ee]                   Export .env-example file\n");
  printf("\thelp        [-h]                    Help message\n");
  printf("\n\t/usr/bin/kvilo                    David Kviloria <dkvilo>\n\n");
} 
