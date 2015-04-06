FLAGS=-lm -lcrypt -O2 -pipe
FILE=${F}/${F}

all: 
	#nano $(FILE).cpp
	g++ $(FILE).cpp $(FLAGS) -o $(FILE)
	./$(FILE) < $(FILE).in > $(FILE).out
