#include "LIST.h"

typedef struct BTnode* BTlink;

struct BTnode{
   char label;
   BTlink l;
   BTlink r;
};  //Define BTlink


BTlink newNode(char);
BTlink BTcons(char, BTlink, BTlink);
BTlink BTsubtree(BTlink, link);
void BTprint(BTlink);
int BTsize(BTlink);
int BTisLeaf(BTlink, link);
int BTleaves(BTlink);
int BTedges(BTlink);
char BTlabel(BTlink, link);
