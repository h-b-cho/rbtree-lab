#include <stdio.h>
#include <stdlib.h>

typedef struct _Node 
{
    int data;
    struct _Node *left, *right;
} Node;

Node* create_node(Node *node, int data)
{
    node = (Node*)malloc(sizeof(Node));
    (*node).data = data;
    (*node).left = NULL;
    (*node).right = NULL;
    return node;
}

Node* insert_node(Node *root, int data)
{
    if(root==NULL){
        return create_node(root, data);
    }
    else if(data < (*root).data){
        (*root).left = insert_node((*root).left, data);
    }
    else if(data > (*root).data){
        (*root).right = insert_node((*root).right, data);
    }
    return root;
}

Node* search_node(Node *root, int data)
{
	while (root!=NULL) {
        if(root->data==data){
            return root;
        }
        else if(data < root->data){
            return search_node(root->left, data);
        }
        else if(data > root->data){
            return search_node(root->right, data);
        }
        return root;
    }
    return NULL; //fail
}

Node* delete_node(Node *root, int data)
{
    if(root==NULL){
        return root;
    }
    else if(data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data){
        root->right = delete_node(root->right, data);
    } else {
        if(root->left==NULL){
            Node *temp = root->right;
			free(root);
			return temp;
        }
        else if(root->right==NULL){
            Node *temp = root->left;
			free(root);
			return temp;
        }
        Node *temp = root->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = insert_node(root, 7);
    root = insert_node(root, 14);
    root = insert_node(root, 21);
    root = insert_node(root, 28);
    root = insert_node(root, 35);
    root = insert_node(root, 9);
    root = insert_node(root, 19);
    root = insert_node(root, 29);
    root = insert_node(root, 39);
    root = insert_node(root, 49);
    root = insert_node(root, 1);
    root = insert_node(root, 11);
    root = insert_node(root, 22);
    root = insert_node(root, 33);
    root = insert_node(root, 44);
    root = insert_node(root, 55);

    printf("삭제연산 테스트 용 인풋을 입력해보자. :");
    int inp;
    scanf("%d", &inp);

    if (search_node(root, inp)!=NULL) {
        printf("트리에서 %d를 찾았습니다. \n", inp);
    } else {
        printf("트리에 %d가 없습니다. \n", inp);
    }

    delete_node(root, inp);

    if (search_node(root, inp)!=NULL) {
        printf("트리에서 %d를 찾았습니다. \n", inp);
    } else {
        printf("트리에 %d가 없습니다. \n", inp);
    }

    return 0;
}