.PHONY: default
default:
	gcc -O3 -lm -lGL -lGLU -lglut -o out/gib gib/*.c

.PHONY: clean
clean:
	clang-format -i gib/*.c gib/*.h