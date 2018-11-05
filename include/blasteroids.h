#ifndef BLASTEROIDS
#define BLASTEROIDS

#include<math.h>

#include "asteroid.h"
#include "blast.h"
#include "spaceship.h"

#define FPS 60

/*typedef enum Objects{
  SPACESHIP,
  ASTEROID,
  BLAST
} Objects;

typedef union Object{
  Spaceship s;
  Asteroid a;
  Blast b;
} Object;

typedef struct GameObject{
  Object object;
  Objects type;
} GameObject;

void detect_overlap();
*/


float clamp(float val, float min_val, float max_val);
float repeat(float val, float module);
#endif
