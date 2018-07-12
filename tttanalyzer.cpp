// Copyright 2018 Chuqiao Liang chuqiao@bu.edu
// Copyright 2018 Felipe Dale Figeman fdale@bu.edu

#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "movedef.h"
using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::map;

char invalid(string tttboard) {
  int numx = 0, numo = 0, numblank = 0;
  if (tttboard.length() != 9) return 'e';
  for (int i = 0; i < 9 ; i++) {
    if (tttboard[i] == 'o') {
      numo += 1;
    } else if (tttboard[i] == 'x') {
      numx += 1;
    } else if (tttboard[i] == '#') {
      numblank += 1;
    } else {
      return 'e';
    }
  }
  if ((numo > numx) || ((numx - numo) > 1)) return 'i';
}

char tttresult(string board) {
  int counthash = 0, numo = 0, resulto = 0, numx = 0, resultx = 0;
  char inval = invalid(board);
  if (inval == 'i' || inval == 'e') return inval;
  char b[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      b[i][j] = board[3 * i + j];
      if (b[i][j] == '#') {
        counthash += 1;
      } else if (b[i][j] == 'x') {
        numx += 1;
      } else if (b[i][j] == 'o') {
        numo += 1;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (b[i][0] == 'x' && b[i][1] == 'x' && b[i][2] == 'x' ||
        b[0][i] == 'x' && b[1][i] == 'x' && b[2][i] == 'x') resultx = 1;
    if (b[i][0] == 'o' && b[i][1] == 'o' && b[i][2] == 'o' ||
        b[0][i] == 'o' && b[1][i] == 'o' && b[2][i] == 'o') resulto = 1;
  }
  if (b[0][0] == 'x' && b[1][1] == 'x' && b[2][2] == 'x' ||
      b[0][2] == 'x' && b[1][1] == 'x' && b[2][0] == 'x') resultx = 1;
  if (b[0][0] == 'o' && b[1][1] == 'o' && b[2][2] == 'o' ||
      b[0][2] == 'o' && b[1][1] == 'o' && b[2][0] == 'o') resulto = 1;
  if (resulto + resultx > 1) return 'i';
  if (resultx == 1) {
    if (numx > numo) {
      return 'x';
    } else {
      return 'i';
    }
  }
  if (resulto == 1) {
    if (numx == numo) {
      return 'o';
    } else {
      return 'i';
    }
  }
  if (counthash == 0) return 't';
  return 'c';
}

char tttresult(vector<Move> board) {
  std::string blankboard = "#########";
  for (int i = 0; i < board.size(); i++) {
    if ((board[i].r > 2 || board[i].c > 2)) return 'e';
    int position = 3 * (board[i].r) + board[i].c;
    if (blankboard[position] == '#') {
      blankboard[position] = board[i].player;
    } else {
      return 'e';
    }
  }
  return tttresult(blankboard);
}

string dectoboar(int iter) {
  // turns decimal number input into a base 3 string representation
  string outstr = "000000000";  // Didn't want to google preallocation
  int mult = 1, intnum = 0, pow = 9;
  for (int i = 0; i < 9; ++i) {
    for (int j = 1; j < pow; ++j) {
      mult = mult * 3;
    }
    intnum = iter / mult;
    if (intnum == 0) {
      outstr[i] = static_cast<char>(35);
    } else {
      if (intnum == 1) {
        outstr[i] = static_cast<char>(120);
      } else {
        outstr[i] = static_cast<char>(111);
      }
    }
    // outstr[i]=char((iter/mult)+48);
    iter = iter - intnum * mult;
    mult = 1;
    pow -= 1;
  }
  return outstr;
}

vector<string> get_all_boards() {
  // Iterates from 0 to 3^9 and makes all possible boards
  // stored in a vector of strings
  vector<string>boards;
  string intstr = "000000000";
  for (int i = 0; i < 19683; ++i) {
    intstr = dectoboar(i);
    boards.push_back(intstr);
    intstr = "000000000";
  }
  return boards;
}

// MAIN

int main() {
  vector<string>boards = get_all_boards();
  int tiems = 19683, xc = 0, oc = 0, tc = 0, ic = 0, cc = 0;
  char intchar;
  for (int i = 0; i < tiems; ++i) {
    intchar = tttresult(boards[(i)]);
    if (intchar == 'x') {
      xc = xc + 1;
    } else {
      if (intchar == 'o') {
        oc = oc + 1;
      } else {
        if (intchar == 't') {
          tc = tc + 1;
        } else {
          if (intchar == 'i') {
            ic = ic + 1;
          } else {
            if (intchar == 'c') {
              cc = cc + 1;
            }
          }
        }
      }
    }
  }
  cout << "x " << xc;
  cout << "\no " << oc;
  cout << "\nt " << tc;
  cout << "\ni " << ic;
  cout << "\nc " << cc << "\n";
}

