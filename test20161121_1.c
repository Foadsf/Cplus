#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *keywords[] = {"auto", "break", "case", "char",
                                 /* . */
                                 /* . */
                                 /* . */
                                 "while"};

int compare(const void *, const void *);

int main(int argc, const char *argv[]) {
  size_t num = 5;
  char *ptr;

  if (argc <= 1)
    return EXIT_FAILURE;

  ptr = lfind(&argv[1], keywords, &num, sizeof(char **), compare);
  if (ptr == NULL) {
    printf("'%s' is not a C keyword\n", argv[1]);

    return EXIT_FAILURE;
  } else {
    printf("'%s' is a C keyword\n", argv[1]);

    return EXIT_SUCCESS;
  }

  /* You'll never get here. */
  return EXIT_SUCCESS;
}

int compare(const void *op1, const void *op2) {
  const char **p1 = (const char **)op1;
  const char **p2 = (const char **)op2;

  return (strcmp(*p1, *p2));
}
