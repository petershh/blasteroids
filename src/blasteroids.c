#include "blasteroids.h"
#include <stdio.h>

int main(/*int argc, char const *argv[]*/) {
  al_init();
  al_init_primitives_addon();
  al_install_keyboard();
  ALLEGRO_DISPLAY* display = al_create_display(800, 640);
  al_clear_to_color(al_map_rgba(0,0,0,255));
  al_flip_display();

  int display_width = al_get_display_width(display);
  int display_height = al_get_display_height(display);

  Spaceship s;
  s.x = display_width/2;
  s.y = display_height/2;
  s.rotation = M_PI;

  s.rotating = 0;
  s.speed = 0;
  s.accelerating = 0;
  s.lifes = 3;
  s.color = al_map_rgb(255,255,255);

  ALLEGRO_EVENT_QUEUE *q = al_create_event_queue();
  al_register_event_source(q, al_get_keyboard_event_source());
  ALLEGRO_TIMER *timer = al_create_timer(1.0f/FPS);
  al_register_event_source(q, al_get_timer_event_source(timer));
  ALLEGRO_EVENT event;
  al_start_timer(timer);
  while (true) {
    al_wait_for_event(q, &event);
    if(event.type == ALLEGRO_EVENT_KEY_DOWN){
      switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_LEFT:
          s.rotating = 1;
          break;
        case ALLEGRO_KEY_RIGHT:
          s.rotating = -1;
          break;
        case ALLEGRO_KEY_UP:
          s.accelerating = 1;
          break;
        case ALLEGRO_KEY_DOWN:
          s.accelerating = -1;
          break;
        case ALLEGRO_KEY_SPACE:
          //TODO
          break;
        }
    }else if(event.type == ALLEGRO_EVENT_KEY_UP){
      switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_LEFT: //fall through
        case ALLEGRO_KEY_RIGHT:
          s.rotating = 0;
          break;
        case ALLEGRO_KEY_UP:  //fall through
        case ALLEGRO_KEY_DOWN:
          s.accelerating = 0;
          break;
        case ALLEGRO_KEY_SPACE:
          //TODO
          break;
        }
    }else if (event.type == ALLEGRO_EVENT_TIMER){
      //Redraw scene, ...
      al_clear_to_color(al_map_rgb(0,0,0));
      draw_spaceship(&s);
      al_flip_display();

      //... then compute physics
      //s.rotation += SPACESHIP_ANGULAR_VELOCITY*s.rotating/FPS;
      s.rotation = repeat(s.rotation + SPACESHIP_ANGULAR_VELOCITY*s.rotating/FPS, 2*M_PI);
      s.speed = clamp(s.speed + SPACESHIP_ACCELERATION*s.accelerating*(1.0f/FPS), SPACESHIP_MIN_SPEED, SPACESHIP_MAX_SPEED);

      s.x = clamp(s.x + s.speed*sin(s.rotation)*(1.0f/FPS), 0, (float)display_width);
      s.y = clamp(s.y + s.speed*cos(s.rotation)*(1.0f/FPS), 0, (float)display_height);
    }
  }
  return 0;
}

float clamp(float val, float min_val, float max_val){
  if(val > max_val) val = max_val;
  else if(val < min_val) val = min_val;
  return val;
}

float repeat(float val, float module){
  if(val < 0) val += module;
  else if(val > module) val -= module;
  return val;
}
