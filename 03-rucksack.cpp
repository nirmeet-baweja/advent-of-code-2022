#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
  fstream rucksack_file;
  rucksack_file.open("rucksack.txt", ios::in);

  if (rucksack_file.is_open())
  {
    cout << "File open" << endl;
    string line;
    int total_points = 0;

    while (getline(rucksack_file, line))
    {
      unordered_set<char> char_set;
      int len = line.size();
      int priority = 0;

      for (int i = 0; i < len / 2; i++)
      {
        char_set.insert(line[i]);
      }

      for (int i = len / 2; i < len; i++)
      {
        if (char_set.count(line[i]) == 1)
        {
          if (line[i] >= 'a' && line[i] <= 'z')
            priority = line[i] - 'a' + 1;
          if (line[i] >= 'A' && line[i] <= 'Z')
            priority = line[i] - 'A' + 27;

          break;
        }
      }

      total_points += priority;
    }
    cout << "Total Points: " << total_points << endl;
    rucksack_file.close();
  }

  // find badges
  rucksack_file.open("rucksack.txt", ios::in);

  if (rucksack_file.is_open())
  {
    cout << "File open" << endl;
    string line;
    int total_points = 0;
    int count = 1;

    string line1, line2, line3;

    while (getline(rucksack_file, line))
    {
      int priority = 0;
      if (count % 3 == 1)
      {
        line1 = line;
      }
      else if (count % 3 == 2)
      {
        line2 = line;
      }
      else
      {
        line3 = line;

        for (int i = 0; i < line3.size(); i++)
        {
          if (line1.find(line3[i]) != string::npos &&
              line2.find(line3[i]) != string::npos)
          {
            if (line[i] >= 'a' && line[i] <= 'z')
              priority = line[i] - 'a' + 1;

            if (line[i] >= 'A' && line[i] <= 'Z')
              priority = line[i] - 'A' + 27;

            total_points += priority;
            break;
          }
        }
      }

      count++;
    }
    cout << "Total Points: " << total_points << endl;
    rucksack_file.close();
  }
}