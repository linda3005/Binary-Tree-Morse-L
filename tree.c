#include "tree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


Tree createTree(){
    Tree T;
    T.root = NULL;

    return T;
}

addressNode createNode(char info){
    addressNode nd = (addressNode)malloc(sizeof(Node));

    nd->info = info;
    nd->parent = NULL;
    nd->leftSon = NULL;
    nd->rightSon = NULL;

    return nd;
}


void insertSon(addressNode node, char pos, char info){
    if(node==NULL){
        return;
    }

    addressNode x=createNode(info);
    x->parent=node;

    if(pos=='l'){
        node->leftSon=x;
    }
    else if(pos=='r'){
        node->rightSon=x;
    }
}



void inorder(addressNode node){
    if(node!=NULL){
        inorder(node->leftSon);
        printNode(node);
        inorder(node->rightSon);
    }
}

void preorder(addressNode node){
	if(node!=NULL){
		preorder(node->leftSon);
		preorder(node->rightSon);
		printNode(node);
	}
}

void printNode(addressNode node){
    printf((node->info==0 ? "(NULL)" : "%c "), node->info);
}

addressNode searchData(addressNode node, char info){
    if(node->info==toupper(info)){
        return node;
    }

    if(node==NULL){
        return node;
    }

    addressNode result=searchData(node->leftSon, info);

    if(result!=NULL){
        return result;
    }

    result=searchData(node->rightSon, info);
    return result;
}


bool isNodeEmpty(addressNode node){
    return node->info==0;
}

bool isNodeLeaf(addressNode node){
    if(node==NULL){
        return false;
    }
    return(node->rightSon==NULL&&node->leftSon==NULL);
}

bool isNodeRoot(addressNode node){
    return node->parent==NULL;
}


int treeHeight(addressNode root){
    if(root==NULL){
        return 0;
    }

    int leftSon = treeHeight(root->leftSon);
    int rightSon = treeHeight(root->rightSon);

    return leftSon > rightSon ? (leftSon + 1) : (rightSon + 1);
}

void createMorseTree(Tree *tree){
    //  . = left Son 
    //  - = right Son 

    tree->root = createNode(0);

    insertSon(tree->root, LEFTSON, 'E');
    insertSon(tree->root, RIGHTSON, 'T');

  //level 2
    insertSon(tree->root->leftSon, LEFTSON, 'I');
    insertSon(tree->root->leftSon, RIGHTSON, 'A');
    insertSon(tree->root->rightSon, LEFTSON, 'N');
    insertSon(tree->root->rightSon, RIGHTSON, 'M');

    //level 3
    insertSon(tree->root->leftSon->leftSon, LEFTSON, 'S');
    insertSon(tree->root->leftSon->leftSon, RIGHTSON, 'U');
    insertSon(tree->root->leftSon->rightSon, LEFTSON, 'R');
    insertSon(tree->root->leftSon->rightSon, RIGHTSON, 'W');
    insertSon(tree->root->rightSon->leftSon, LEFTSON, 'D');
    insertSon(tree->root->rightSon->leftSon, RIGHTSON, 'K');
    insertSon(tree->root->rightSon->rightSon, LEFTSON, 'G');
    insertSon(tree->root->rightSon->rightSon, RIGHTSON, 'O');

    //level 4
    insertSon(tree->root->leftSon->leftSon->leftSon, LEFTSON, 'H');
    insertSon(tree->root->leftSon->leftSon->leftSon, RIGHTSON, 'V');
    insertSon(tree->root->leftSon->leftSon->rightSon, LEFTSON, 'F');
    insertSon(tree->root->leftSon->leftSon->rightSon, RIGHTSON, 0);
    insertSon(tree->root->leftSon->rightSon->leftSon, LEFTSON, 'L');
    insertSon(tree->root->leftSon->rightSon->leftSon, RIGHTSON, 0);
    insertSon(tree->root->leftSon->rightSon->rightSon, LEFTSON, 'P');
    insertSon(tree->root->leftSon->rightSon->rightSon, RIGHTSON, 'J');
    insertSon(tree->root->rightSon->leftSon->leftSon, LEFTSON, 'B');
    insertSon(tree->root->rightSon->leftSon->leftSon, RIGHTSON, 'X');
    insertSon(tree->root->rightSon->rightSon->leftSon, LEFTSON, 'Z');
    insertSon(tree->root->rightSon->rightSon->leftSon, RIGHTSON, 'Q');
    insertSon(tree->root->rightSon->leftSon->rightSon, LEFTSON, 'C');
    insertSon(tree->root->rightSon->leftSon->rightSon, RIGHTSON, 'Y');
    insertSon(tree->root->rightSon->rightSon->rightSon, LEFTSON, '0');
    insertSon(tree->root->rightSon->rightSon->rightSon, RIGHTSON, 0);

    //level 5
    insertSon(tree->root->leftSon->leftSon->leftSon->leftSon, LEFTSON, '5');
    insertSon(tree->root->leftSon->leftSon->leftSon->leftSon, RIGHTSON, '4');
    insertSon(tree->root->leftSon->leftSon->leftSon->rightSon, RIGHTSON, '3');
    insertSon(tree->root->leftSon->leftSon->rightSon->rightSon, RIGHTSON, '2');
    insertSon(tree->root->leftSon->rightSon->leftSon->leftSon, RIGHTSON, 0);
    insertSon(tree->root->leftSon->rightSon->rightSon->rightSon, RIGHTSON, '1');
    insertSon(tree->root->rightSon->leftSon->leftSon->leftSon, LEFTSON, '6');
    insertSon(tree->root->rightSon->rightSon->leftSon->leftSon, LEFTSON, '7');
    insertSon(tree->root->rightSon->rightSon->rightSon->leftSon, LEFTSON, '8');
    insertSon(tree->root->rightSon->rightSon->rightSon->rightSon, LEFTSON, '9');
    
    //level 6
    insertSon(tree->root->leftSon->rightSon->leftSon->leftSon->rightSon, LEFTSON, ' ');
}

char *createCodeChar(Tree morseTree, char cod){
    addressNode searchResult = searchData(morseTree.root, cod);
    addressNode x=NULL;
    int height=treeHeight(morseTree.root);
    char *strge=(char *)malloc(sizeof(char) * height);
    int j=0;

    while (searchResult!=NULL){
        x=searchResult->parent;
        if(x==NULL){
            break;
        }

        if(searchResult==x->rightSon){
            strge[j]='-';
        }
        else{
            strge[j]='.';
        }

        searchResult = x;
        j++;
    }
    height= j - 1;
    char *returned=(char *)malloc(sizeof(char) * j);
    for (j=height; j>=0; j--){
        returned[height-j]=strge[j];
    }
    return returned;
}

void createCodeString(Tree morseTree, char *cods){
    int length = strlen(cods);
    int i;

    printf("%s : ", cods);
    for (i=0; i<length; i++){
        printf("%s ", createCodeChar(morseTree, cods[i]));
    }
    printf("\nd");
}

char convertMorse(Tree morseTree, char *morse){
    addressNode y=morseTree.root;
    int length=strlen(morse);
    int i;

    for (i=0; i<length; i++){
        if (morse[i]=='.'){
            y=y->leftSon;
        }
        else if (morse[i]== '-'){
            y=y->rightSon;
        }
    }

    return y->info;
}

void convertMorseString(Tree morseTree, char *morses){
    char fill[6];
    int length = strlen(morses);
    int i, j = 0;

    for(i=0; i<length; i++){
        if(morses[i]== ' '){
            printf("%c", convertMorse(morseTree, fill));
            j=0;

            memset(fill, 0, sizeof(fill));
        }
        else if(morses[i]!= ' '){
            fill[j]=morses[i];
            j++;

            if(i==length-1){
                printf("%c", convertMorse(morseTree, fill));
            }
        }
    }
}

void convertFileToMorse(Tree morseTree, char *read, char *write){
    FILE *fp_read, *fp_write;
    char line[100];
    int i, x;

    fp_read=fopen(read, "r");
    fp_write=fopen(write, "w");
    if (fp_read==NULL || fp_write==NULL){
        return;
    }
    while(fgets(line, 100, fp_read)!= NULL){
        x=strlen(line);

        for(i=0; i<x; i++){
            fprintf(fp_write, "%s ", createCodeChar(morseTree, line[i]));
        }

        fprintf(fp_write, "\nd");
    }

    fclose(fp_read);
    fclose(fp_write);
}
