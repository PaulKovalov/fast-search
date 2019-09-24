LIBS=-lstdc++fs
STD=-std=c++14
EXEC=main
FLAGS= -Wall -pedantic

$(EXEC): main.o trie.o document.o string_utility.o app.o config.o reader.o validator.o app.o doc_reader.o
	g++ main.o trie.o document.o string_utility.o app.o config.o reader.o validator.o doc_reader.o -o $(EXEC) $(LIBS) 

main.o: main.cpp
	g++ main.cpp -c $(STD) $(FLAGS)

trie.o: trie.cpp trie.hpp
	g++ trie.cpp -c $(STD) $(FLAGS)

document.o: document.cpp document.hpp
	g++ document.cpp -c $(STD) $(FLAGS)

config.o: config.cpp config.hpp
	g++ config.cpp -c $(STD) $(FLAGS)

doc_reader.o: doc_reader.cpp doc_reader.hpp
	g++ doc_reader.cpp -c $(STD) $(FLAGS)

string_utility.o: string_utility.cpp string_utility.hpp
	g++ string_utility.cpp -c $(STD) $(FLAGS)
	
reader.o: reader.cpp reader.hpp
	g++ reader.cpp -c $(STD) $(FLAGS)
	
validator.o: validator.cpp validator.hpp
	g++ validator.cpp -c $(STD) $(FLAGS)

app.o: app.cpp app.hpp
	g++ app.cpp -c $(STD) $(FLAGS)

clean:
	rm *.o;

.PHONY: run
run:
	./$(EXEC)
