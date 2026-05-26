all:
	g++ src/main.cpp -o minishell
run:
	./minishell
clean:
	rm -f minishell
	