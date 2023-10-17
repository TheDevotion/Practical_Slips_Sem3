#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *root = NULL;

void create() {
  int num_elements;
  printf("How many numbers do you want to add to the binary search tree? ");
  scanf("%d", &num_elements);

  for (int i = 0; i < num_elements; i++) {
    int data;
    printf("Enter number %d: ", i + 1);
    scanf("%d", &data);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root == NULL) {
      root = new_node;
    } else {
      struct node *temp = root;
      while (1) {
        if (new_node->data < temp->data) {
          if (temp->left == NULL) {
            temp->left = new_node;
            break;
          } else {
            temp = temp->left;
          }
        } else {
          if (temp->right == NULL) {
            temp->right = new_node;
            break;
          } else {
            temp = temp->right;
          }
        }
      }
    }
  }
}


void pre_order(struct node *node) {
  if (node != NULL) {
    printf("%d ", node->data);
    pre_order(node->left);
    pre_order(node->right);
  }
}

void post_order(struct node *node) {
  if (node != NULL) {
    post_order(node->left);
    post_order(node->right);
    printf("%d ", node->data);
  }
}

int main() {
  int choice;
  char ans;
  
  do {
    printf("\nMenu:\n");
    printf("1. Create binary search tree\n");
    printf("2. Traverse pre-order\n");
    printf("3. Traverse post-order\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        create();
        break;
      case 2:
        printf("Pre-order traversal: ");
        pre_order(root);
        printf("\n");
        break;
      case 3:
        printf("Post-order traversal: ");
        post_order(root);
        printf("\n");
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice\n");
        break;
    }

    printf("Do you want to continue ?(Y/N)\n");
    scanf("%s", & ans);

  }while(ans == 'y' || ans == 'Y');
  return 0;
}
