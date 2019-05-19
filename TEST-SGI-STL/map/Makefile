all : map test1 test2

map : map.cpp
	g++ $^ -o $@ -std=c++11

test1 : test1.cpp
	g++ $^ -o $@ -std=c++11

test2 : test2.cpp
	g++ $^ -o $@ -std=c++11

.PHONY :

clean :
	rm -rf map test1 test2
