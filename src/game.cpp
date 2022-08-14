#include "game.h"
#include "snake.h"
#include <iostream>
#include <thread>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      engine2(dev2()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_w2(0, static_cast<int>(grid_width - 1)),
      random_h2(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &&renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    
    renderer.Render(snake, food, food_2);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;

  /* Second food Coordinates*/
  int x2, y2;

  /* Counter to update both food locations */
  int counter=0;

  while (true) {
    x = random_w(engine);
    y = random_h(engine);

    /* Creating new random generator for the second food object */
    x2 = random_w2(engine2);
    y2 = random_h2(engine2);

    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      counter++;
    }
    /* Check that the location is not occupied by a snake item before placing Second Food */
    if (!snake.SnakeCell(x2, y2)) {
      food_2.x = x2;
      food_2.y = y2;
      counter++;
    }
    /* If finished setting the two food objects coordinates, break */
    if(counter==2)
      return;
  }
}

void Game::Update() {
  if (!snake.getAlive()) return;

  snake.Update();

  int new_x = static_cast<int>(snake.getHead_x());
  int new_y = static_cast<int>(snake.getHead_y());

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.setSpeed(snake.getSpeed() + 0.02);
  }
  /* Check if there's second food over here */
  else if (food_2.x == new_x && food_2.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.setSpeed(snake.getSpeed() + 0.02);
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.getSize(); }
