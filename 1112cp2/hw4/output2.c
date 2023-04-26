#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your .h file
#include "potato.h"

int main() {
  int N;
  scanf_s("%d", &N);
  srand(N);

  struct PotatoProducer P;
  init_potato_producer(&P, "NCCU student", 0);

  struct Potato* p = P.produce(&P);
  p->print(&p);

  struct PotatoBall* pb = p->fry(&p);
  pb->print(&pb);

  strcpy(P.name, "Kobe");
  pb->print(&pb);

  pb->dtor(&pb);
}
