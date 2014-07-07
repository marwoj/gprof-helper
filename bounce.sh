gcc -g -c bounce.c -pg
gcc -o bounce bounce.o -pg -lpthread

gcc -shared -fPIC gprof-helper.c -o gprof-helper.so -lpthread -ldl

LD_PRELOAD=./gprof-helper.so ./bounce


gprof -p -Q bounce gmon.out > resultFlat.txt
gprof -P -q bounce gmon.out > resultGraph.txt

gedit resultFlat.txt &
gedit resultGraph.txt &

rm -f *.o
rm -f *.so
rm -f *~
