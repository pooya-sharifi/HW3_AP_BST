#include "bst.h"
#include <vector>
// inke children nadashte bashe null ptr bezare
BST::Node::Node(int _value, Node* _left, Node* _right)
    : value { _value }
    , left { _left }
    , right { _right }
{
}
BST::Node::Node(const Node& node)
    : value { node.value }
    , left { node.left }
    , right { node.right }
{
}

std::ostream& operator<<(std::ostream& os, const BST::Node& node)
{
    os << "Vector: ";
    os << node.value;
    return os;
}
BST::Node*& BST::get_root()
{
    return root;
}
bool BST::add_node(int _value)
{
    auto pnt_new = root;
    if (root == nullptr) {
        BST::Node khers1(_value, nullptr, nullptr);
        root = new Node(khers1);
        std::cout << "poopy butthole" << &khers1 << khers1 << root << *root << root->value << std::endl;

    } else {
        BST::Node khers1(_value, nullptr, nullptr);
        while (true) {
            std::cout << "miyad tooye while" << std::endl;
            if (_value > pnt_new->value) {
                std::cout << "miyad tooye >" << std::endl;
                std::cout << "enter 1";
                // pnt_new = (pnt_new->right);
                std::cout << "adresse baade bozorgtar" << pnt_new << std::endl;
                if (pnt_new->right == nullptr) {
                    pnt_new->right = new Node(khers1);
                    std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
                    return 1;
                }
                pnt_new = pnt_new->right;

            } else if (_value < pnt_new->value) {
                std::cout << "miyad tooye <" << std::endl;
                std::cout << " adresse baade koochik" << pnt_new << std::endl;
                if (pnt_new->left == nullptr) {
                    pnt_new->left = new Node(khers1);
                    std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
                    return 1;
                }
                pnt_new = pnt_new->left;
            } else {
                return false;
            }
        }

        // std::cout << "new mikone" << std::endl;
        // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
    }
    // root->left = new Node(khers1);
}
void BST::bfs(std::function<void(Node*& node)> func)
{

    std::vector<Node*> queue;
    std::vector<int> visited;
    size_t i = 0;
    auto pnt_standin = root;
    queue.push_back(pnt_standin);
    while (true) {

        std::cout << "BOOOOM" << i << std::endl;
        visited.push_back(queue[0]->value);
        std::cout << "PAWWWWW" << i << std::endl;
        std::cout << queue[0] << std::endl;
        std::cout << queue[0]->value << std::endl;
        queue.erase(queue.begin());
        std::cout << "visited:" << visited[i] << std::endl;

        if (pnt_standin->left != nullptr) {
            std::cout << "goosfand biya inja dige" << std::endl;
            queue.push_back(pnt_standin->left);
        }
        if (pnt_standin->right != nullptr) {
            std::cout << "goosfand biya inja dige" << std::endl;
            queue.push_back(pnt_standin->right);
        }
        if (queue.size() == 0) {
            // return i + 1;
        }
        i++;
        pnt_standin = queue[0];
        // func(visited[i]);
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
}
size_t BST::length()
{
    std::vector<Node*> queue;
    std::vector<int> visited;
    // queue[0] = root->value;
    // queue[1] = root->right;
    // queue[2] = root->left;
    size_t i = 0;
    auto pnt_standin = root;
    queue.push_back(pnt_standin);
    while (true) {

        std::cout << "BOOOOM" << i << std::endl;
        visited.push_back(queue[0]->value);
        std::cout << "PAWWWWW" << i << std::endl;
        std::cout << queue[0] << std::endl;
        std::cout << queue[0]->value << std::endl;
        queue.erase(queue.begin());
        std::cout << "visited:" << visited[i] << std::endl;

        if (pnt_standin->left != nullptr) {
            std::cout << "goosfand biya inja dige" << std::endl;
            queue.push_back(pnt_standin->left);
        }
        if (pnt_standin->right != nullptr) {
            std::cout << "goosfand biya inja dige" << std::endl;
            queue.push_back(pnt_standin->right);
        }
        if (queue.size() == 0) {
            return i + 1;
        }
        i++;
        pnt_standin = queue[0];
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
}
std::ostream& operator<<(std::ostream& os, const BST bst)
{
    os << "*******************************************************************************************" << std::endl;

    std::vector<BST::Node*> queue;
    std::vector<int> visited;
    // queue[0] = root->value;
    // queue[1] = root->right;
    // queue[2] = root->left;
    size_t i = 0;
    auto pnt_standin = bst.root;
    queue.push_back(pnt_standin);
    size_t flag { 0 };
    while (flag == 0) {

        visited.push_back(queue[0]->value);
        os << queue[0] << "             ";
        os << "=>";
        os << "value: ";
        os << queue[0]->value;
        queue.erase(queue.begin());
        os << "              ";

        if (pnt_standin->left != nullptr) {
            os << "left:";
            queue.push_back(pnt_standin->left);
            os << pnt_standin->left;
            os << "              ";
        } else {
            os << "left:";
            os << 0 << "            ";
        }
        if (pnt_standin->right != nullptr) {
            os << "right:";
            queue.push_back(pnt_standin->right);
            os << pnt_standin->right;
            os << "             ";
        } else {
            os << "right:";
            os << 0 << "            ";
        }
        if (queue.size() == 0) {
            flag = 1;
        }
        i++;
        pnt_standin = queue[0];
        os << std::endl;
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
    os << "*******************************************************************************************" << std::endl;
    return os;
}
