#! /bin/sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o shell
valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./shell

