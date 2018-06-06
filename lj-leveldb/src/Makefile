# build liblualeveldb.so executable when user executes "make"
CC = g++
liblualeveldb.so: lua_leveldb.o
	$(CC) -shared lua_leveldb.o -o liblualeveldb.so -lpthread -lleveldb

lua_leveldb.o: lua_leveldb.cc
	$(CC) -fPIC -c lua_leveldb.cc

# remove object files and executable when user executes "make clean"
clean:
	rm *.o liblualeveldb.so
