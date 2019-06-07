CXX = gcc -g
LIBS = 
CFLAGS =

Obj = nickname
Src = ./src/error_code.h ./src/main.c ./src/nickname.h ./src/nickname.c

$(Obj) : $(Src)
	$(CXX) -o $@ $^

.PHONY: clean

clean:
	-rm -rf $(Obj)
