
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>

int main() {
  std::fstream inventory_file;
  inventory_file.open("./inventory.txt", std::ios::in);
  std::vector<long> sums;

  if(inventory_file.is_open()) {
    std::cout << "File open" << std::endl;
    long sum = 0;
    long max_sum = 0;
    long calorie;
    std::string line;
    // int i = 0;
    while (getline(inventory_file, line))
    {
      if(line != "") {
        calorie = stol(line);
        sum += calorie;
        // std::cout << "Calorie: " << calorie << ", ";
        // std::cout << "Sum:" << sum << std::endl;
      } else {
        if(sum > max_sum) {
          max_sum = sum;
        }
        sums.push_back(sum);
        sum = 0;
        // std::cout << "Found an empty line." << std::endl;
        // std::cout << "Max Sum so far is: " << max_sum << std::endl;
      }
    }
    inventory_file.close();
    std::cout << "Max Sum so far is: " << max_sum << std::endl;

    sort(sums.begin(), sums.end(), std::greater<>());

    long max_three_sum = sums[0] + sums[1] + sums[2];

    std::cout << "Max 3 Sum so far is: " << max_three_sum << std::endl;
  } else {
    std::cout << "Failed to open" << std::endl;
  }
}