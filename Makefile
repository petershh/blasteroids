CFLAGS =-Wall -Wextra -I ./include -g -std=c99
LIBS=`pkg-config --cflags --libs allegro-5 allegro_primitives-5`

bin/blasteroids: obj/blast.o obj/spaceship.o obj/asteroid.o obj/blasteroids.o
	gcc $^ -lm  $(CFLAGS) $(LIBS) -o bin/blasteroids
	printf "#!/bin/sh\n./blasteroids" > ./bin/run.sh && chmod 777 ./bin/run.sh #Temp script for opening the game from Nautilus since it thinks that game is a shared lib

obj/%.o: src/%.c
	gcc -c $^ $(CFLAGS) -o $@
