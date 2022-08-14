#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake
{
public:
  enum class Direction
  {
    kUp,
    kDown,
    kLeft,
    kRight
  };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        _head_x(grid_width / 2),
        _head_y(grid_height / 2) {}

  void Update();

  void GrowBody();
  bool SnakeCell(int x, int y);

  Direction direction = Direction::kUp;

  /* Setters and Getters for _speed variable */
  void setSpeed(float speed);
  float getSpeed() const;

  /* Setters and Getters for _size variable */
  void setSize(int size);
  int getSize() const;

  /* Setters and Getters for _alive variable */
  void setAlive(bool alive);
  bool getAlive() const;

  /* Setters and Getter for _head_x and _head_y */
  void setHead_x(float head_x);
  float getHead_x()const;
  void setHead_y(float head_y);
  float getHead_y()const;

  std::vector<SDL_Point> body;

  /* Setters and Getter for _growing */
  void setGrowing(bool growing);
  bool getGrowing()const;

private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  float _speed{0.1f};
  int _size{1};
  bool _alive{true};

  float _head_x;
  float _head_y;

  bool _growing{false};

  int grid_width;
  int grid_height;
};

#endif