#! /bin/sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o shell
valgrind --leak-check=full --show-leak-kinds=all ./shell
