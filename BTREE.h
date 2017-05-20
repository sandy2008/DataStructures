#include "LIST.h"

typedef struct BTnode* BTlink;

struct BTnode{
   char item;
   BTlink l;
   BTlink r;
};  //Define BTlink


BTlink newNode(char);
BTlink BTcons(char, BTlink, BTlink);
BTlink BTsubtree(BTlink, link);
void BTprint(BTlink);
