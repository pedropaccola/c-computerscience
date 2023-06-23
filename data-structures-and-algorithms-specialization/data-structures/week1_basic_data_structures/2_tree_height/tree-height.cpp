#include <algorithm>
#include <iostream>
#include <vector>

// Commented code is with pointers. I'm not sure which one is better

class Node;

class Node {
public:
  int key;
  Node *parent;
  std::vector<Node *> children;

  Node() { this->parent = nullptr; }
};

int DFS(Node *root) {
  int max_height = 0;

  for (Node *child : root->children) {
    max_height = std::max(max_height, DFS(child));
  }
  return max_height + 1;
}

int main(int argc, char **argv) {
  int n;
  std::cin >> n;

  // std::vector<Node *> nodes;
  std::vector<Node> nodes(n);
  // nodes.resize(n);

  Node *root = nullptr;

  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;

    // if (!nodes[child_index]) {
    //   nodes[child_index] = new Node();
    // }

    if (parent_index >= 0) {
      // if (!nodes[parent_index]) {
      //   nodes[parent_index] = new Node();
      // }
      nodes[child_index].parent = &nodes[parent_index];
      // nodes[child_index]->parent = nodes[parent_index];
      nodes[child_index].parent->children.push_back(&nodes[child_index]);
      // nodes[child_index]->parent->children.push_back(nodes[child_index]);
    } else {
      root = &nodes[child_index];
      // root = nodes[child_index];
    }

    nodes[child_index].key = child_index;
    // nodes[child_index]->key = child_index;
  }

  int height = DFS(root);
  std::cout << height << std::endl;

  // for (int i = 0; i < n; i++) {
  //   delete nodes[i];
  // }

  return 0;
}
