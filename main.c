// Author : Linda Damayanti (191524017) & Muhammad Hargi Muttaqin (191524027)
// Binary Tree Morse Code
#include "tree.h"
#include <stdio.h>

int main(int argc, char const *argv[]){
    Tree morse = createTree();
    char temp[100], read[100], write[100];
    buildTmorse(&morse);

    printf("Hasil Traversal Preorder :\n");
    preorder(morse.root);
    printf("\nHasil Traversal Inorder :\n");
    inorder(morse.root);
	MainMenu();
    return 0;
}
