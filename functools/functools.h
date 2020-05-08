#ifndef __FUNCTOOLS_H
#define __FUNCTOOLS_H

typedef int *Int_Array;
typedef int (*Int_Mapper)(int);

Int_Array int_map(Int_Mapper, Int_Array, unsigned);

#endif
