#include <bits/stdc++.h>

using namespace std;

int sizeQueue;
vector<int> values;
vector<int> sortedValues;

struct Node {
    int value;
    struct Node *next;
};

typedef struct {
    struct Node *head;
    struct Node *tail;
} Queue;

void initialize(Queue *q) {
    sizeQueue = 0;
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue *q, int v) {
    sizeQueue++;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return;
    newNode->value = v;
    newNode->next = NULL;
    if (q->head == NULL) q->head = newNode;
    if (q->tail != NULL) q->tail->next = newNode;
    q->tail = newNode;
}

bool isEmpty(Queue q) {
    return q.head == NULL && q.tail == NULL;
}

void dequeue(Queue *q) {
    sizeQueue--;
    struct Node *temp;
    if (q->head == NULL) return;
    temp = q->head;
    q->head = temp->next;
    if (q->head == NULL) q->tail = NULL;
    free(temp);
}

int front(Queue q) {
    return q.head->value;
}

int main() {
    int num, limit;
    while (cin >> num >> limit) {
        if (!num && !limit) break;
        if (limit > 34) cout << "Let me try!\n";
        else {
            Queue q;
            initialize(&q);
            enqueue(&q, 1);
            int counter = 2;
            while (front(q) != limit && front(q) > 0 && front(q) <= num) {
                int current = front(q);
                dequeue(&q);
                if (current < limit) {
                    if (current + (2 * counter - 1) <= num) current += 2 * counter - 1;
                    else current -= 2 * counter - 1;
                    enqueue(&q, current);
                } else {
                    if (current - (2 * counter - 1) > 0) current -= 2 * counter - 1;
                    else current += 2 * counter - 1;
                    enqueue(&q, current);
                }
                counter++;
            }
            if (!isEmpty(q) && front(q) == limit) cout << "Let me try!\n";
            else cout << "Don't make fun of me!\n";
        }
    }
    return 0;
}

//Augusto C Fagundes