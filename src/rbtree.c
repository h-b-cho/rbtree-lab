#include "rbtree.h"
#include <stdio.h>
#include <stdlib.h>

rbtree *new_rbtree(void) {  // TODO: initialize struct if needed
  rbtree *p = (rbtree *)calloc(1, sizeof(rbtree));
  p->nil = (node_t *)calloc(1, sizeof(node_t));
  p->nil->color = RBTREE_BLACK;
  p->root = p->nil;
  return p;
}

void delete_rbtree(rbtree *t) {  // TODO: reclaim the tree nodes's memory

  free(t);
}

void left_rotate(rbtree *t, node_t *x) {
  node_t *y = x->right;

  x->right = y->left;
  if (y->left != t->nil) {
    y->left->parent = x;
  }

  y->parent = x->parent;

  if (x->parent==t->nil) {
    t->root = y;
  } else if (x==x->parent->left) {
    x->parent->left = y;
  } else {
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}

void right_rotate(rbtree *t, node_t *x) {
  node_t *y = x->left;

  x->left = y->right;
  if (y->right != t->nil) {
    y->right->parent = x;
  }

  y->parent = x->parent;

  if (x->parent==t->nil) {
    t->root = y;
  } else if (x==x->parent->right) {
    x->parent->right = y;
  } else {
    x->parent->left = y;
  }

  y->right = x;
  x->parent = y;
}

void rbtree_insert_fixup(rbtree *t, node_t *z) {
  while (z->parent->color==RBTREE_RED) {    // "새롭게 삽입한 노드(z)의 parent가 red라면". 아니게 될 때까지 반복.
    
    // "z의 부모가 z의 조부모의 왼쪽 자식이라면".
    if (z->parent == z->parent->parent->left) {
      node_t *uncle = z->parent->parent->right; // "z의 조부모의 오른쪽 자식이 uncle일 것이다."

      if (uncle->color == RBTREE_RED) {
				z->parent->color = RBTREE_BLACK;
        uncle->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        z = z->parent->parent;
			} else {
        if (z==z->parent->right) {
          z = z->parent;
          left_rotate(t, z);
        }
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        right_rotate(t, z->parent->parent);
      }
    
    // "z의 부모가 z의 조부모의 오른쪽 자식이라면".
    } else {                                
      node_t *uncle = z->parent->parent->left; // "z의 조부모의 왼쪽 자식이 uncle일 것이다."
      
      if (uncle->color == RBTREE_RED) {
				z->parent->color = RBTREE_BLACK;
				uncle->color = RBTREE_BLACK;
				z->parent->parent->color = RBTREE_RED;
				z = z->parent->parent;
			} else {
        if (z==z->parent->left) {
          z = z->parent;
          right_rotate(t, z);
        }
        z->parent->color = RBTREE_BLACK;
        z->parent->parent->color = RBTREE_RED;
        left_rotate(t, z->parent->parent);
      }
    }
  }

  t->root->color = RBTREE_BLACK;
}

node_t *rbtree_insert(rbtree *t, const key_t key) {  // TODO: implement insert
  node_t *x = t->root; // 현재 노드. 함수가 시작되는 시점에선 트리의 루트이다.
  node_t *y = t->nil;  // 현재 노드의 부모 포인터 변수. 함수가 시작되는 시점에선 NULL 즉, nil이다.

  // 트리의 끝까지 내려가는 탐색.
  while (x != t->nil) // "x에게 부모가 없다면".
  {
    y = x;
    if (x->key > key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  // while 문을 다 돌면 말인즉 x는 nil을 가르키게 되었다는 뜻.
  // 이제 parent인 y에 새로운 노드인 z를 삽입하면 된다.

  // 새 노드 z 생성.
  node_t *z = (node_t *)calloc(1, sizeof(node_t));
  z->key = key;
  z->parent = y;

  if (y==t->nil) { //"부모가 nil일 때". while문을 1번도 돌지 않았다면 y, 즉 parent는 nil일 것이다.
    t->root = z;
  } else if (z->key < y->key) {
    y->left = z;
  } else {
    y->right = z;
  }

  z->left = t->nil;
  z->right = t->nil;
  z->color = RBTREE_RED;
  rbtree_insert_fixup(t, z);

  return t->root;
}

node_t *rbtree_find(const rbtree *t, const key_t key) {  // TODO: implement find

  return t->root;
}

node_t *rbtree_min(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

node_t *rbtree_max(const rbtree *t) {
  // TODO: implement find
  return t->root;
}

int rbtree_erase(rbtree *t, node_t *z) {  // TODO: implement erase
  node_t *y = z;

  color_t y_original_color = y->color;
  node_t *x;

  if (z->left==t->nil) {
    x = z->right;
    rbtree_transplant(t, z, z->right);
  } else if (z->right==t->nil) {
    x = z->left;
    rbtree_transplant(t, z, z->left);
  } else {
    
  }

  return 0;
}

int rbtree_to_array(const rbtree *t, key_t *arr, const size_t n) {  // TODO: implement to_array 

  return 0;
}
