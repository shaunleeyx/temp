//
// Created by Shaun Lee on 2020-04-22.
//

#include "robot.h"
#include <iostream>
robot::robot(std::string str)
{
    row = 5;
    column = 5;
    state = true;
    std::string text;
    std::ifstream file(str);
    if (file.is_open())
    {
      for(int r = 0; r <= 10; r++)
      {
          for(int c = 0; c <= 10; c++)
          {
              std::string temp;
              file >> temp;
              grid[r][c] = stoi(temp);
          }
      }
    file.close();
    }
}