#include "potato.h"
#include <string.h>
#include <stdlib.h>

void init_potato_producer(struct PotatoProducer* producer, const char* name, int magical) {
    strcpy(producer->name, name);
    producer->magical = magical;
    producer->produce = potato_producer_produce;
}

struct Potato* potato_producer_produce(struct PotatoProducer* producer) {
    struct Potato* tmp = malloc(sizeof(struct Potato));
    tmp->producer = producer;
    tmp->weight = (rand()%1000) + 1;
    if(producer->magical!=0) {
        tmp->magical = producer->magical;
        strcpy(tmp->effect, "slowness");
    }
    else tmp->magical = 0;
    tmp->print = potato_print;
    tmp->fry = potato_fry;
    return tmp;
}

void potato_print(struct Potato** potato) {
    if((*potato)->magical == 0)
        printf("Potato:\n  producer: %s\n  weight: %d\n", (*potato)->producer->name, (*potato)->weight);
    else printf("Magical Potato:\n  producer: %s\n  weight: %d\n  effect: slowness\n", (*potato)->producer->name, (*potato)->weight);
}

struct PotatoBall* potato_fry(struct Potato** potato) {
    struct PotatoBall* tmp = malloc(sizeof(struct PotatoBall));
    tmp->producer = (*potato)->producer;
    tmp->weight = (*potato)->weight;
    if((*potato)->magical!=0) {
        tmp->magical = (*potato)->magical;
        strcpy(tmp->effect, "slowness");
    }
    else tmp->magical = 0;
    tmp->print = potato_ball_print;
    tmp->dtor = potato_ball_dtor;
    free(*potato);
    return tmp;
}

void potato_ball_print(struct PotatoBall** potatoBall) {
     if((*potatoBall)->magical == 0)
        printf("Potato Ball:\n  producer: %s\n  weight: %d\n", (*potatoBall)->producer->name, (*potatoBall)->weight);
    else printf("Magical Potato Ball:\n  producer: %s\n  weight: %d\n  effect: slowness\n", (*potatoBall)->producer->name, (*potatoBall)->weight);
   
}

void potato_ball_dtor(struct PotatoBall** potatoBall){
    free(*potatoBall);
}
