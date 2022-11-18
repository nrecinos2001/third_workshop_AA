#include <iostream>

using namespace std;

// initialize function to calculate minimum money needed
int minimum_fuel_calculator(int cities_number, int tank_max_capacity)
{
  // Declare and initialize variables for current litters, required litters and litter to fill
  int current_litters = 0, required_litters = cities_number - 1, litters_to_fill = 0;
  // Declare array for memorization
  int cost[cities_number];
  // Initialize firs position with zero
  cost[0] = 0;

  // Initialize for from 1 to cities numbers
  for (int i = 1; i < cities_number; i++)
  {
    // if the require liters are not 0...
    if (required_litters > 0)
    {
      // take the min between the max capacity of the tank minus the current litters and, the required litters
      litters_to_fill = min(tank_max_capacity - current_litters, required_litters);
      // sum the litters to fill to the current litters
      current_litters += litters_to_fill;
      // subtract 1 from the current litters
      current_litters += -1;
      // assign the cost in the previous position plus the litters to fill multiplied by
      // the i to the cost array in the position i
      cost[i] = cost[i - 1] + (litters_to_fill * i);
      // subtract litters to fill from require litters
      required_litters -= litters_to_fill;
    }
    // if does not reach the condition
    else
    {
      // assign the cost in the previous position to the actual position on costs array
      cost[i] = cost[i - 1];
    }
  }
  // return the value in the position cities_number minus one, from the costs array
  return cost[cities_number - 1];
}

int main()
{
  // declare variables which will be asked for to the user
  int cities_number = 0, tank_max_capacity = 0, minimum_money_needed = 0;
  // ask and validate the number of cities
  do
  {
    cout << "Type the number of cities to visit: ";
    cin >> cities_number;
  } while (cities_number < 2 || cities_number > 100);
  // ask and validate the tank's maximum capacity
  do
  {
    cout << "Type the your tank's maximum capacity of fuel in litters: ";
    cin >> tank_max_capacity;
  } while (cities_number < 1 || cities_number > 100);

  // call the function to calculate and assign it to a variable
  minimum_money_needed = minimum_fuel_calculator(cities_number, tank_max_capacity);

  // print the response to the user
  cout << "You need at least $" << minimum_money_needed << " for fuel in order to complete the travel.\n";

  // finish program
  return 0;
}