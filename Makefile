CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Werror -pedantic

search : main.cpp mapping.o score.o 
	clang++ main.cpp mapping.o score.o -std=c++1y -stdlib=libc++ -lpng -o search

#main.o : main.cpp mapping.h score.h sort.cpp
#	clang++ $(CXXFLAGS) main.cpp

mapping.o : mapping.h mapping.cpp
	clang++ $(CXXFLAGS) mapping.cpp

score.o : score.h score.cpp 
	clang++ $(CXXFLAGS) score.cpp

##sort.o : sort.h sort.cpp
#	clang++ $(CXXFLAGS) sort.cpp
clean:	
	rm -f *.o search

