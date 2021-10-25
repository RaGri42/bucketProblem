CXX = g++ -Wall
HEADERS = $(wildcard *.h)
NAME = bucket

all: compile

compile: $(NAME)Main


checkstyle:
	python ../cpplint.py --repository=. *.h *.cpp

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test
	rm -f core

%Main: %Main.o $(NAME).o
	$(CXX) -o $@ $^ -lncurses


%.o: %.cpp $(HEADERS)
	$(CXX) -c $<
