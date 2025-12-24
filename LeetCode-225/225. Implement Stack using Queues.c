#include <stdlib.h>
#include <stdbool.h>

#define MAX 10000

typedef struct {
    int q1[MAX];
    int q2[MAX];
    int f1, r1;
    int f2, r2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->f1 = obj->r1 = 0;
    obj->f2 = obj->r2 = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {

    obj->q2[obj->r2++] = x;

    while (obj->f1 < obj->r1) {
        obj->q2[obj->r2++] = obj->q1[obj->f1++];
    }

    obj->f1 = 0;
    obj->r1 = obj->r2;
    for (int i = 0; i < obj->r2; i++) {
        obj->q1[i] = obj->q2[i];
    }

    obj->f2 = obj->r2 = 0;
}

int myStackPop(MyStack* obj) {
    return obj->q1[obj->f1++];
}

int myStackTop(MyStack* obj) {
    return obj->q1[obj->f1];
}

bool myStackEmpty(MyStack* obj) {
    return obj->f1 == obj->r1;
}

void myStackFree(MyStack* obj) {
    free(obj);
}
