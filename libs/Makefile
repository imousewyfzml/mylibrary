LDFLAG = -lpthread
SRC = main.cpp \
	  thread.cpp \
	  mutex.cpp \
	  condition.cpp 
MODULE = test_thread

all:
	g++ $(SRC) -o $(MODULE) $(LDFLAG)

clean:
	rm -f ${MODULE}
