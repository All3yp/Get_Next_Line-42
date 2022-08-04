all:	clean	build bonus	debug

run: clean build bonus
	./gnl.out

build: main.c get_next_line.c get_next_line_utils.c
	clang main.c get_next_line.c get_next_line_utils.c -o gnl.out -D BUFFER_SIZE=10 -fsanitize=address -g3

bonus: 
	clang main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl.out -D BUFFER_SIZE=10 -fsanitize=address -g3

debug: gnl.dSYM
	lldb gnl

clean:
	rm -rf gnl gnl.dSYM


