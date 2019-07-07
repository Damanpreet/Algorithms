#define TYPE int

struct Deque{
    TYPE *data;
    TYPE start;
    TYPE size;
    TYPE capacity;
};

void dequeInit(struct Deque *d, TYPE initcap);
TYPE dequeSize(struct  Deque *d);
void dequeAddFront(struct Deque *d, TYPE value);
void dequeAddBack(struct Deque *d, TYPE value);
void dequeDelFront(struct Deque *d);
void dequeDelBack(struct Deque *d);
TYPE dequeFront(struct Deque *d);
TYPE dequeBack(struct Deque *d);
void dequeFree(struct  Deque *d);
void dequePrint(struct Deque *d);
