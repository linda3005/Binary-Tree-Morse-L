#include <stdbool.h>

#define RIGHTSON 'r'
#define LEFTSON 'l'

typedef struct Node *addressNode;
typedef struct Node
{
    char info;
    addressNode parent;
    addressNode leftSon, rightSon;
} Node;

typedef struct Tree
{
    addressNode root;
} Tree;

/*
    Constructor
*/
Tree createTree();
addressNode createNode(char info);


//    Mutators

//'r' for rightSon
//'l' for leftSon
void insertSon(addressNode node, char pos, char info);

bool isNodeEmpty(addressNode node);
bool isNodeLeaf(addressNode node);
bool isNodeRoot(addressNode node);


//    Accessor

void printNode(addressNode node);
void preorder(addressNode node);
void inorder(addressNode node);
addressNode searchData(addressNode node, char info);



//    Others
int Theight(addressNode root);
void buildTmorse(Tree *tree);
char *createCode(Tree Tmorse, char cod);
void CodeStr(Tree Tmorse, char *cods);
char convertMorse(Tree Tmorse, char *morse);
void conMorseStrg(Tree Tmorse, char *m);
void convertFile(Tree Tmorse, char *read, char *write);
void MainMenu();
