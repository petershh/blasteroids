#ifndef BLASTEROIDS
#define BLASTEROIDS

#include<math.h>

#include "asteroid.h"
#include "blast.h"
#include "spaceship.h"

#define FPS 60

float clamp(float val, float min_val, float max_val);
float repeat(float val, float module);
#endif
