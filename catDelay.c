#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char**argv){
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  int c;
  useconds_t stime=10000; // defaults to 100 Hz

  if (argc>1) { // Argument is interperted as Hz
    stime=1000000/atoi(argv[1]);
  }

  setvbuf(stdout,NULL,_IONBF,0);


   while ((read = getline(&line, &len, stdin)) != -1) {
            fputs(line,stdout);
            usleep(stime);
   }

  free(line);
  
  return 0;
}
