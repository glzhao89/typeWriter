#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_LEN 128
#define FORWARD_STEP 1
#define BACKWARD_STEP -2

void getLastLine(FILE *fp, char *buf) {
  char c;
  int len = 0;
  // last two characters in FILE \n, EOF
  fseek(fp, BACKWARD_STEP, SEEK_END);
  c = fgetc(fp);
  while(c != '\n') {
    len++;
    // fgetc increase one character
    // of cursor each time
    fseek(fp, BACKWARD_STEP, SEEK_CUR);
    c = fgetc(fp);
  }

  fgets(buf, len + 2, fp); // including '\0' and '\n' characters
  fseek(fp, 0, SEEK_END);
}

int main(int argc, char *argv[]) {
  char cache[BUF_LEN] = {0};
  char input[BUF_LEN] = {0};

  if (argc != 2) {
    printf("Please enter file path\n");
    return -1;
  }

  FILE *fp = fopen(argv[1], "a+");
  if (fp == NULL) {
    printf("Invalid file path: %s\n", argv[1]);
    return -1;
  }
  // fill cache with last line
  getLastLine(fp, cache);
  //printf("%s", cache);

  printf("Enter words(q to quit):\n");
  while(1) {
    memset(input, 0, sizeof(input));
    fgets(input, sizeof(input), stdin);
    //printf("%s", input);
    printf("\033[1A");
    printf("\033[K");

    if (input[0] == 'q' && input[1] == '\n') {
      break;
    } else if (input[0] == 's' && input[1] == '\n') {
      printf("%s", cache);
      sleep(1);
      printf("\033[1A");
      printf("\033[K");
      continue;
    }

    fputs(input, fp);
    memcpy(cache, input, BUF_LEN);
  }
  fclose(fp);
}

