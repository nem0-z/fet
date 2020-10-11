#include <iostream>
#include <vector>

/*
   + /home/zlatan
     + dir1
        - file1
        - file2
        - file3
        - file4
     + dir2
        - file1
        - file2
*/

struct Node
{
    std::string value;
    std::vector<Node *> children;

    Node(std::string v) : value{v} {}
    ~Node()
    {
        for (Node *node : children)
            delete node;
    }
};

void printTree(Node *node, int level = 0)
{
    std::cout << std::string(level * 2, ' ');
    std::cout << ((node->children).empty() ? "-" : "+");
    std::cout << node->value << std::endl;
    for (Node *item : node->children)
        printTree(item, level + 1);
}

int main(int argc, char const *argv[])
{
    Node *root = new Node("/home/zlatan");
    Node *dir1 = new Node("dir1");
    Node *dir2 = new Node("dir2");

    dir1->children.push_back(new Node("file1"));
    dir1->children.push_back(new Node("file2"));
    dir1->children.push_back(new Node("file3"));
    dir1->children.push_back(new Node("file4"));

    dir2->children.push_back(new Node("file1"));
    dir2->children.push_back(new Node("file2"));

    root->children.push_back(dir1);
    root->children.push_back(dir2);

    printTree(root);

    delete root;
    return 0;
}
