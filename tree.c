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

//define
addressNode createNode(char info){
    addressNode nd = (addressNode)malloc(sizeof(Node));

    nd->info = info;
    nd->parent = NULL;
    nd->rightSon = NULL;
    nd->leftSon = NULL;

    return nd;
}


void insertSon(addressNode node, char pos, char info){
    if(node==NULL){
        return;
    }
    addressNode temp=createNode(info);
    temp->parent=node;

    if(pos == 'r'){
        node->rightSon=temp;
    }
    else if(pos == 'l'){
        node->leftSon=temp;
    }
}

bool isNodeEmpty(addressNode node){
    return node->info == 0;
}

bool isNodeLeaf(addressNode node){
    if(node==NULL){
        return false;
    }

    return(node->rightSon==NULL && node->leftSon==NULL);
}

bool isNodeRoot(addressNode node){
    return node->parent==NULL;
}


void printNode(addressNode node){
    printf((node->info==0 ? "(NULL)" : "%c "), node->info);
}

void preorder(addressNode node){
	if(node!=NULL){
		preorder(node->leftSon);
		preorder(node->rightSon);
		printNode(node);
	}
}

void inorder(addressNode node){
    if(node!=NULL){
        inorder(node->leftSon);
        printNode(node);
        inorder(node->rightSon);
    }
}

addressNode searchData(addressNode node, char info){
    if(node==NULL){
        return node;
    }

    if(node->info==toupper(info)){
        return node;
    }

    addressNode result=searchData(node->leftSon, info);

    if(result!=NULL){
        return result;
    }

    result=searchData(node->rightSon, info);
    return result;
}


int Theight(addressNode root){
    if(root==NULL){
        return 0;
    }

    int leftSon=Theight(root->leftSon);
    int rightSon=Theight(root->rightSon);

    return leftSon>rightSon ? (leftSon+1) : (rightSon+1);
}

void buildTmorse(Tree *tree)
{
  
    tree->root=createNode(0);

    // level 1
    insertSon(tree->root, LEFTSON, 'E');
    insertSon(tree->root, RIGHTSON, 'T');

    // level 2
    insertSon(tree->root->leftSon, LEFTSON, 'I');
    insertSon(tree->root->leftSon, RIGHTSON, 'A');
    insertSon(tree->root->rightSon, LEFTSON, 'N');
    insertSon(tree->root->rightSon, RIGHTSON, 'M');

    // level 3
    insertSon(tree->root->leftSon->leftSon, LEFTSON, 'S');
    insertSon(tree->root->leftSon->leftSon, RIGHTSON, 'U');
    insertSon(tree->root->leftSon->rightSon, LEFTSON, 'R');
    insertSon(tree->root->leftSon->rightSon, RIGHTSON, 'W');
    insertSon(tree->root->rightSon->leftSon, LEFTSON, 'D');
    insertSon(tree->root->rightSon->leftSon, RIGHTSON, 'K');
    insertSon(tree->root->rightSon->rightSon, LEFTSON, 'G');
    insertSon(tree->root->rightSon->rightSon, RIGHTSON, 'O');

    // level 4
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

    // level 5
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
    // level 6
    insertSon(tree->root->leftSon->rightSon->leftSon->leftSon->rightSon, LEFTSON, ' ');
}

char *createCode(Tree Tmorse, char cod){
    addressNode searchResult=searchData(Tmorse.root, cod);
    addressNode temp=NULL;
    int height=Theight(Tmorse.root);
    char *strge=(char *)malloc(sizeof(char) * height);
    int i=0;

    while(searchResult!= NULL){
        temp=searchResult->parent;

        if(temp==NULL){
            break;
        }

        if(searchResult==temp->leftSon){
            strge[i]= '.';
        }
        else{
            strge[i]= '-';
        }

        searchResult=temp;
        i++;
    }

    height= i-1;
    char *returned= (char *)malloc(sizeof(char) * i);
    for(i=height; i>=0; i--){
        returned[height-i] = strge[i];
    }
    return returned;
}

void CodeStr(Tree Tmorse, char *cods){
    int length = strlen(cods);
    int i;

    printf("%s : ", cods);
    for(i=0; i<length; i++){
        printf("%s ", createCode(Tmorse, cods[i]));
    }
    printf("\n");
}

char convertMorse(Tree Tmorse, char *morse){
    addressNode temp=Tmorse.root;
    int length=strlen(morse);
    int i;

    for(i=0; i<length; i++){
        if(morse[i]== '.'){
            temp = temp->leftSon;
        }
        else if(morse[i]== '-'){
            temp=temp->rightSon;
        }
    }

    return temp->info;
}

void conMorseStrg(Tree Tmorse, char *m){
    char temp[6];
    int length = strlen(m);
    int i,j = 0;

    for(i=0;i<length; i++){
        if(m[i] == ' '){
            printf("%c", convertMorse(Tmorse, temp));
            j=0;

            memset(temp, 0, sizeof(temp));
        }
        else if(m[i]!= ' '){
            temp[j] = m[i];
            j++;

            if(i == length - 1){
                printf("%c", convertMorse(Tmorse, temp));
            }
        }
    }
}

void convertFile(Tree Tmorse, char *read, char *write){
    FILE *fp_read, *fp_write;
    char line[100];
    int i, length;

    fp_read = fopen(read, "r");
    fp_write = fopen(write, "w");
    if(fp_read == NULL || fp_write == NULL){
        return;
    }

    while(fgets(line, 100, fp_read)!= NULL){
        length = strlen(line);

        for(i=0; i<length; i++){
            fprintf(fp_write, "%s ", createCode(Tmorse, line[i]));
        }

        fprintf(fp_write, "\n ");
    }

    fclose(fp_read);
    fclose(fp_write);
}

void MainMenu(){
	Tree morse = createTree();
    char temp[100], read[100], write[100];
    buildTmorse(&morse);
	
	printf("\n");
	printf("\n==============================================================\n");
    printf("\n1. Merubah Teks Menjadi Morse");
    printf("\n2. Merubah Morse Menjadi Teks");
	printf("\n3. File Teks Menjadi Morse");
	printf("\n4. Keluar Program");
	printf("\nSilahkan Pilih Menu: ");

    int choice;
    scanf("%d", &choice);
	
	
    switch (choice){
    case 1:
        printf("Masukan Teks (Maksimal 100 Character) : ");
        scanf(" %[^\n]", temp);

        CodeStr(morse, temp);
        MainMenu();

    case 2:
        printf("Masukan Sandi Morse (Maksimal 100 Character, setiap huruf di pisahkan spasi) : ");
        scanf(" %[^\n]", temp);

        conMorseStrg(morse, temp);
        MainMenu();

    case 3:
        printf("Masukan Nama Dari File Input: ");
        scanf("%s", read);

        printf("Masukan Nama File Penyimpanan Output: ");
        scanf("%s", write);

        convertFile(morse, read, write);
        MainMenu();
	
	case 4:
		exit(0);
	
    default:
        break;
    }
}

