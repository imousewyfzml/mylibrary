LDFLAG = -lpthread
CXXFLAG = -g
SRC = main.cpp \
	  thread.cpp \
	  mutex.cpp \
	  condition.cpp 
MODULE = test_thread

all:
	g++ $(SRC) -o $(MODULE) $(LDFLAG) $(CXXFLAG)

clean:
	rm -f ${MODULE}
