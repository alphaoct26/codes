\#include <iostream>
#include <vector>

class BTreeNode {
public:
    vector<int> keys;
    vector<BTreeNode*> children;
    bool isLeaf;
    
    BTreeNode(bool leaf) {
        isLeaf = leaf;
    }
};

class BTree {
private:
    BTreeNode* root;
    int t; // Minimum degree
    
public:
    BTree(int degree) {
        root = nullptr;
        t = degree;
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == (2 * t - 1)) {
                BTreeNode* newRoot = new BTreeNode(false);
                newRoot->children.push_back(root);
                splitChild(newRoot, 0);
                root = newRoot;
            }
            insertNonFull(root, key);
        }
    }

    void insertNonFull(BTreeNode* node, int key) {
        int i = node->keys.size() - 1;
        if (node->isLeaf) {
            node->keys.push_back(0); 
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
        } else {
            while (i >= 0 && key < node->keys[i])
                i--;
            i++;
            if (node->children[i]->keys.size() == (2 * t - 1)) {
                splitChild(node, i);
                if (key > node->keys[i])
                    i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

  void splitChild(BTreeNode* parent, int childIndex) {

        BTreeNode* child = parent->children[childIndex];

        BTreeNode* newChild = new BTreeNode(child->isLeaf);

        parent->keys.insert(parent->keys.begin() + childIndex, child->keys[t - 1]);


        parent->children.insert(parent->children.begin() + childIndex + 1, newChild);

        newChild->keys.assign(child->keys.begin() + t, child->keys.end());

        child->keys.erase(child->keys.begin() + t, child->keys.end());

        if (!child->isLeaf) {
            newChild->children.assign(child->children.begin() + t, child->children.end());
            child->children.erase(child->children.begin() + t, child->children.end());
        }
        
    }

    void print() {
        if (root != nullptr) {
            printNode(root);
        }
    }

    void printNode(BTreeNode* node) {
        for (int i = 0; i < node->keys.size(); i++) {
            std::cout << node->keys[i] << " ";
        }
        std::cout << std::endl;

        if (!node->isLeaf) {
            for (int i = 0; i < node->children.size(); i++) {
                printNode(node->children[i]);
            }
        }
    }
};

int main()
{
    int degree;
    cout << "Enter the minimum degree of the B-tree: ";
    cin >> degree;

    BTree bTree(degree);

    int key;
    cout << "Enter keys (enter -1 to stop): ";
    while (true) {
        cin >> key;
        if (key == -1)
            break;
        bTree.insert(key);
    }

    cout << "B-Tree Structure:" << endl;
    bTree.print();

    return 0;
}