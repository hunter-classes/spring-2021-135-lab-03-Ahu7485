#include "reservoir.h"
#include "reverseorder.h"

int main()
{
  std::cout << "Lab Part A" << "\n";
  std::cout << get_east_storage("05/12/2018") << " billion gallons\n";
  std::cout << get_east_storage("09/13/2018") << " billion gallons\n";
  std::cout << get_east_storage("02/14/2018") << " billion gallons\n";
  std::cout << "Lab Part B" << "\n";
  std::cout << "Smallest:  " << get_min_east() << " billion gallons\n";
  std::cout << "Lardgest:  " << get_max_east() << " billion gallons\n";
  std::cout << "Lab Part C" << "\n";
  std::cout << compare_basins("06/24/2018") << "\n";
  std::cout << compare_basins("07/24/2018") << "\n";
  std::cout << compare_basins("06/04/2018") << "\n";
  std::cout << "Lab Part D" << "\n";
  reverse_order("06/25/2018", "07/04/2018");
  
  return 0;
}
