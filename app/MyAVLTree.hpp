/**
 * @author Allyson Yamasaki, Jullia Bautista
 * Date Created: Nov 11, 2019
 *
 * Project 3
 *
 */


#ifndef __PROJ_THREE_AVL_HPP
#define __PROJ_THREE_AVL_HPP

#include "runtimeexcept.hpp"
#include <string>
#include <vector>
//#include <jmorecfg.h>

class ElementNotFoundException : public RuntimeException {
public:
    ElementNotFoundException(const std::string &err) : RuntimeException(err) {}
};

template<typename Key, typename Value>
struct Node {
    Value data;
    Key InOrderID;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;

    /**
     * Made by Josh
     */
    bool isLeaf() {
        return (left == nullptr and right == nullptr);
    }
    /**
     * Made by Josh
     */
    int getNumberOfNodes() {
        int numLeftNodes = 0;
        int numRightNodes = 0;

        if (left != nullptr) {
            numLeftNodes = left->getNumberOfNodes();
        }
        if (right != nullptr) {
            numRightNodes = right->getNumberOfNodes();
        }

        return 1 + numLeftNodes + numRightNodes; // Add 1 to count self node
    }
    /**
     * Made by Josh
     */
    int getHeight() {
        return getHeight(this);
    }
    /**
     * Made by Josh
     */
    int getHeight(Node<Key, Value> *currNode) {
        int height = 0;

        if (currNode != nullptr) {
            height = 1 + std::max(getHeight(currNode->left), getHeight(currNode->right));
        }
        return height;
    }
};

template<typename Key, typename Value>
class MyAVLTree {
private:
    // fill in private member data here
    // If you need to declare private functions, do so here too.
    Node<Key, Value> *root = nullptr;

public:
    MyAVLTree();

    // In general, a copy constructor and assignment operator
    // are good things to have.
    // For ICS 46, Fall 2019, I am not requiring these.
    //	MyAVLTree(const MyAVLTree & st);
    //	MyAVLTree & operator=(const MyAVLTree & st);


    // The destructor is, however, required.
    ~MyAVLTree() {
        // TODO
    }

    // size() returns the number of distinct keys in the tree.
    size_t size() const noexcept;

    // isEmpty() returns true if and only if the tree has no values in it.
    bool isEmpty() const noexcept;

    // contains() returns true if and only if there
    //  is a (key, value) pair in the tree
    //	that has the given key as its key.
    bool contains(const Key &k) const;

    // find returns the value associated with the given key
    // If !contains(k), this will throw an ElementNotFoundException
    // There needs to be a version for const and non-const MyAVLTrees.
    Value &find(const Key &k);

    const Value &find(const Key &k) const;

    // Inserts the given key-value pair into
    // the tree and performs the AVL re-balance
    // operation, as described in lecture.
    // If the key already exists in the tree,
    // you may do as you please (no test cases in
    // the grading script will deal with this situation)
    void insert(const Key &k, const Value &v);

    // in general, a "remove" function would be here
    // It's a little trickier with an AVL tree
    // and I am not requiring it for Fall 2019's ICS 46.
    // You should still read about the remove operation
    // in your textbook.

    // The following three functions all return
    // the set of keys in the tree as a standard vector.
    // Each returns them in a different order.
    std::vector<Key> inOrder() const;

    std::vector<Key> preOrder() const;

    std::vector<Key> postOrder() const;

    /**
     * Added by Josh
     */
    void addEntry(Node<Key, Value> *currNode, const Key &k, const Value &v);

    /**
     * Added by Josh
     */
     void checkBalance(Node<Key, Value> *currNode);
};


template<typename Key, typename Value>
MyAVLTree<Key, Value>::MyAVLTree() {

}

template<typename Key, typename Value>
size_t MyAVLTree<Key, Value>::size() const noexcept {
    return helperFuncSize(root);
}

template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::isEmpty() const noexcept {
    return (root == nullptr);
}


template<typename Key, typename Value>
bool MyAVLTree<Key, Value>::contains(const Key &k) const {
    Node<Key, Value> *tmpPtr = root;
    while (tmpPtr != nullptr) {
        if (tmpPtr->InOrderID == k) {
            return true;
        } else if (k > root->InOrderID) {
            tmpPtr = tmpPtr->right;
        } else {
            tmpPtr = tmpPtr->left;
        }
    }
    return false;

}


template<typename Key, typename Value>
Value &MyAVLTree<Key, Value>::find(const Key &k) {
    try {
        if (!MyAVLTree<Key, Value>::contains(k)) {
            throw ElementNotFoundException("This element cannot be found.");
        }
    }
    catch (RuntimeException err) {
        std::cout << err.getMessage() << '\n';
    }
    Node<Key, Value> *tmpPtr = root;
    while (tmpPtr != nullptr) {
        if (tmpPtr->InOrderID == k) {
            return tmpPtr->data;
        } else if (k > root->InOrderID) {
            tmpPtr = tmpPtr->right;
        } else {
            tmpPtr = tmpPtr->left;
        }
    }
    return tmpPtr->data;
}


template<typename Key, typename Value>
const Value &MyAVLTree<Key, Value>::find(const Key &k) const {
    try {
        if (!MyAVLTree<Key, Value>::contains(k)) {
            throw ElementNotFoundException("This element cannot be found.");
        }
    }
    catch (RuntimeException err) {
        std::cout << err.getMessage() << '\n';
    }
    Node<Key, Value> *tmpPtr = root;
    while (tmpPtr != nullptr) {
        if (tmpPtr->InOrderID == k) {
            return tmpPtr->data;
        } else if (k > root->InOrderID) {
            tmpPtr = tmpPtr->right;
        } else {
            tmpPtr = tmpPtr->left;
        }
    }
}

//template<typename Key, typename Value>
//void MyAVLTree<Key, Value>::insert(const Key &k, const Value &v) {
//    Node<Key, Value> *newNode = new Node<Key, Value>;
//    newNode->InOrderID = k;
//    newNode->data = v;
//    Node<Key, Value> *temp = root;
//    Node<Key, Value> *tempParent = nullptr;
//    while (temp != nullptr) {
//        tempParent = temp;
//        if (k < temp->InOrderID) {
//            temp = temp->left;
//        } else if (k > temp->InOrderID) {
//            temp = temp->right;
//        }
//    }
//    if (tempParent == nullptr) {
//        root = newNode;
//    } else if (k < tempParent->InOrderID) {
//        tempParent->left = newNode;
//    } else if (k > tempParent->InOrderID) {
//        tempParent->right = newNode;
//    }
//
//    newNode->parent = tempParent;
//
//    Node<Key, Value> *revTemp = tempParent;
//    if (tempParent != nullptr) {
//        while (revTemp != root) {
//            rotate(revTemp);
//            revTemp = revTemp->parent;
//        }
//    }
//}

/**
 * Made by Josh
 */
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::insert(const Key &k, const Value &v) {
    if (isEmpty()) {
        root = new Node<Key, Value>;
        root->InOrderID = k;
        root->data = v;
    } else {
        addEntry(root, k, v);
    }
}

/**
 * Made by Josh
 */
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::addEntry(Node<Key, Value> *currNode, const Key &k, const Value &v) {

    // If new value matches object at root of tree/subtree, replace root with new data
    if (k == currNode->data) {
        currNode->data = v;
    }
        // if new value is smaller than at root
    else if ((k - currNode->InOrderID) < 0) {
        // If the root has a leftChild, recursively use the addEntry method until newEntry is correctly added.
        if (currNode->left != nullptr) {
            addEntry(currNode->left, k, v);
        }
            // If the root does not have a leftChild, set the root's leftChild with newEntry as its data.
        else {
            currNode->left = new Node<Key, Value>;
            currNode->left->InOrderID = k;
            currNode->left->data = v;
            currNode->left->parent = currNode;
            checkBalance(currNode->parent);
        }
    }
        // newEntry is comparatively greater than the data at the root node and should ne added in the right subtree.
    else {

        // If the root has a rightChild, recursively use the addEntry method until newEntry is correctly added.
        if (currNode->right != nullptr) {
            addEntry(currNode->right, k, v);
        }
            // If the root does not have a rightChild, set the root's rightChild with newEntry as its data.
        else {
            currNode->right = new Node<Key, Value>;
            currNode->right->InOrderID = k;
            currNode->right->data = v;
            currNode->right->parent = currNode;
            checkBalance(currNode->parent);
        }
    }
}

/**
 * Made by Josh
 */
template<typename Key, typename Value>
void MyAVLTree<Key, Value>::checkBalance(Node<Key, Value> *currNode) {

    while (currNode != root) {
        int balanceFactor = currNode->right->getHeight() - currNode->left->getHeight();

        // Left Heavy
        if (balanceFactor < -1) {
            Node<Key, Value> *leftChild = currNode->left;

            // Left-Left Case: Perform Right Rotation
            if (leftChild->left != nullptr) {
                Node<Key, Value> *currParent = currNode->parent;
                currParent->left = leftChild;
                leftChild->right = currNode;

                currNode->left = nullptr;
                currNode->right = nullptr;
            }
            // Left-Right Case: Perform Left Rotation then Right Rotation
            else {
                // Left Rotation
                currNode->left = leftChild->right;
                currNode->left->left = leftChild;
                leftChild->left = nullptr;
                leftChild->right = nullptr;

                // Right Rotation
                Node<Key, Value> *currParent = currNode->parent;
                currParent->left = currNode->left;
                currParent->left->right = currNode;

                currNode->left = nullptr;
                currNode->right = nullptr;
            }
        }
        // Right Heavy
        else if (balanceFactor > 1) {
            Node<Key, Value> *rightChild = currNode->right;

            // Right-Right Case: Perform Left Rotation
            if (rightChild->right != nullptr) {

            }
            // Right-Left Case: Perform Right Rotation then Left Rotation
            else {

            }
        }
        // Move upward toward root
        else {
            currNode = currNode->parent;
        }
    }
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::inOrder() const {
    return helperInOrder(root);
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::preOrder() const {
    return helperPreOrder(root);
}


template<typename Key, typename Value>
std::vector<Key> MyAVLTree<Key, Value>::postOrder() const {
    return helperPostOrder(root);
}

template<typename Key, typename Value>
size_t helperFuncSize(Node<Key, Value> *temp) {
    if (temp == nullptr) {
        return 0;
    }
    return 1 + helperFuncSize(temp->left) + helperFuncSize(temp->right);

}

template<typename Key, typename Value>
size_t heightOfParent(Node<Key, Value> *temp) {
    if (temp == nullptr) {
        return 0;
    }
    return 1 + std::max(heightOfParent(temp->left), heightOfParent(temp->right));
}

//size_t maximum(size_t x, size_t y){
//    if (x > y){
//        return x;
//    }
//    return y;
//}
template<typename Key, typename Value>
size_t balanceFactor(Node<Key, Value> *parent) {
    if (parent == nullptr) {
        return 0;
    } else if (parent->left == nullptr and parent->right == nullptr) {
        return 0;
    }
    return heightOfParent(parent->left) - heightOfParent(parent->right);
}

template<typename Key, typename Value>
void rotate(Node<Key, Value> *parent) {
    // tree is LEFT heavy
    if (balanceFactor(parent) > 1 and (parent != nullptr)) {
        // tree's LEFT subtree is RIGHT heavy
        if (balanceFactor(parent->left) < -1 and (parent->left != nullptr)) {
            leftRightRotation(parent);
        } else {
            rightRightRotation(parent);
        }
    }
        // tree is RIGHT heavy
    else if (balanceFactor(parent) < -1 and (parent != nullptr)) {
        // tree's RIGHT subtree is LEFT heavy
        if (balanceFactor(parent->right) > 1 and (parent->right != nullptr)) {
            rightLeftRotation(parent);
        } else {
            leftLeftRotation(parent);
        }
    }
}

template<typename Key, typename Value>
void rightRightRotation(Node<Key, Value> *parent) {
    Node<Key, Value> *tmpPtr = parent->parent;
    Node<Key, Value> *rightChild = parent->right;
    rightChild->left = parent;
    tmpPtr->right = rightChild;
    parent->left = nullptr;
    parent->right = nullptr;
}

template<typename Key, typename Value>
void leftLeftRotation(Node<Key, Value> *parent) {
    Node<Key, Value> *tmpPtr = parent->parent;
    Node<Key, Value> *leftChild = parent->left;
    leftChild->right = parent;
    tmpPtr->left = leftChild;
    parent->left = nullptr;
    parent->right = nullptr;
}

template<typename Key, typename Value>
void rightLeftRotation(Node<Key, Value> *parent) {
    Node<Key, Value> *tmpPtr = parent;
    Node<Key, Value> *leftChild = parent->left;
    tmpPtr->left = leftChild->right;
    tmpPtr->left->left = leftChild;
    leftChild->right = nullptr;

    leftLeftRotation(parent);
}

template<typename Key, typename Value>
void leftRightRotation(Node<Key, Value> *parent) {
    Node<Key, Value> *tmpPtr = parent;
    Node<Key, Value> *rightChild = parent->right;
    tmpPtr->right = rightChild->left;
    tmpPtr->right->right = rightChild;
    rightChild->left = nullptr;

    rightRightRotation(parent);
}

template<typename Key, typename Value>
std::vector<Key> helperInOrder(Node<Key, Value> *n) {
    std::vector<Key> result;
    if (n == nullptr) {
        return result;
    } else {

        std::vector<Key> x;
        if (n->left != nullptr) {
            x = helperInOrder(n->left);
            result.insert(result.end(), x.begin(), x.end());
        }

        result.push_back(n->InOrderID);

        if (n->right != nullptr) {
            x = helperInOrder(n->right);
            result.insert(result.end(), x.begin(), x.end());
        }
    }
    return result;
}

template<typename Key, typename Value>
std::vector<Key> helperPreOrder(Node<Key, Value> *n) {
    std::vector<Key> result;
    if (n == nullptr) {
        return result;
    } else {
        result.push_back(n->InOrderID);
        std::vector<Key> x;
        if (n->left != nullptr) {
            x = helperPreOrder(n->left);
            result.insert(result.end(), x.begin(), x.end());
        }
        if (n->right != nullptr) {
            x = helperPreOrder(n->right);
            result.insert(result.end(), x.begin(), x.end());
        }
    }
    return result;
}

template<typename Key, typename Value>
std::vector<Key> helperPostOrder(Node<Key, Value> *n) {
    std::vector<Key> result;
    if (n == nullptr) {
        return result;
    } else {
        std::vector<Key> x;
        if (n->left != nullptr) {
            x = helperPostOrder(n->left);
            result.insert(result.end(), x.begin(), x.end());
        }
        if (n->right != nullptr) {
            x = helperPostOrder(n->right);
            result.insert(result.end(), x.begin(), x.end());
        }
        result.push_back(n->InOrderID);
    }
    return result;
}


#endif