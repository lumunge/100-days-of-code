#include<iostream>
#include<vector>
#include<map>
using namespace std;

/* PROBLEM STATEMENT:
 * Given a description of a rooted tree, compute and output its height,
 * 
 * Sample:
 * Input: 5
 *        4, -1, 4, 1, 1 --> | 0 | 1 | 2 | 3 | 4 |  -> -1 = root(1)
 *                             4   -1  4   1   1    -> 1  = has two children(3, 4) 
 *                                                  -> 4  = has two children(0, 2) 
 *              Tree:
 *                1
 *              /   \
 *             3     4
 *                  /  \
 *                 0    2 ==> Height = 3
 */


class Node{
public:
    int data;
    vector<int> children;

    Node(int data){
        this->data = data;
    }
    
    void addChild(int child){
        children.push_back(child);
    }
    int getSize(){
        return children.size();
    }
};

class Tree{
    private:
        int numNodes;
        Node *root;
        vector<int> parents;
        map<int, Node*> nodes;

        void constructTree(){
            for(int i = 0; i < this->numNodes; i++){ //Creating an array[numNodes]
                this->nodes[i] = new Node(i);
            }
            for(int i = 0; i < this->numNodes; i++){//Reading each parent index
                int parent = this->parents[i];
                if(parent == -1)
                    this->root = this->nodes[i];
                else
                    this->nodes[parent]->addChild(i);
            }
        }

        int getMaxHeight(Node *node){
            int height = 0;
            if(node == NULL) return 0; // No node in tree
            if(node->getSize() == 0) return 1; //Root node only
            for(int i = 0; i < node->getSize(); i++){
                int childHeight = this->getMaxHeight(this->nodes[node->children[i]]);
                height = max(height, childHeight);
            }
            return height+1;//Add root node
        }

    public:
        ~Tree(){
            for(const auto & node : this->nodes){
                delete node.second;
            }
        }

        void read(){
            cin >> this->numNodes;
            this->parents.resize(this->numNodes);
            for(int i = 0; i < this->numNodes; i++)
                cin >> this->parents[i];
        }

        int getHeight(){
            this->constructTree();
            return this->getMaxHeight(this->root);
        }
};

int main(){
    Tree * tree = new Tree();
    tree->read();
    cout << tree->getHeight() << endl;
    return 0;
}
