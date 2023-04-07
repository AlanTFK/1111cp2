#ifndef POTATO_H
#define POTATO_H

#include<stdio.h>

struct PotatoBall {
    struct PotatoProducer* producer;
    int weight;
    int magical;
    char effect[32];
    void (*print)(struct PotatoBall** potatoBall);
    void (*dtor)(struct PotatoBall** potatoBall);
};

struct Potato {
    struct PotatoProducer* producer;
    int weight;
    int magical;
    char effect[32];
    void (*print)(struct Potato** potato);
    struct PotatoBall* (*fry)(struct Potato** potato);
};

struct PotatoProducer {
    char name[20];
    int magical;
    struct Potato* (*produce)(struct PotatoProducer* producer);
};

void init_potato_producer(struct PotatoProducer* producer, const char* name, int magical);

struct Potato* potato_producer_produce(struct PotatoProducer* producer);
void potato_print(struct Potato** potato);
struct PotatoBall* potato_fry(struct Potato** potato);
void potato_ball_print(struct PotatoBall** potatoBall);
void potato_ball_dtor(struct PotatoBall** potatoBall);
#endif
