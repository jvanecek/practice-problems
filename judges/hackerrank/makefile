FLAGS=-lm -lcrypt -O2 -pipe #-Wall #-std=c++0x
FILE=${F}
EXEC=./$(FILE)/$(FILE)

all:
	g++ $(FLAGS) $(EXEC).cpp -o $(EXEC)
	$(EXEC) < $(EXEC).in > $(EXEC).out
	$(diff $(EXEC).expected $(EXEC).out)
