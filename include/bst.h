#ifndef BST_H
#define BST_H
#include <compare>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>

class BST {
public:
    // koja bayad in ro copye konim?
    class Node {
    public:
        Node(int value, Node* left, Node* right);
        Node() = default;
        Node(const Node& node);
        //??
        std::partial_ordering operator<=>(int value_enter) const { return value <=> value_enter; };
        bool operator==(int value_enter) const { return value == value_enter; };
        //
        friend std::ostream& operator<<(std::ostream& os, const BST::Node& node);
        //

        int value;
        Node* left;
        Node* right;
    };
    //??
    friend std::ostream& operator<<(std::ostream& os, const BST bst);
    //??
    Node*& get_root();
    void bfs(std::function<void(Node*& node)> func);
    size_t length();
    bool add_node(int _value);
    Node** find_node(int value);
    Node** find_parrent(int value);
    Node** find_successor(int value);
    bool delete_node(int value);

private:
    Node* root;
};

#endif // BST_H