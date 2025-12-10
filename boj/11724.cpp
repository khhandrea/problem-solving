#include <iostream>

class Group {
public:
  short *parents;
  short size, group_u, group_v;

  Group(short max_size) {
    parents = new short[max_size];
    size = max_size;
    for (short i = 0; i < max_size; i++) {
      parents[i] = i;
    }
  }
  
  short get_group(short x) {
    if (parents[x] == x) {
      return x;
    }
    return parents[x] = get_group(parents[x]);
  }

  void union_nodes(short u, short v) {
    group_u = get_group(u);
    group_v = get_group(v);
    if (group_u == group_v) {
      return;
    }

    parents[get_group(v)] = get_group(u);
    size--;
  }
};

int main() {
  short N, u, v;
  int M;
  Group *group;

  std::cin >> N >> M;
  group = new Group(N);
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    group->union_nodes(u - 1, v - 1);
  }

  std::cout << group->size << '\n';

  return 0;
}
