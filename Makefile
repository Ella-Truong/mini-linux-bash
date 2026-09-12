all:
	g++ -std=c++17 -Iinclude src/main.cpp src/parser.cpp src/builtin.cpp src/executor.cpp -o minishell
run:
	./minishell
clean:
	rm -f minishell
	