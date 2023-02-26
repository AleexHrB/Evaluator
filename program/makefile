.DEFAULT_GOAL := program.exe
OPTIONS = -DJUDGE -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11


program.exe : course.o problem.o season.o user.o cjt_course.o cjt_season.o cjt_problem.o cjt_user.o program.o
	g++ -o program.exe program.o course.o problem.o season.o user.o cjt_course.o cjt_season.o cjt_problem.o cjt_user.o $(OPTIONS)

%.o : %.cc
	g++ -c $< $(OPTIONS)

.PHONY : all
all : program.exe

.PHONY : clean

practica.tar: 
	tar -cvf practica.tar *.hh *.cc makefile Doxyfile
clean :
	rm *.o 
	rm *.exe

