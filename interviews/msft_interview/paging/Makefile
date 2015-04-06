CPP = g++
CPPFLAGS = -std=c++11 -ggdb
BIN = $(CPP) $(CPPFLAGS) $^ -o $@
ALL = $(patsubst %.cpp, %, $(wildcard *.cpp))
.PHONY: clean
all: $(ALL)
%: %.cpp
	$(BIN)
clean:
	rm -f $(ALL)