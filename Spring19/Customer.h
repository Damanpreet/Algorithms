
struct Customer{
    int ID;
    int time;
};

#define TYPE struct Customer

struct Deque{
    struct Customer * data;
    int capacity;
    int size;
    int start; 
};

void dequeInit(struct Deque *d, int initcap);
int dequeSize(struct  Deque *d);
void dequeAddFront(struct Deque *d, TYPE value);
void dequeAddBack(struct Deque *d, TYPE value);
void dequeDelFront(struct Deque *d);
void dequeDelBack(struct Deque *d);
int dequeFront(struct Deque *d);
int dequeBack(struct Deque *d);
void dequeFree(struct  Deque *d);
void dequePrint(struct Deque *d);
