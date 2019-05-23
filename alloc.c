#ifndef L_ALLOC_C
#define L_ALLOC_C

#include <stdlib.h>
#include <stdio.h>

void *
allocArgv (int argc)
{
  return malloc (sizeof (char *) * argc);
}

void
printArgs (int argc, char **argv)
{
  int i;
  for (i = 0; i < argc; i++)
    {
      printf ("%s\n", argv[i]);
    }
}

#endif
