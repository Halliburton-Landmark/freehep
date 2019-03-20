
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int aArgn,char** aArgs) {

  if(aArgn<=1) {
  
    // Similar to : UNIX> /usr/bin/glib-config

    printf("\
Usage: heprep-config [OPTIONS]\n\
Options:\n\
        [--version]\n\
        [--lib]\n\
        [--include]\n\
        [--implementation]\n\
");

    return EXIT_SUCCESS;

  } 

  if(!strcmp(aArgs[1],"--version")) {
    if(char* env = getenv("HEPREP_VERSION")) {
      printf("%s\n",env);
    } else {
      printf("HEPREP setup not executed.\n");
      return EXIT_FAILURE;
    }
  } else if(!strcmp(aArgs[1],"--include")) {
    if(char* env = getenv("HEPREP_INCLUDES")) {
      char* path = getenv("PATH");
      int cygwin = strstr(path,"cygwin") != NULL;
      if (cygwin)
      {
	 while(char *p = strchr(env,'\\'))
	 {
	    *p = '/';
	 }
      }
      printf("%s\n",env);
    } else {
      printf("HEPREP setup not executed.\n");
      return EXIT_FAILURE;
    }
  } else if(!strcmp(aArgs[1],"--lib")) {
    if(char* env = getenv("HEPREP_LIBS")) {
      printf("%s\n",env);
    } else {
      printf("HEPREP setup not executed.\n");
      return EXIT_FAILURE;
    }
  }
  else if(!strcmp(aArgs[1],"--implementation")) {
    printf("FreeHEP HEPREP\n");
  } else {
    printf("Unknown option.\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
