// Copyright 2018 Chuqiao Liang chuqiao@bu.edu

#include <array>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin;
using std::array;
using std::cout;
using std::string;
using std::vector;
using std::unordered_map;
using std::endl;
using std::make_pair;
using std::to_string;

typedef int TileID;

class Tile {
  //   common interface. required.
 public:
  TileID id;
  int size;
  vector <string> tiles;
  void show() const {
    for (int i = 0; i < tiles.size(); i++) {
      cout << tiles.at(i) << endl;
    }
  }
  bool checksize(int N) {
    int rowTextBox{0};
    for (int i{0}; i < tiles.size(); ++i) {
      if (!tiles.at(i).empty()) {
        ++rowTextBox;
        if (tiles.at(i).size() != N) return false;
      } else {
        if (rowTextBox != N) return false;
        else
          rowTextBox = 0;
      }
    }
    return true;
  }
  bool checkcharacters() {
    for (int i{0}; i < tiles.size(); ++i) {
      for (int j{0}; j < tiles.at(i).size(); ++j) {
        if (tiles.at(i).at(j) != '*' && tiles.at(i).at(j) != '.' &&
            tiles.at(i).at(j) != ' ') return false;
        if (tiles.at(i).at(j) == ' ' &&
            tiles.at(i).at(j) != tiles.at(i).at(tiles.size() - 1)) return false;
      }
    }
    return true;
  }
  bool checkempty(int N) {
    int count = 0;
    for (int i = 0; i < tiles.size(); i++) {
      for (int j = 0; j < tiles.at(i).size(); j++) {
        if (tiles.at(i).at(j) == '.') {
          count++;
        }
      }
    }
    if (count == N * N) {
      return false;
    } else {
      return true;
    }
  }

  bool checkconnected() {
    if (tiles.size() == 1) {
      if (tiles.at(0).at(0) == '*') {
        return true;
      }
    }
    int ind = 0;
    bool connected = true;
    int row = tiles.size(), col = tiles.size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (tiles.at(i).at(j) == '*') {
          tiles.at(i).at(j) = 'o';
          ind = j;
          break;
        }
      }

      if (tiles.at(i).at(ind) == 'o')
        break;
    }

    for (int i = 0; i < row ; i++) {
      for (int j = 0; j < col; j++) {
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < row) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (j + 1 < row) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }


          if (i - 1 > 0) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }



    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }

    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three element
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < col; i++) {  // loop 5 times for three lines
      for (int j = 0; j < col; j++) {  // loop for the three elements
        if (tiles.at(i).at(j) == 'o') {
          if (i + 1 < col) {
            if (tiles.at(i + 1).at(j) == '*')
              tiles.at(i + 1).at(j) = 'o';
          }
          if (i - 1 > -1) {
            if (tiles.at(i - 1).at(j) == '*')
              tiles.at(i - 1).at(j) = 'o';
          }
          if (j + 1 < col) {
            if (tiles.at(i).at(j + 1) == '*')
              tiles.at(i).at(j + 1) = 'o';
          }
          if (j - 1 > -1) {
            if (tiles.at(i).at(j - 1) == '*')
              tiles.at(i).at(j - 1) = 'o';
          }
        }
      }
    }
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (tiles.at(i).at(j) == '*') {
          return false;
        }
      }
    }
    for (int c = 0; c < row; c++) {
      for (int d = 0; d < col; d++) {
        if (tiles.at(c).at(d) == 'o')
          tiles.at(c).at(d) = '*';
      }
    }
    return true;
  }




  void upandleft() {
    int rowct = 0;
    int tsize = tiles.size();
    for (int i = 0; i < tsize; i++) {
      if (tiles.at(i).find('*') != std::string::npos) {
        break;
      }
      if (tiles.at(i).find('*') == std::string::npos) {
        tiles.push_back(tiles.at(i));
        rowct++;
      }
    }
    tiles.erase(tiles.begin(), tiles.begin() + rowct);
    tsize = tiles.size();
    int tlength = tiles.at(0).size();
    int numcount = 0;
    int count = 0;
    for (int i = 0; i < tlength; i++) {
      for (int j = 0; j < tsize; j++) {
        if (tiles.at(j).at(i) == '*') {
          goto last;
        }
        if (tiles.at(j).at(i) == '.') {
          count++;
        }
      }
      if (count == tsize) {
        for (int k = 0; k < tsize; k++) {
          tiles.at(k).append(".");
        }
        numcount++;
      }
      count = 0;
    }
last:
    for (int k = 0; k < tsize; k++) {
      tiles.at(k).erase(tiles.at(k).begin(), tiles.at(k).begin() + numcount);
    }
  }

  void rotate() {
    int N = tiles.size();
    int count = 0;  //  start counting blanks in this for loop
    for (int i = 0; i < N; i++) {
      if (tiles.at(i).at(N - 1) == '.') {
        count++;
      }
    }
    if (count == N) {
      for (int x = 0; x < N - 1; x++) {
        for (int y = x; y < N - x - 1; y++) {
          int temp = tiles.at(x).at(y);
          tiles.at(x).at(y) = tiles.at(y).at(N - 1 - x);
          tiles.at(y).at(N - 1 - x) = tiles.at(N - 1 - x).at(N - 1 - y);
          tiles.at(N - 1 - x).at(N - 1 - y) = tiles.at(N - 1 - y).at(x);
          tiles.at(N - 1 - y).at(x) = temp;
        }
      }
      int i, j, k = 0;  //  swap
      string temp(N, ' ');
      for (i = 0; i < N; i++) {
        temp.at(i) = tiles.at(0).at(i);
      }
      for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
          if (i != N - 1) {
            tiles.at(i).at(j) = tiles.at(i + 1).at(j);
            tiles.at(i + 1).at(j) = temp.at(j);
          }
        }
      }
    } else {
      for (int x = 0; x < N - 1; x++) {
        for (int y = x; y < N - x - 1; y++) {
          int temp = tiles.at(x).at(y);
          tiles.at(x).at(y) = tiles.at(y).at(N - 1 - x);
          tiles.at(y).at(N - 1 - x) = tiles.at(N - 1 - x).at(N - 1 - y);
          tiles.at(N - 1 - x).at(N - 1 - y) = tiles.at(N - 1 - y).at(x);
          tiles.at(N - 1 - y).at(x) = temp;
        }
      }
    }
    upandleft();
  }
  void swap_column(int first_col, int second_col) {
    for (int i = 0, length = tiles.size(); i < length; i++) {
      char temp;
      temp = tiles.at(i).at(first_col);
      tiles.at(i).at(first_col) = tiles.at(i).at(second_col);
      tiles.at(i).at(second_col) = temp;
    }
  }

  void swap_row(int first_row, int second_row) {
    for (int i = 0, length = tiles.size(); i < length; i++) {
      char temp;
      temp = tiles.at(first_row).at(i);
      tiles.at(first_row).at(i) = tiles.at(second_row).at(i);
      tiles.at(second_row).at(i) = temp;
    }
  }

  void fliplr() {
    int middle, first = 0, last = 0;
    vector<int> index;
    for (int i = 0, size = tiles.size(); i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (tiles.at(j).at(i) == '*') {
          index.push_back(i);
        }
      }
    }
    first = index.at(0);
    last = index.at(index.size() - 1);
    if ((last - first) % 2 != 0) {
      middle = (last + first) / 2 + 1;
    } else {
      middle = (last + first) / 2;
    }
    for (int i = first; i < middle; i++) {
      swap_column(i, (last - (i - first)));
    }
  }

  void flipud() {
    int middle, first = 0, last = 0;
    vector<int> index;
    for (int i = 0, size = tiles.size(); i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (tiles.at(i).at(j) == '*') {
          index.push_back(i);
        }
      }
    }
    first = index.at(0);
    last = index.at(index.size() - 1);

    if ((last - first) % 2 != 0) {
      middle = (last + first) / 2 + 1;
    } else {
      middle = (last + first) / 2;
    }
    for (int i = first; i < middle; i++) {
      swap_row(i, (last - (i - first)));
    }
  }
};


class Blokus {
 private:
  vector <Tile> onlytiles;
  vector <int> tileids;
  vector <string> board;
  vector <string> mockboard;
  vector <char> mocks = {'1', '2', '3', '4', '5', '6', '7', '8', '9',
                         '^', '$', '@', '#', '(', ')', '0', '%', '-', '~', '!',
                         'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'
                        };

 public:
  Tile* find_tile(TileID id) {
    int index = id - 100;
    Tile* tile = &onlytiles.at(index);
    return tile;
  }

  bool checkduplicate(vector<string> tile1, vector<string> tile2) {
    vector<int> index_tile1;  // stores the indices of stars in tile1
    vector<int> index_tile2;  // stores the indices of stars in tile2
    // tile1 is onlytiles, tile2 is copy
    for (int i = 0; i < tile1.size(); i++) {
      for (int j = 0; j < tile1.size(); j++) {
        if (tile1.at(i).at(j) == '*') {
          index_tile1.push_back(i);
          index_tile1.push_back(j);
        }
      }
    }

    for (int i = 0; i < tile2.size(); i++) {
      for (int j = 0; j < tile2.size(); j++) {
        if (tile2.at(i).at(j) == '*') {
          index_tile2.push_back(i);
          index_tile2.push_back(j);
        }
      }
    }

    if (index_tile1 == index_tile2) {
      return true;
    } else {
      return false;          // the tiles are the same
    }
  }

  void create_piece() {
    Tile t;
    Tile tile_copy, tile_copy2, tile_copy3, tile_copy4, tile_copy5,
         tile_copy6, tile_copy7;
    int dim;
    cin >> dim;
    t.size = dim;
    for (int i = 0; i < dim; i++) {
      string row;
      cin >> row;
      t.tiles.push_back(row);
      // copy the rows to the tile and create 7 copies of it
      tile_copy.tiles.push_back(row);
      // these copies are later used to test for duplicates
      tile_copy2.tiles.push_back(row);
      tile_copy3.tiles.push_back(row);
      tile_copy4.tiles.push_back(row);
      tile_copy5.tiles.push_back(row);
      tile_copy6.tiles.push_back(row);
      tile_copy7.tiles.push_back(row);
    }
    if (t.checksize(dim) == false || t.checkcharacters() == false
        || t.checkempty(dim) == false) {
      cout << "invalid tile" << endl;
    } else if ((t.checkconnected() == false)) {
      cout << "disconnected tile discarded" << endl;
    } else {
      t.upandleft();
      tile_copy.upandleft();
      // copy 1 is unchanged, 2 flipud, 3 fliplr, 4 rotated
      tile_copy2.flipud();
      // 5 flipud then fliplr, 6 rotated twice, 7 rotated three times
      tile_copy2.upandleft();
      tile_copy3.fliplr();
      tile_copy3.upandleft();
      tile_copy4.rotate();
      tile_copy4.upandleft();
      tile_copy5.flipud();
      tile_copy5.fliplr();
      tile_copy5.upandleft();
      tile_copy6.rotate();
      tile_copy6.rotate();
      tile_copy6.upandleft();
      tile_copy7.rotate();
      tile_copy7.rotate();
      tile_copy7.rotate();
      tile_copy7.upandleft();
      vector<Tile> copies;
      copies.push_back(tile_copy);
      copies.push_back(tile_copy2);
      copies.push_back(tile_copy3);
      copies.push_back(tile_copy4);
      copies.push_back(tile_copy5);
      copies.push_back(tile_copy6);
      copies.push_back(tile_copy7);

      for (int i = 0; i < onlytiles.size(); i++)
        for (int j = 0; j < copies.size(); j++)
          if (checkduplicate(copies.at(j).tiles, onlytiles.at(i).tiles)) {
            cout << "duplicate of " << (i + 100) << " discarded" << endl;
            return;
          }

      onlytiles.push_back(t);
      t.id = onlytiles.size() + 99;
      cout << "created tile " << t.id << endl;
      tileids.push_back(t.id);
    }
  }
  void reset() {
    onlytiles.clear();
    tileids.clear();
    board.clear();
    cout << "game reset" << endl;
  }

  void show_tiles() const {
    cout << "tile inventory" << endl;
    for (int i = 0; i < onlytiles.size(); i++) {
      cout << tileids.at(i) << endl;
      onlytiles.at(i).show();
    }
  }

  void show_board() const {
    for (int i = 0; i < board.size(); i++) {
      cout << board.at(i) << endl;
    }
  }

  bool findoverlap(vector<string> temps, int x, int y) {  //  true if overlap
    for (int i = x; i < temps.size() + x; i++) {
      for (int j = y; j < temps.at(0).size() + y; j++) {
        char atplace = temps.at(i - x).at(j - y);
        if ((board.at(i).at(j) == '*') &&  (atplace == '*')) {
          return true;
        }
      }
    }
    return false;
  }
  void play_tile(TileID id, int r, int c) {  // r for row, c for column
    if (id < 100 | id > (onlytiles.size() + 99)) {
      cout << id << " not played" << endl;
    } else {
      auto t = find_tile(id);
      int counth = 0;  //  count number of blanks in column (horizontal)
      int countv = 0;  //  count number of blanks in row (v for vertical)j
      vector<string> temptiles = (*t).tiles;  //  temp var to trim for fit
      for (int i = 0; i < (*t).tiles.size(); i++) {
        for (int j = 0; j < (*t).tiles.at(0).size(); j++) {
          if ((*t).tiles.at(i).at(j) == '.') counth++;
          if ((*t).tiles.at(j).at(i) == '.') countv++;
        }
        if (counth == (*t).tiles.at(0).size()) {
          temptiles.erase(temptiles.begin() + i);
        }
        if (countv == (*t).tiles.size()) {
          for (int k = 0; k < temptiles.size(); k++) {
            temptiles.at(k).erase(i, 1);
          }
        }
        counth = 0;
        countv = 0;
      }
      if ((temptiles.size() + r) > board.size()) {
        cout << id << " not played" << endl;
      } else if ((temptiles.at(0).size() + c) > board.size()) {
        cout << id << " not played" << endl;
      } else if (findoverlap(temptiles, r, c)) {
        cout << id << " not played" << endl;
      } else {
        static int m = 0;
        for (int i = r; i < temptiles.size() + r; i++) {
          for (int j = c; j < temptiles.at(0).size() + c; j++) {
            if (board.at(i).at(j) == '*') {
              board.at(i).at(j) == '*';
            } else {
              board.at(i).at(j) = temptiles.at(i - r).at(j - c);
              if (temptiles.at(i - r).at(j - c) == '*') {
                mockboard.at(i).at(j) = mocks.at(m);
              }
            }
          }
        }
        cout << "played " << id << endl;
        m++;
      }
    }
  }
  void set_size(int size) {
    string row;
    if (board.empty()) {
      for (int i = 0; i < size; i++) {
        row.append(".");
      }
      for (int i = 0; i < size; i++) {
        board.push_back(row);
        mockboard.push_back(row);
      }
    }
    if (size > board.size()) {
      int num = size - board.size();
      string addon;
      string newrow;
      for (int i = 0; i < num; i++) {
        addon.append(".");
      }
      for (int i = 0; i < board.size(); i++) {
        board.at(i).append(addon);
        mockboard.at(i).append(addon);
      }
      for (int i = 0; i < size; i++) {
        newrow.append(".");
      }
      for (int i = 0; i < num; i++) {
        board.push_back(newrow);
        mockboard.push_back(newrow);
      }
    }
    if (size < board.size()) {
      char holder;
      for (int i = 0; i < mockboard.size(); i++) {
        if (mockboard.at(size).at(i) != '.') {
          holder = mockboard.at(size).at(i);
          for (int k = 0; k < mockboard.size(); k++) {
            for (int h = 0; h < mockboard.size(); h++) {
              if (mockboard.at(k).at(h) == holder) {
                mockboard.at(k).at(h) = '.';
              }
            }
          }
        }
      }
      for (int i = 0; i < mockboard.size(); i++) {
        if (mockboard.at(i).at(size) != '.') {
          holder = mockboard.at(i).at(size);
          for (int k = 0; k < mockboard.size(); k++) {
            for (int h = 0; h < mockboard.size(); h++) {
              if (mockboard.at(k).at(h) == holder) {
                mockboard.at(k).at(h) = '.';
              }
            }
          }
        }
      }
      mockboard.erase(mockboard.begin() + size, mockboard.begin() +
                      mockboard.size());  // delete last couple of rows
      for (int i = 0; i < mockboard.size(); i++) {
        mockboard.at(i).erase(size, mockboard.at(i).length());
      }
      board.clear();
      board.resize(mockboard.size());
      for (int i = 0; i < mockboard.size(); i++) {
        for (int j = 0; j < mockboard.size(); j++) {
          if (mockboard.at(i).at(j) != '.') {
            board.at(i).push_back('*');
          } else {
            board.at(i).push_back('.');
          }
        }
      }
    }
  }
};


// MAIN. Do not change the below.



int main() {
  string command;
  Blokus b;

  while (true) {
    cin >> command;
    if (command == "quit")  {
      break;
    } else if (command == "//") {
      getline(cin, command);
    } else if (command == "board") {
      b.show_board();
    } else if (command == "create") {
      b.create_piece();
    } else if (command == "reset") {
      b.reset();
    } else if (command == "show") {
      string arg;
      cin >> arg;
      if (arg == "tiles") {
        b.show_tiles();
      } else {
        auto g = b.find_tile(std::stoi(arg));
        g->show();
      }
    } else if (command == "resize") {
      int newsize;
      cin >> newsize;
      b.set_size(newsize);
      b.show_board();
    } else if (command == "play") {
      TileID id;
      int row, col;
      cin >> id >> row >> col;
      b.play_tile(id, row, col);
    } else if (command == "rotate") {
      TileID id;
      cin >> id;
      auto g = b.find_tile(id);
      g-> rotate();
      cout << "rotated " << id << "\n";
      g->show();
    } else if (command == "fliplr") {
      TileID id;
      cin >> id;
      auto g = b.find_tile(id);
      g->fliplr();
      cout << "fliplr " << id << "\n";
      g->show();
    } else if (command == "flipud") {
      TileID id;
      cin >> id;
      auto g = b.find_tile(id);
      g->flipud();
      cout << "flipud " << id << "\n";
      g->show();
    } else {
      cout << "command not understood.\n";
    }
  }
  cout << "Goodbye\n";
  return 0;
}


