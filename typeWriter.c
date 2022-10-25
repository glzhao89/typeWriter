#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please enter file path\n");
    return -1;
  }

  FILE *fp = fopen(argv[1], "a");
  if (fp == NULL) {
    printf("Invalid file path: %s\n", argv[1]);
    return -1;
  }

  char buf[128] = {0};
  printf("Enter words(q to quit):\n");
  while(1) {
    memset(buf, 0, sizeof(buf));
    fgets(buf, sizeof(buf), stdin);
    printf("\033[1A");
    printf("\033[K");
    //printf("%s", buf);
    if (buf[0] == 'q' && buf[1] == '\n') {
      break;
    }
    fputs(buf, fp);
  }
  fclose(fp);
}

