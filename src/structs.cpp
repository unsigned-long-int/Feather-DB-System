#include<iostream>
#include<vector>
#include<fstream>

template <typename T>
struct BTreeNode{
    bool isLeaf;
    std::vector<T> keys;
    std::vector<BTreeNode*> children;

    BTreeNode(bool leaf=true) : isLeaf(leaf){}
};

template <typename T>
class BTree{
    private:
	BTreeNode<T>* root;
	std::fstream file;

    public:
	BTree(const std::string& filename="default_btree.dat") : root(nullptr) {
	    file.open(filename, std::ios::in | std::ios::out | std::ios:binary | std::ios::trunc);
	}

	void insert(const T& key){
	    if (root==nullptr){
		root = new BTreeNode<T>(true);
		root->keys.push_back(key);
	    } else{
		if (root->keys.size() == 2){
		BTreeNode<T>* newRoot = new BTreeNode<T>(false);
		newRoot->children.push_back(root);
		splitChild(newRoot, 0);
		root=newRoot;
		}
	    insertNonFull(root, key);
	    }
	}

	bool search(const T& key) const{
	    return searchKey(root, key);
	}

	void print() const{
	    inOrderTraversal(root);
	    std::cout << std::endl;
	}

	void saveToFile(){
	    file.seekp(0);
	    writeToFile(root);
	}

	void loadFromFile(){
	    file.seekg(0);
	    root = readFromFile();
	}
	
	~BTree(){
	    file.close();
	}

    private:
	bool searchKey(BTreeNode<T>* node, const T& key) const{
	    if (node==nullptr){
		return false;
	    }

	    size_t i=0;

	    while(i<node->keys.size() && key>node->keys[i]){
		++i;
	    }

	    if (i<node->keys.size() && key==node->keys[i]){
		return true;
	    }

	    if (node->isLeaf){
		return false;
	    }

	    return searchKey(node->children[i], key);
	}

	void isOrderTraversal(BTreeNode<T>* node) const{
	    if (node!=nullptr){
		size_t i;
		for (i=0; i<node->keys.size();++i){
		    inOrderTraversal(node->children[i]);
		    std::cout << node->keys[i] << " ";
		}

		inOrderTraversal(node->children[i]);
	    }
	}

	void insertNonFull(BTreeNode<T>* node, const T& key){
	    size_t i=node->keys.size();

	    if (node->isLeaf){
		while (i>0 && key<node->keys[i-1]){
		    --i;
		}

		node->keys.insert(node->keys.begin() + i, key);
	    } else {
		while (i>0 && key<node->keys[i-1]){
		    --i;
		}

		if (node->children[i]->keys.size()==2){
		    splitChild(node, i);

		    if (key>node->keys[i]){
			++i;
		    }
		}

		insertNonFull(node->children[i], key);
	    }
	}

	void splitChild(BTreeNode<T>* parentNode, size_t childIndex){
	    BTreeNode<T>* childNode=parentNode->children[childIndex];
	    BTreeNode<T>* newChild=new BTreeNode<T>(childNode->isLeaf);

	    parentNode->keys.insert(parentNode->keys.begin() + childIndex, childNode->keys[1]);

	    newChild->keys.push_back(childNode->keys[2]);

	    childNode->keys.resize(1);

	    if (!childNode->isLeaf){
		newChild->children.push_back(childNode->children[2]);
		childNode->children.resize(2);
	    }

	    parentNode->children.insert(parentNode->children.begin() + childIndex + 1, newChild);
	}

	void writeToFile(BTreeNode<T>* node){
	    if (node!=nullptr){
		file.write(reinterpret_cast<char*>(node), sizeof(BTreeNode<T>));

		for (size_t i=0; i<node->children.size(); ++i){
		    writeToFile(node->children[i]);
		}
	    }
	}

	BTreeNode<T>* readFromFile(){
	    BTreeNode<T>* node = new BTreeNode<T>();
	    file.read(reinterpret_cast<char*>(node), sizeof(BTreeNode<T>));

	    for (size_t i=0; i<node->children.size(); ++i){
		node->children[i]=readFromFile();
	    }

	    return node;
	}
};

