#include <iostream>

using namespace std;

int minimum_fuel_calculator(int cities_number, int tank_max_capacity)
{
  int current_litter = 0, required_litters = cities_number - 1, cost = 0;
  int litters_to_fill = 0;

  for (int i = 1; i < cities_number; i++)
  {
    litters_to_fill = min(tank_max_capacity - current_litter, required_litters);
    current_litter += litters_to_fill;
    current_litter += -1;
    cost += (litters_to_fill * i);
    required_litters -= litters_to_fill;
  }
  return cost;
}

int main()
{
  int cities_number = 0, tank_max_capacity = 0, minimum_money_needed = 0;
  cout << "Type the number of cities to visit: ";
  cin >> cities_number;
  cout << "Type the your tank's maximum capacity of fuel in litters: ";
  cin >> tank_max_capacity;

  minimum_money_needed = minimum_fuel_calculator(cities_number, tank_max_capacity);

  cout << "You need at least " << minimum_money_needed << " for fuel in order to complete the travel.";

  return 0;
}