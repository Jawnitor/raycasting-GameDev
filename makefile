build:
	gcc -std=c99 ./src/*.c -lSDL2 -o ./bin/ray;

run:
	./bin/ray;

clean:
	rm ./bin/ray;
