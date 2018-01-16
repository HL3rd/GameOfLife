# Makefile for the Life class
# Horacio Lopez, Section 02

CMP = g++
MAIN = life
CLASS = lifeboard
EXEC = playlife

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(MAIN).o $(CLASS).o -o $(EXEC)

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c -std=c++11 $(MAIN).cpp -o $(MAIN).o

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

clean:
	rm *.o $(EXEC)
