CFLAGS =-Wall -Wextra -I ./include -g

bin/blasteroids: obj/blast.o obj/spaceship.o obj/asteroid.o obj/blasteroids.o
	gcc $^ -lm  $(CFLAGS) `pkg-config --cflags --libs allegro-5 allegro_primitives-5` -o bin/blasteroids
	echo "./blasteroids" > ./bin/run.sh && chmod 777 ./bin/run.sh

obj/%.o: src/%.c
	gcc -c $^ $(CFLAGS) -o $@
