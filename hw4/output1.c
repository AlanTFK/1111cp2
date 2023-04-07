#include<stdio.h>
#include<stdlib.h>
#include"potato.h"

int main() {
  int N = 0;
  scanf_s("%d", &N);
  srand(N);
  struct PotatoProducer Tom;
  init_potato_producer(&Tom, "Tom", 0);
  struct Potato* p = Tom.produce(&Tom);
  struct Potato* p3 = Tom.produce(&Tom);
  p3->print(&p3);
  struct PotatoBall* pb = p->fry(&p);
  pb->print(&pb);
}
