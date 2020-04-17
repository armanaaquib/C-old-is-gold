#include "dynamic_string.h"

#ifndef __SPLIT_H_
#define __SPLIT_H_

typedef unsigned short u_short;

#define ITERATE(start, end) for(u_short i = start; i < end; i++)

Strings split(String, u_short, char);

#endif
