typedef char ItemType;

class VectorStack {
    public:
        VectorStack(ItemType pHolder[], int capacity);
        ~VectorStack();

        ItemType pop();
        void push(ItemType item);

        bool isFull() const;
        bool isEmpty() const;
    
        void print() const;
    private:
        int length;
        int holderCapacity;
        ItemType *pHolder;
};