template <typename T>

class BTnode {

    public:
    T data;
    BTnode* left;
    BTnode* right;

    BTnode(T data) {

        this->data = data;
        left = NULL;
        right = NULL;
    }

    
};

