#include <iostream>
#include <fstream>
#include <utility>

using namespace std;

// check if interval1 is fully included in interval2
bool isIncluded(pair<int, int> &interval1, pair<int, int> &interval2)
{
  return (interval1.second <= interval2.second &&
          interval1.first >= interval2.first);
}

bool isOverlapping(pair<int, int> &interval1, pair<int, int> &interval2)
{
  return (
      (interval1.first >= interval2.first && interval1.first <= interval2.second) ||
      (interval1.second >= interval2.first && interval1.second <= interval2.second));
}

int main()
{
  fstream section_file;
  section_file.open("04-sections.txt", ios::in);

  if (section_file.is_open())
  {
    string line;
    int count_included = 0;
    int count_overlap = 0;

    while (getline(section_file, line))
    {
      // cout << line << endl;
      pair<int, int> interval1;
      pair<int, int> interval2;

      std::string::size_type sz;

      interval1.first = stoi(line, &sz);
      line = line.substr(sz + 1);
      interval1.second = stoi(line, &sz);
      line = line.substr(sz + 1);
      interval2.first = stoi(line, &sz);
      line = line.substr(sz + 1);
      interval2.second = stoi(line, &sz);

      // cout << interval1.first << ", " << interval1.second << "\t"
      //      << interval2.first << ", " << interval2.second << "\t"
      //      << endl;

      if (isIncluded(interval1, interval2) || isIncluded(interval2, interval1))
      {
        count_included++;
      }
      if (isOverlapping(interval1, interval2) ||
          isOverlapping(interval2, interval1))
      {
        // cout << interval1.first << ", " << interval1.second << "\t"
        //      << interval2.first << ", " << interval2.second << "\t"
        //      << endl;
        // cout << "Overlap found" << endl;
        count_overlap++;
      }
    }

    cout << "Included intervals count : " << count_included << endl;
    cout << "Overlapping intervals count : " << count_overlap << endl;
  }
}