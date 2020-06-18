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

/*
    Mutators
*/
// pos -> 'r' for rightSon, and 'l' for leftSon
void insertSon(addressNode node, char pos, char info);

/*
    Accessor
*/
void printNode(addressNode node);
void inorder(addressNode node);
addressNode searchData(addressNode node, char info);

/*
    Validator
*/
bool isNodeEmpty(addressNode node);
bool isNodeLeaf(addressNode node);
bool isNodeRoot(addressNode node);

/*
    Others
*/
int Theight(addressNode root);
void createMorseTree(Tree *tree);
char *createCode(Tree Tmorse, char cod);
void CodeStr(Tree Tmorse, char *cods);
char convertMorse(Tree Tmorse, char *morse);
void conMorseStrg(Tree Tmorse, char *m);
void convertFile(Tree Tmorse, char *src, char *dest);
