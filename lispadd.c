#include <ecl/ecl.h>
#include <stdlib.h>
#include <stdio.h>
extern void init_add(cl_object cblock);

// Make sure this doesn't get called before 'cl_boot'
int lisp_add(int x, int y)
{
  cl_object sum = cl_funcall(3, c_string_to_object("add"), ecl_make_int(x), ecl_make_int(y));
  return ecl_to_int(sum);
}

int main(int argc, char *argv[])
{
  if (argc<2) {
    printf("I need 2 arguments to add\n");
    return 1;
  }
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  cl_boot(argc, argv);
  read_VV(OBJNULL, init_add);
  int sum = lisp_add(x, y);
  printf("%d\n", sum);
  cl_shutdown();
  return 0;
}
