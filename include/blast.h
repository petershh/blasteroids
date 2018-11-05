#ifndef BLASTEROIDS_BLAST
#define BLASTEROIDS_BLAST
#include<allegro5/allegro.h>

#define BLAST_SPEED 50.0f

typedef struct Blast{
  float x;
  float y;
  float rotation;
  ALLEGRO_COLOR color;
} Blast;

#endif
