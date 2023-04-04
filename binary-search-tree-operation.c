#include <stdio.h>

typedef struct _treenode
{
    int key;
    struct _treenode *left, *right;
} treenode;

treenode n1 = { 1, NULL, NULL };
treenode n2 = { 4, &n1, NULL };
treenode n3 = { 16, NULL, NULL };
treenode n4 = { 25, NULL, NULL };
treenode n5 = { 20, &n3, &n4 };
treenode n6 = { 15, &n2, &n5 };
treenode *root = &n6;

//탐색연산
treenode *search(treenode *node, int key) {
    if (node==NULL) {
        return NULL;
    }
    if (key==node->key) {
        return node;
    } else if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

//삽입연산
treenode *new_node(int item)  {
	treenode *temp = (treenode *)malloc(sizeof(treenode));
	temp->key = item;
	temp->left = NULL; 
    temp->right = NULL;
	return temp;
}

treenode *insert_node(treenode *node, int key){
	// 트리가 공백이면 새로운 노드를 반환한다. 
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다. 
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다. 
	return node;
}

//삭제연산
treenode *min_value_node(treenode *node)
{
	treenode *current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

treenode *delete_node(treenode *root, int key)  { // key 노드 삭제 후 루트 반환
	if (root == NULL) return root;
	if (key < root->key) 			              // 키가 루트보다 작으면 왼쪽 서브 트리에 있음
		root->left = delete_node(root->left, key);
	else if (key > root->key) 		              // 키가 루트보다 크면 오른쪽 서브 트리에 있음
		root->right = delete_node(root->right, key);
	else {				                          // 키가 루트와 같으면 이 노드를 삭제함
		if (root->left == NULL) {	              // (1) or (2)
			treenode *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {           // (1) or (2)
			treenode *temp = root->left;
			free(root);
			return temp;
		}
		treenode *temp = min_value_node(root->right); 	   // (3)
		root->key = temp->key; 				               // 직후 키 복사
		root->right = delete_node(root->right, temp->key); // 직후 노드 삭제
	}
	return root;
}

int main()
{
	treenode* root = NULL;
	treenode* tmp = NULL;
	root = insert_node(root, 11);
	root = insert_node(root, 6);
	root = insert_node(root, 8);
	root = insert_node(root, 19);
	root = insert_node(root, 4);
	root = insert_node(root, 10);
	root = insert_node(root, 5);
	root = insert_node(root, 17);
	root = insert_node(root, 43);
	root = insert_node(root, 49);
	root = insert_node(root, 31);
	delete_node(root, 11);

    return 0;
}