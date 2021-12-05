#include "stdio.h"
#include "util.h"

void foo(abstract_type x) { printf("%d ", x); }

void bar() { foo(45); }
