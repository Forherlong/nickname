CXX = gcc -g

Obj = nickname
Src = ./src/main.c ./src/nickname.h ./src/nickname.c

$(Obj) : $(Src)
	$(CXX) -o $@ $^

.PHONY: clean

clean:
	-rm -rf $(Obj)
