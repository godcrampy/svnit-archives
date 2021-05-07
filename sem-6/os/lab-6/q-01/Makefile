CC=g++
cpp_formatter=clang-format
cpp_formatter_options=-style=Google -i --verbose
file_pattern='.*\.\(cpp\|hpp\|cc\|cxx\)'

all: main.cpp node/node.o fit/fit.o first-fit/first-fit.o worst-fit/worst-fit.o best-fit/best-fit.o 
	$(CC) ./main.cpp node/node.o fit/fit.o first-fit/first-fit.o worst-fit/worst-fit.o best-fit/best-fit.o 


%.o : %.cpp %.hpp
	$(CC) -c $< -o $@

format:
	find . -regex $(file_pattern) -exec $(cpp_formatter) $(cpp_formatter_options) {} \;

.PHONY: clean
clean:
	rm ./*/*.o ./a.out
