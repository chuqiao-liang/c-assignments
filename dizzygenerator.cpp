// Copyright 2018 Chuqiao Liang chuqiao@bu.edu

#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#include "timer.h"

using std::vector;
using std::string;
using std::to_string;
using std::set;
using std::unordered_set;
using std::cout;


const int MYLIMIT = 4000000;
const int MYTRUE = 101;
const int MYFALSE = 102;
vector<int> base10cache(MYLIMIT, 0);

void tentobase(int num, int tobase, vector<int>& digitreps) {
  digitreps.clear();
  int digit;
  while (num > 0) {
    digit = num % tobase;
    digitreps.push_back(digit);
    num /= tobase;
  }
}

struct dizzyGenerator {
  std::vector<int> find_dizzy_up_to(int last, const int base = 10) {
    vector<int> dizzynums;
    int num = 1;
    while (num <= last) {
      if (is_dizzy(num, base)) {
        dizzynums.push_back(num);
      }
      num += 1;
    }
    return dizzynums;
  }
  std::vector<int> dizziness_cycle(int number, int base = 10) {
    vector<int> cyclenums;
    vector<int> digitreps;
    unordered_set<int> cycleset;
    std::vector<int>::iterator it;
    int sum = 0;
    int digit;
    cyclenums.push_back(number);
    // cycleset.insert(number);
    tentobase(number, base, digitreps);
    while (sum != 1) {
      sum = 0;
      for (it = digitreps.begin(); it != digitreps.end(); ++it) {
        sum += (*it) * (*it);
      }
      // if (cycleset.find(sum) != cycleset.end()) {
      if (std::find(cyclenums.begin(), cyclenums.end(), sum)
          != cyclenums.end()) {
        break;
      }
      cyclenums.push_back(sum);
      // cycleset.insert(sum);
      tentobase(sum, base, digitreps);
    }
    if (sum == 1) {
      cyclenums.clear();
      cyclenums.push_back(1);
      return cyclenums;
    }
    it = std::find(cyclenums.begin(), cyclenums.end(), sum);
    cyclenums.erase(cyclenums.begin(), it);
    return cyclenums;
  }
  bool is_dizzy(int number, int base = 10) {
    if (base == 2) return true;
    base10cache.reserve(MYLIMIT);
    if (number < MYLIMIT && base == 10) {
      if (base10cache.at(number) == MYTRUE) {
        return true;
      } else if (base10cache.at(number) == MYFALSE) {
        return false;
      }
    }
    set<int> allnums;
    int sum = 0;
    vector <int> digitreps;
    tentobase(number, base, digitreps);
    std::vector<int>::iterator it;
    while (sum != 1) {
      sum = 0;
      for (it = digitreps.begin(); it != digitreps.end(); ++it) {
        sum += (*it) * (*it);
      }
      if (number < MYLIMIT && base == 10) {
        if (base10cache.at(sum) == MYTRUE) {
          base10cache.at(number) = MYTRUE;
          return true;
        } else if (base10cache.at(sum) == MYFALSE) {
          base10cache.at(number) = MYFALSE;
          return false;
        }
      }
      tentobase(sum, base, digitreps);
      if (allnums.find(sum) != allnums.end()) {
        if (number < MYLIMIT && base == 10) {
          base10cache.at(number) = MYFALSE;
        }
        return false;
      }
      allnums.insert(sum);
    }
    if (number < MYLIMIT && base == 10) {
      base10cache.at(number) = MYTRUE;
    }
    return true;
  }
};


// MAIN   leave this line and all below as is
//        when submitting


const double TLIMIT = 0.5;

void standard_tests();
void interactive_main();

int main(int argc, const char **argv) {
  if (argc > 1)
    interactive_main();
  else
    standard_tests();
  return 0;
}

void standard_tests() {
  double speed = computer_speed();
  std::cerr << "Your computers speed relative to server: " << speed << "\n";

  Timer tall, t0("setup"), t1("all100");
  Timer t3("lots_of_base_10"), t4("lots_of_bases");


  std::vector<std::pair<int, int>> res;

  t0.start();
  dizzyGenerator h;
  t0.stop();

  // Test case definitions.
  std::vector<int> dizzy_tests_one{1, 4, 7, 145, 91, 31435135};
  std::vector<std::vector<int>> dizzy_tests_two{{14500, 10}, {2, 3},
    {255, 2}, {255, 4}, {998, 998}, {4, 10}, {7, 3},
    {41, 100}, {234, 100}, {124, 100}, {22357, 1000}, {1049, 1000}};
  std::vector<std::vector<int>> find_upto_tests_two{{100, 3},
    {1000, 11}, {20, 2}};
  std::vector<int> find_upto_tests_one{10, 100};

  std::cout << "Testing is_dizzy (two parameters)\n";
  for (auto e : dizzy_tests_two) {
    std::cout << "is_dizzy(" << e.at(0) << "," << e.at(1) << ") = ";
    std::cout << h.is_dizzy(e.at(0), e.at(1)) << "\n";
  }

  std::cout << "Testing is_dizzy (one parameter)\n";
  for (auto e : dizzy_tests_one) {
    std::cout << "is_dizzy(" << e << ") = ";
    std::cout << h.is_dizzy(e) << "\n";
  }

  std::cout << "Testing dizziness_cycle (two parameters)\n";
  for (auto e : dizzy_tests_two) {
    std::cout << "dizziness_cycle(" << e.at(0) << "," << e.at(1) << ") = ";
    for (auto cyc_val : h.dizziness_cycle(e.at(0), e.at(1)))
      std::cout << cyc_val << " ";
    std::cout << "\n";
  }

  std::cout << "Testing dizziness_cycle (one parameter)\n";
  for (auto e : dizzy_tests_one) {
    std::cout << "dizziness_cycle(" << e << ") = ";
    for (auto cyc_val : h.dizziness_cycle(e))
      std::cout << cyc_val << " ";
    std::cout << "\n";
  }

  std::cout << "Testing find_dizzy_up_to (two parameters)\n";
  for (auto e : find_upto_tests_two) {
    std::cout << "find_dizzy_up_to(" << e.at(0) << "," << e.at(1) << ") = ";
    for (auto dizzyval : h.find_dizzy_up_to(e.at(0), e.at(1)))
      std::cout << dizzyval << " ";
    std::cout << "\n";
  }


  std::cout << "Testing find_dizzy_up_to (one parameter)\n";
  for (auto e : find_upto_tests_one) {
    std::cout << "find_dizzy_up_to(" << e << ") = ";
    for (auto dizzynum : h.find_dizzy_up_to(e))
      std::cout << dizzynum << " ";
    std::cout << "\n";
  }


  std::cout << "Finding the dizziest bases\n";

  t1.start();
  for (int i = 2; i < 100; i++) {
    auto v = h.find_dizzy_up_to(100, i);
    res.push_back(std::make_pair(v.size(), i));
  }
  t1.stop();

  std::sort(res.begin(), res.end());

  std::cout << "The ten dizziest bases (for 1 to 100) are \n";
  for (auto it = res.rbegin(); it != res.rbegin() + 10 ; it++)
    std::cout << "base "  << it -> second << " has "
              << it -> first << " dizzy\n";



  std::cout << "\nHow many dizzy can you find in 0.5 seconds, base 10?\n";
  int start_size = 100;
  while (t3.time() < TLIMIT) {
    t3.start();
    std::vector<int> res =  h.find_dizzy_up_to(start_size);
    t3.stop();
    std::vector<uint64_t> locs{0, res.size() / 3,
                               2 * res.size() / 3, res.size() - 1};
    for (auto i : locs) {
      std::cout << "ss:" << start_size << " i: " << i
                << " v: " << res.at(i) << "\n";
    }
    start_size *= 2;
  }



  std::cout << "\nHow many dizzy can you find in 0.5 seconds, all bases?\n";
  int base = 2;
  while (t4.time() < TLIMIT) {
    t4.start();
    std::vector<int> res =  h.find_dizzy_up_to(20000, base);
    t4.stop();
    std::vector<uint64_t> locs{0, res.size() / 3,
                               2 * res.size() / 3, res.size() - 1};
    for (auto i : locs) {
      std::cout << "base:" << base
                << " i: " << i << " v: " << res.at(i) << "\n";
    }
    base *= 2;
  }
}


void interactive_main() {
  std::string asktype;
  int number, parameters, base;
  dizzyGenerator h;

  while (true) {
    std::cin >> asktype;
    if (asktype == "quit") break;
    std::cin >> parameters >> number;
    if (parameters > 1) std::cin >> base;
    if (asktype == "i" and parameters == 2) {
      std::cout << "is_dizzy(" << number << "," << base << ") = ";
      std::cout << h.is_dizzy(number, base) << "\n";
    } else if (asktype == "i" and parameters == 1) {
      std::cout << "is_dizzy(" << number << ") = ";
      std::cout << h.is_dizzy(number) << "\n";
    } else if (asktype == "c" and parameters == 2) {
      std::cout << "dizziness_cycle(" << number << "," << base << ") = ";
      for (auto cyc_val : h.dizziness_cycle(number, base) )
        std::cout << cyc_val << " ";
      std::cout << "\n";
    } else if (asktype == "c" and parameters == 1) {
      std::cout << "dizziness_cycle(" << number << ") = ";
      for (auto cyc_val : h.dizziness_cycle(number))
        std::cout << cyc_val << " ";
      std::cout << "\n";
    } else if (asktype == "f" and parameters == 2) {
      std::cout << "find_dizzy_up_to(" << number << "," << base << ") = ";
      for (auto dizzyval : h.find_dizzy_up_to(number, base))
        std::cout << dizzyval << " ";
      std::cout << "\n";
    } else if (asktype == "f" and parameters == 1) {
      std::cout << "find_dizzy_up_to(" << number << ") = ";
      for (auto dizzynum : h.find_dizzy_up_to(number))
        std::cout << dizzynum << " ";
      std::cout << "\n";
    }
  }
}

