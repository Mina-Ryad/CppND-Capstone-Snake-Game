#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update()
{
  SDL_Point prev_cell{
      static_cast<int>(_head_x),
      static_cast<int>(
          _head_y)}; // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(_head_x),
      static_cast<int>(_head_y)}; // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y)
  {
    UpdateBody(current_cell, prev_cell);
  }
}

void Snake::UpdateHead()
{
  switch (direction)
  {
  case Direction::kUp:
    setHead_y(getHead_y() - getSpeed());
    break;

  case Direction::kDown:
    setHead_y(getHead_y() + getSpeed());
    break;

  case Direction::kLeft:
    setHead_x(getHead_x() - getSpeed());
    break;

  case Direction::kRight:
    setHead_x(getHead_x() + getSpeed());

    break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  setHead_x(fmod(getHead_x() + grid_width, grid_width));
  setHead_y(fmod(getHead_y() + grid_height, grid_height));
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell)
{
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!_growing)
  {
    // Remove the tail from the vector.
    body.erase(body.begin());
  }
  else
  {
    _growing = false;
    Snake::setSize(Snake::getSize() + 1);
  }

  // Check if the snake has died.
  for (auto const &item : body)
  {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y)
    {
      setAlive(false);
    }
  }
}

void Snake::GrowBody() { _growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y)
{
  if (x == static_cast<int>(getHead_x()) && y == static_cast<int>(getHead_y()))
  {
    return true;
  }
  for (auto const &item : body)
  {
    if (x == item.x && y == item.y)
    {
      return true;
    }
  }
  return false;
}

void Snake::setSpeed(float speed)
{
  _speed = speed;
}

float Snake::getSpeed() const
{
  return _speed;
}

void Snake::setSize(int size)
{
  _size = size;
}
int Snake::getSize() const
{
  return _size;
}

void Snake::setAlive(bool alive)
{
  _alive = alive;
}
bool Snake::getAlive() const
{
  return _alive;
}

void Snake::setHead_x(float head_x)
{
  _head_x = head_x;
}
float Snake::getHead_x() const
{
  return _head_x;
}
void Snake::setHead_y(float head_y)
{
  _head_y = head_y;
}
float Snake::getHead_y() const
{
  return _head_y;
}

void Snake::setGrowing(bool growing)
{
  _growing = growing;
}
bool Snake::getGrowing() const
{
  return _growing;
}