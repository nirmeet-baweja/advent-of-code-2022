#include <iostream>
#include <fstream>
#include <unordered_map>

#define ROCK1 A

using namespace std;

int main()
{
  const char ROCK_1 = 'A';
  const char PAPER_1 = 'B';
  const char SCISSOR_1 = 'C';

  const char ROCK_2 = 'X';
  const char PAPER_2 = 'Y';
  const char SCISSOR_2 = 'Z';

  // vector<pair<char, char>> winning_combos={{SCISSOR_1, ROCK_2},
  // {ROCK_1, PAPER_2},
  // {PAPER_1, SCISSOR_2}};

  unordered_map<char, char> winning_combos = {{ROCK_2, SCISSOR_1},
                                              {PAPER_2, ROCK_1},
                                              {SCISSOR_2, PAPER_1}};

  unordered_map<char, char> draw_combos = {{ROCK_2, ROCK_1},
                                           {PAPER_2, PAPER_1},
                                           {SCISSOR_2, SCISSOR_1}};

  fstream strategy_file;
  strategy_file.open("rock-paper-scissor-strategy.txt", ios::in);
  // strategy_file.open("file2.txt", ios::in);

  if (strategy_file.is_open())
  {
    cout << "File open" << endl;
    string line;
    int game_point = 0;
    int move_point = 0;

    int total_score = 0;

    while (getline(strategy_file, line))
    {
      if (draw_combos[line[2]] == line[0])
      {
        game_point = 3;
      }
      else if (winning_combos[line[2]] == line[0])
      {
        game_point = 6;
      }
      else
      {
        game_point = 0;
      }

      if (line[2] == ROCK_2)
      {
        move_point = 1;
      }
      else if (line[2] == PAPER_2)
      {
        move_point = 2;
      }
      else if (line[2] == SCISSOR_2)
      {
        move_point = 3;
      }

      total_score += game_point + move_point;
    }

    cout << "Total Score: " << total_score << endl;
    strategy_file.close();
  }

  // Strategy 2
  const char LOSE = 'X';
  const char DRAW = 'Y';
  const char WIN = 'Z';

  unordered_map<char, char> lose_combos = {{ROCK_1, 'S'},
                                           {PAPER_1, 'R'},
                                           {SCISSOR_1, 'P'}};

  unordered_map<char, char> draw_combos_2 = {{ROCK_1, 'R'},
                                             {PAPER_1, 'P'},
                                             {SCISSOR_1, 'S'}};

  unordered_map<char, char> win_combos = {{ROCK_1, 'P'},
                                          {PAPER_1, 'S'},
                                          {SCISSOR_1, 'R'}};

  unordered_map<char, int> move_score = {{'R', 1},
                                         {'P', 2},
                                         {'S', 3}};

  fstream strategy_file_2;
  strategy_file_2.open("rock-paper-scissor-strategy.txt", ios::in);
  // strategy_file_2.open("file2.txt", ios::in);

  if (strategy_file_2.is_open())
  {
    cout << "File open" << endl;
    string line;
    int game_point = 0;
    int move_point = 0;

    int total_score = 0;

    while (getline(strategy_file_2, line))
    {
      char current_move;
      if (line[2] == LOSE)
      {
        current_move = lose_combos[line[0]];
        game_point = 0;
      }
      else if (line[2] == DRAW)
      {
        current_move = draw_combos_2[line[0]];
        game_point = 3;
      }
      else if (line[2] == WIN)
      {
        current_move = win_combos[line[0]];
        game_point = 6;
      }

      move_point = move_score[current_move];

      total_score += game_point + move_point;
    }
    cout << "Total Score: " << total_score << endl;
    strategy_file_2.close();
  }
}
