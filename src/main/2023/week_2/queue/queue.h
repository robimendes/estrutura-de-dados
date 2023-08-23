typedef char ItemType;

class Queue {
    public:
        Queue(ItemType *pHolder, int capacity);
        ~Queue();

        void enqueue(ItemType item);
        ItemType dequeue();
        bool isFull() const;
        bool isEmpty() const;

    private:
        ItemType *pHolder;
        int lenght;
        int capacity;
        int first;
        int last;
        int count;
        void emptyQueue() const;
};