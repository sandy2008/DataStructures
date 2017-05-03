#include "Item.h"

typedef struct node *link;
struct node { Item item; link next; };
link LISTempty(void);
Item LISThead(link);
link LISTtail(link);
link LISTcons(Item,link);
int LISTlength(link);
void LISTprint(link);
