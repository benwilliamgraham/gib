.PHONY: default
default:
	gcc -O3 -lm -lGL -lglfw -Wextra -Wall -o out/gib src/*.c

.PHONY: clean
clean:
	clang-format -i src/*.c src/*.h