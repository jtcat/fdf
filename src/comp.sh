#!/bin/bash
cc -g -O0 -Wall -Werror -Wextra main.c window.c -lXext -lX11 minilibx-linux/libmlx.a libft/libft.a -o test
