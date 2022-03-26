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
BST::Node& BST::Node::operator=(const BST::Node& node)
{
    std::cout << "operator = of node" << std::endl;
    // delete value;
    delete left;
    delete right;
    // root? new chi?
    value = node.value;
    left = node.left;
    right = node.right;
    return *this;
}

// BST::Node*& BST::Node::operator=(const BST::Node*& node_pnt)
// {
//     std::cout << "operator = of node*" << std::endl;
//     // delete value;
//     delete left;
//     delete right;
//     // root? new chi?
//     value = node_pnt->value;
//     left = node_pnt->left;
//     right = node_pnt->right;
//     return this;
// }

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
        std::cout << "poopy " << &khers1 << khers1 << root << *root << root->value << std::endl;

    } else {
        BST::Node khers1(_value, nullptr, nullptr);
        while (true) {
            // std::cout << "miyad tooye while" << std::endl;
            if (_value > pnt_new->value) {
                // std::cout << "miyad tooye >" << std::endl;
                // std::cout << "enter 1";
                // pnt_new = (pnt_new->right);
                std::cout << "adresse baade bozorgtar" << pnt_new << std::endl;
                if (pnt_new->right == nullptr) {
                    pnt_new->right = new Node(khers1);
                    // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
                    return 1;
                }
                pnt_new = pnt_new->right;

            } else if (_value < pnt_new->value) {

                if (pnt_new->left == nullptr) {
                    pnt_new->left = new Node(khers1);
                    // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
                    return 1;
                }
                pnt_new = pnt_new->left;
            } else {
                std::cout << "miyad tooye else dige" << std::endl;
                return false;
            }
        }

        // std::cout << "new mikone" << std::endl;
        // std::cout << "ina ro mikhaim check konim" << pnt_new << "****" << &khers1 << std::endl;
    }
    // root->left = new Node(khers1);
}
void BST::bfs(std::function<void(BST::Node*& node)> func)
{

    std::vector<BST::Node*> queue;
    std::vector<int> visited;
    // size_t i = 0;
    auto pnt_standin = root;
    // std::cout << *root << std::endl;

    queue.push_back(pnt_standin);
    // std::cout << "root q" << queue[0] << "      " << queue[0]->value << std::endl;

    std::cout << "inja miyad?";

    while (queue.size() != 0 && queue[0] != nullptr) {
        std::cout << "hi" << std::endl;
        visited.push_back(queue[0]->value);
        func(queue[0]);
        queue.erase(queue.begin());
        // queue.erase(queue.begin());
        // std::cout << "visited:" << visited[i] << std::endl;

        if (pnt_standin->left != nullptr) {
            queue.push_back(pnt_standin->left);
        }
        if (pnt_standin->right != nullptr) {
            queue.push_back(pnt_standin->right);
        }
        pnt_standin = queue[0];
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
std::ostream& operator<<(std::ostream& os, const BST& bst)
{
    std::cout << "avalin chizi ke cout mishe" << std::endl;
    os << "*******************************************************************************************" << std::endl;
    std::vector<BST::Node*> queue;
    std::vector<int> visited;
    // queue[0] = root->value;
    // queue[1] = root->right;
    // queue[2] = root->left;
    size_t i = 0;
    auto pnt_standin = bst.root;
    std::cout << "ino mikham check konam" << bst.root->value << std::endl;
    queue.push_back(pnt_standin);
    size_t flag { 0 };
    while (flag == 0) {

        visited.push_back(queue[0]->value);
        os << queue[0];
        os << "             ";
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
            os << 0;
            os << "            ";
        }
        if (pnt_standin->right != nullptr) {
            os << "right:";
            queue.push_back(pnt_standin->right);
            os << pnt_standin->right;
            os << "             " << std::endl;
        } else {
            os << "right:";
            os << 0;
            os << "            " << std::endl;
        }
        if (queue.size() == 0) {
            os << "*******************************************************************************************" << std::endl;
            std::cout << "ino mikham check konam" << bst.root->value << std::endl;
            return os;
            flag = 1;
        }
        i++;
        // std::cout << "miyad ta inja**" << std::endl;
        pnt_standin = (queue[0]);
        os << std::endl;
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
}
BST::Node** BST::find_node(int value)
{
    std::vector<Node*> queue;
    std::vector<int> visited;
    size_t i = 0;
    auto pnt_standin = root;
    queue.push_back(pnt_standin);
    std::cout << "root q" << queue[0] << std::endl;
    while (true) {
        visited.push_back(queue[0]->value);
        if (queue[0]->value == value) {
            std::cout << "oomad too if?" << value << queue[0]->value << queue[0]->left->value << queue[0]->right->value << std::endl;
            auto pnt_ret = new Node*(queue[0]);
            return pnt_ret;
        }

        // std::cout << queue[0] << std::endl;
        // std::cout << queue[0]->value << std::endl;
        queue.erase(queue.begin());
        // std::cout << "visited:" << visited[i] << std::endl;

        if (pnt_standin->left != nullptr) {
            queue.push_back(pnt_standin->left);
        }
        if (pnt_standin->right != nullptr) {
            queue.push_back(pnt_standin->right);
        }
        if (queue.size() == 0) {
            auto pnt_ret = nullptr;
            return pnt_ret;
        }
        i++;

        pnt_standin = queue[0];
        // std::cout << queue[i] << std::endl;
        // std::cout << queue[i]->value << std::endl;
        // std::cout << visited[i] << std::endl;
    }
}
BST::Node** BST::find_parrent(int value)
{
    // bebin mitooni ino ba find node bezani?
    std::vector<Node*> queue;
    std::vector<int> visited;
    Node** pnt_to_parent;
    auto pnt_standin = root;
    queue.push_back(pnt_standin);
    if (root->value == value) {
        // is root ;doesnt have parents
        return 0;
    }
    while (true) {
        // visited.push_back(queue[0]->value);
        std::cout << "in queue[0] kharabe?" << std::endl;
        std::cout << queue[0] << std::endl;
        std::cout << queue[0]->value << std::endl;
        pnt_to_parent = new Node*(queue[0]);
        std::cout << (*pnt_to_parent)->value << std::endl;
        queue.erase(queue.begin());
        // std::cout << "visited:" << visited[i] << std::endl;
        if (pnt_standin->left != nullptr) {
            queue.push_back(pnt_standin->left);
            if (pnt_standin->left->value == value) {
                pnt_to_parent = new Node*(pnt_standin);
            }
        }
        if (pnt_standin->right != nullptr) {
            std::cout << "check the right kid" << pnt_standin->right << std::endl;
            queue.push_back(pnt_standin->right);
            std::cout << "khers khers hezar khers" << pnt_standin->right->value << value << std::endl;
            if (pnt_standin->right->value == value) {
                std::cout << "vaghti tooye 10 im bayad biyad inja" << pnt_standin->right << std::endl;
                pnt_to_parent = new Node*(pnt_standin);
                return pnt_to_parent;
            }
        }
        if (queue.size() == 0) {
            // doesnt have parents
            return 0;
        }
        // i++;
        pnt_standin = queue[0];
    }
}
BST::Node** BST::find_successor(int value)
{
    // bebin mitooni ino ba find node bezani?
    BST::Node** pointer_got_from_findnode { this->find_node(value) };
    while (true) {
        Node* node_one_left;
        node_one_left = (*pointer_got_from_findnode)->left;
        std::cout << "one left " << node_one_left->value;
        Node* node_one_left_right;
        node_one_left_right = node_one_left;
        while (true) {
            node_one_left_right = node_one_left_right->right;
            std::cout << node_one_left_right->value << std::endl;
            if (node_one_left_right->right == nullptr) {
                Node** ret_pnt;
                ret_pnt = new Node*(node_one_left_right);
                return ret_pnt;
            }
        }
    }

    // std::vector<Node*> queue;
    // std::vector<int> visited;
    // size_t i = 0;
    // auto pnt_standin = root;
    // queue.push_back(pnt_standin);
    // while (true) {
    //     visited.push_back(queue[0]->value);
    //     if (queue[0]->value == value) {
    //         Node* node_one_left;
    //         node_one_left = queue[0]->left;
    //         Node* node_one_left_right;
    //         node_one_left_right = node_one_left;
    //         while (true) {
    //             node_one_left_right = node_one_left_right->right;
    //             std::cout << node_one_left_right->value << std::endl;
    //             if (node_one_left_right->right == nullptr) {
    //                 std::cout << "ehtemalan in nullptr khare";
    //                 Node** ret_pnt;
    //                 ret_pnt = new Node*(node_one_left_right);
    //                 return ret_pnt;
    //             }
    //         }
    //     }

    //     queue.erase(queue.begin());
    //     if (pnt_standin->left != nullptr) {
    //         queue.push_back(pnt_standin->left);
    //     }
    //     if (pnt_standin->right != nullptr) {
    //         queue.push_back(pnt_standin->right);
    //     }
    //     if (queue.size() == 0) {
    //         auto pnt_ret = nullptr;
    //         return pnt_ret;
    //     }
    //     i++;
    //     pnt_standin = queue[0];
    // }
}
BST::~BST()
{
    std::vector<Node*> nodes;
    bfs([&nodes](BST::Node*& node) { nodes.push_back(node); });
    for (auto& node : nodes)
        delete node;
    std::cout << "we did destruct" << std::endl;
}
BST::BST(const BST& bst)
    : root { bst.root }
{
    std::cout << "copy constructor of bst" << std::endl;
    std::cout << root->value << std::endl;
}
// aslan motmarn nistam ino
BST& BST::operator=(const BST& bst)
{
    std::cout << "operator =" << std::endl;

    delete root;
    // root? new chi?
    root = bst.root;
    return *this;
}
// bool BST::delete_node(int value)
// {
//     BST::Node** pointer_got_from_findnode { this->find_node(value) };
//     // has two childs
//     if (pnt_standin->right != nullptr && pnt_standin->left != nullptr) {
//         /* code */
//     }
//     // has one child
//     if (pnt_standin->right != nullptr || pnt_standin->left != nullptr) {
//         /* code */
//     }
//     if (pnt_standin->right == nullptr && pnt_standin->left == nullptr) {
//         /* code */
//     }
// }