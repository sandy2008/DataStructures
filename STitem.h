typedef int Key;
typedef struct { Key key; char info[10]; } STitem;
#define key(A) (A.key)
#define info(A) (A.info)
#define less(A, B) (A < B)
#define eq(A, B) (A == B)
STitem NULLitem;
Key ITEMrand(void);
int ITEMscan(Key *);
void ITEMshow(STitem);
