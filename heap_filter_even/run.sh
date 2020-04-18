#! /bin/bash
rm -f *.o
gcc -c *.c
if [ $? == 0 ]
then
  gcc -o ./bin/executable *.o
  rm -f *.o
  ./bin/executable
else
  echo "Compilation Error."
fi
  