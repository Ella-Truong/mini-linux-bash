all:
	g++ -Iinclude src/main.cpp src/parser.cpp src/builtin.cpp -o minishell
run:
	./minishell
clean:
	rm -f minishell
	