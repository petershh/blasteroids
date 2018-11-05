CFLAGS =-Wall -Wextra -I ./include -g -std=c99
LIBS=`pkg-config --cflags --libs allegro-5 allegro_primitives-5`

bin/blasteroids: obj/blast.o obj/spaceship.o obj/asteroid.o obj/blasteroids.o
	gcc $^ -lm  $(CFLAGS) $(LIBS) -o bin/blasteroids

obj/%.o: src/%.c
	gcc -c $^ $(CFLAGS) -o $@
