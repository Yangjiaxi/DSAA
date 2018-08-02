//
// Created by VanYang on 2018/8/2.
//

#include <stdlib.h>
#include "fatal.h"

void Fatal(const char *s)
{
  fprintf(stderr, s);
  fflush(stderr);
  exit(1);
}
