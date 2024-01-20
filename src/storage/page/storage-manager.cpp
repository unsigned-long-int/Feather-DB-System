
#include<fstream>
#include<iostream>

template <typename T>

class BTreePersistenceHandler{
    private:
	BTreeNode<T>* root;
	std::fstream file;
    public:
	BTreePersistenceHandler(BTreeNode<T>* rootNode, const std::string& filename="default_btree.dat") : root(rootNode){
	    if (!root){
		throw std::invalid_argument("Error: root cannot be nullptr");
	    }
	    file.open(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);

	    if (!file.is_open()){
		throw std::runtime_error("Error: unable to open the file");
	    }
	}

	void saveToFile(){
	    file.seekp(0);
	    writeToFile(root);
	}

	void loadFromFile(){
	    file.seekg(0);
	    root=readFromFile();
	}

	~BTreePersistenceHandler(){
	    file.close();
	}


    private:
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
	    for (size_t i=0;i<node->children.size();++i){
		    node->children[i]=readFromFile();
	    }

	    return node;
	}
};


