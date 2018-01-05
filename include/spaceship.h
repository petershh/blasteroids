#ifndef BLASTEROIDS_SPACESHIP
#define BLASTEROIDS_SPACESHIP

#include<math.h>
#include<allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>


#define SPACESHIP_ACCELERATION 10.0f
#define SPACESHIP_ANGULAR_VELOCITY M_PI
#define SPACESHIP_MAX_SPEED 40.0f
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
