#include <stdio.h>
#include <stdbool.h>
#define LEFTSON 'l'
#define RIGHTSON 'r'


typedef struct Node *addressNode;
typedef struct Node{
    char info;
    addressNode parent;
    addressNode leftSon, rightSon;
} Node;

typedef struct Tree{
    addressNode root;
} Tree;
//===============================================================================//
//Constructor

Tree createTree();
addressNode createNode(char info);

//Mutators
// 'R' for RIGHT, and 'L' for LEFT
void insertSon(addressNode node, char pos, char info);


// Accessor
void preorder(addressNode node);
void inorder(addressNode node);
void printNode(addressNode node);
addressNode searchData(addressNode node, char info);


//Validator
bool isNodeEmpty(addressNode node);
bool isNodeLeaf(addressNode node);
bool isNodeRoot(addressNode node);

//Others

int Theight(addressNode root);
void createMorseTree(Tree *tree);
char *createCodeChar(Tree Tmorse, char cod);
void CodeStr(Tree Tmorse, char *cods);
char convertMorse(Tree Tmorse, char *morse);
void convertMorseString(Tree Tmorse, char *m);
void convertFile(Tree Tmorse, char *src, char *dest);
