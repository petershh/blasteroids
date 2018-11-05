#ifndef BLASTEROIDS_SPACESHIP
#define BLASTEROIDS_SPACESHIP

#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

#define M_PI 3.1415926535897932384626433832795L

#define SPACESHIP_ACCELERATION 20.0f
#define SPACESHIP_ANGULAR_VELOCITY 2*M_PI
#define SPACESHIP_MAX_SPEED 100.0f
#define SPACESHIP_MIN_SPEED 0.0f

typedef struct Spaceship {
  float x;
  float y;
  float rotation;

  float speed;
  int rotating;
  int accelerating;

  int lifes;
  ALLEGRO_COLOR color;
} Spaceship;

void draw_spaceship(Spaceship* s);
#endif
