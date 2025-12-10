#include <iostream>

class Network {
private:
  short num_node;
  short *roots;

public:
  Network(short num_node) {
    this->num_node = num_node;
    roots = new short[num_node];

    for (short i = 0; i < num_node; i++) {
      roots[i] = i;
    }
  }

  short find(short x) {
    if (roots[x] == x) {
      return x;
    }

    return roots[x] = find(roots[x]);
  }

  void union_nodes(short u, short v) {
    roots[find(u)] = find(v);
  }
  
  short num_nodes(short x) {
    short result = 0;
    for (short i = 0; i < num_node; i++) {
      result += (find(i) == find(x));
    }
    return result;
  }
};

int main() {
  short num_node, num_edge, u, v;
  Network *net;

  std::cin >> num_node >> num_edge;
  net = new Network(num_node);

  for (short i = 0; i < num_edge; i++) {
    std::cin >> u >> v;
    net->union_nodes(u - 1, v - 1);
  }

  std::cout << net->num_nodes(0) - 1 << '\n';

  return 0;
}
