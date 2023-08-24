typedef char ItemType;

struct NodeType {
    ItemType item;
    NodeType *next;
    NodeType *previous;
};

class Stack {
    public:
        Stack();
        ~Stack();

        ItemType pop();
        void push(ItemType item);

        bool isFull() const;
        bool isEmpty() const;
    
        void print() const;
    private:
        NodeType *firstNode;
        NodeType *lastNode;
};