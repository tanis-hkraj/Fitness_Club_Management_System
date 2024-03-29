#include <stdio.h>
#include <string.h>

int main() {
  char str[] = "Hello, world!";
  char *slice = str + 7;  // slice starting from index 7

  printf("Original string: %s\n", str);
  printf("Sliced string: %s\n", slice);

  return 0;
}