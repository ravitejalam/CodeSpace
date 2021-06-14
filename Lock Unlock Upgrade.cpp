#include "bits/stdc++.h"

using namespace std;

class Node {
public:
    string name;
    int uid = -1;
    vector<Node *> children = {};
    bool isLocked = false;
    int childrenLocked = 0;
    Node *parent = NULL;

    Node(string name) {
        this->name = std::move(name);
    }

    Node(string name, Node *parent) {
        this->name = std::move(name);
        this->parent = parent;
    }
};

bool lock(Node *node, int uid) {
    if (node->childrenLocked || node->isLocked) return false;
    Node *ptr = node;
    while (ptr) {
        if (ptr->isLocked) return false;
        ptr = ptr->parent;
    }
    node->isLocked = true;
    node->uid = uid;
    ptr = node->parent;
    while (ptr) {
        ptr->childrenLocked += 1;
        ptr = ptr->parent;
    }
    return true;
}

bool unlock(Node *node, int uid) {
    if (!node->isLocked || node->uid != uid) return false;
    node->uid = -1;
    node->isLocked = false;
    Node *ptr = node;
    ptr = ptr->parent;
    while (ptr) {
        ptr->childrenLocked -= 1;
        ptr = ptr->parent;
    }
    return true;
}

bool upgrade(Node *node, int uid) {
    if (!node->childrenLocked || node->isLocked) return false;
    vector<Node *> descendants;
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
        Node *ptr = q.front();
        q.pop();
        descendants.push_back(ptr);
        for (auto child: ptr->children) {
            q.push(child);
        }
    }
    for (auto n: descendants) {
        if (n->isLocked && n->uid != uid) {
            return false;
        }
    }
    for (auto n: descendants) {
        unlock(n, uid);
    }
    return lock(node, uid);
}

int main() {
    int nodesCount;
    int childLimit;
    int operations;
    cin >> nodesCount >> childLimit >> operations;
    unordered_map<string, Node *> worldMap;
    vector<Node *> nodes;
    queue<Node *> q;
    for (int i = 0; i < nodesCount; ++i) {
        string name;
        cin >> name;
        Node *node = new Node(name);
        nodes.push_back(node);
        worldMap[name] = node;
    }
    q.push(nodes[0]);
    Node *parent = nullptr;
    for (int i = 1; i < nodesCount;) {
        parent = q.front();
        for (int j = 0; j < childLimit && i < nodesCount; ++j) {
            nodes[i]->parent = parent;
            parent->children.push_back(nodes[i]);
            q.push(nodes[i]);
            i += 1;
        }
        q.pop();
    }
    return 0;
}
