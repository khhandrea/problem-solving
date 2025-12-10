#include <cstring>
#include <iostream>
#include <map>
#include <set>

struct Coord {
  short row;
  short col;

  bool operator<(Coord const &other) const {
    if (row != other.row) {
      return (row < other.row);
    }
    return (col < other.col);
  }

  bool operator==(Coord const &other) const {
    return (row == other.row && col == other.col);
  }

  Coord operator+(Coord const &other) const {
    Coord result;
    result.row = row + other.row;
    result.col = col + other.col;
    return result;
  }
};

Coord adj[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

class Field {
private:
  short max_row, max_col;
  std::map<Coord, Coord> parents;

public:
  Field(short N, short M) {
    this->max_row = N;
    this->max_col = M;
  }

  Coord find(Coord point) {
    if (parents[point] == point) {
      return point;
    }
    return find(parents[point]);
  }

  void union_points(Coord p1, Coord p2) {
    parents[find(p1)] = find(p2);
  }

  void add_point(Coord point) {
    Coord adj_point;

    parents.insert({point, point});

    for (short i = 0; i < 4; i++) {
      adj_point = point + adj[i];
      if (parents.find(adj_point) == parents.end()
          || adj_point.row < 0 || adj_point.row >= max_row
          || adj_point.col < 0 || adj_point.col >= max_col) {
        continue;
      }

      if (parents.find(adj_point) == parents.end()) {
        parents.insert({adj_point, adj_point});
      }
      union_points(point, adj_point);
    }
  }

  short get_size() {
    std::set<Coord> group;
    for (auto iter = parents.begin(); iter != parents.end(); iter++) {
      group.insert(find(iter->second));
    }
    return group.size();
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  short T, M, N, K, row, col;
  Field *field;
  Coord coord;

  std::cin >> T;
  for (short t = 0; t < T; t++) {
    std::cin >> M >> N >> K;
    field = new Field(N, M);
    for (short k = 0; k < K; k++) {
      std::cin >> coord.col >> coord.row;
      field->add_point(coord);
    }
    std::cout << field->get_size() << '\n';
    delete field;
  }

  return 0;
}
