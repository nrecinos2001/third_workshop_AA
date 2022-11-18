#include <iostream>

using namespace std;

int minimum_fuel_calculator(int cities_number, int tank_max_capacity)
{
  int current_litters = 0, required_litters = cities_number - 1;
  int cost[cities_number];
  cost[0] = 0;
  int litters_to_fill = 0;

  for (int i = 1; i < cities_number; i++)
  {
    if (required_litters > 0)
    {
      litters_to_fill = min(tank_max_capacity - current_litters, required_litters);
      current_litters += litters_to_fill;
      current_litters += -1;
      cost[i] = cost[i - 1] + (litters_to_fill * i);
      required_litters -= litters_to_fill;
    }
    else
    {
      cost[i] = cost[i - 1];
    }
  }
  return cost[cities_number - 1];
}

int main()
{
  int cities_number = 0, tank_max_capacity = 0, minimum_money_needed = 0;
  do
  {
    cout << "Type the number of cities to visit: ";
    cin >> cities_number;
  } while (cities_number < 2 || cities_number > 100);

  do
  {
    cout << "Type the your tank's maximum capacity of fuel in litters: ";
    cin >> tank_max_capacity;
  } while (cities_number < 1 || cities_number > 100);

  minimum_money_needed = minimum_fuel_calculator(cities_number, tank_max_capacity);

  cout << "You need at least $" << minimum_money_needed << " for fuel in order to complete the travel.\n";

  return 0;
}