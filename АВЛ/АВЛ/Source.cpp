#include"Header.h"
void main()
{
    //Побудова дерева дана в наведений нище малюнок
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /*
             30
            / \
           20  40
          / \   \
         10 25   50 */
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";

    preOrder(root);//обхід побудованого дерева
    cout << endl;
    cout << "----------------------------------" << endl;
    Node* root1 = NULL;

    root1 = insert(root1, 9);
    root1 = insert(root1, 5);
    root1 = insert(root1, 10);
    root1 = insert(root1, 0);
    root1 = insert(root1, 6);
    root1 = insert(root1, 11);
    root1 = insert(root1, -1);
    root1 = insert(root1, 1);
    root1 = insert(root1, 2);
    /* The constructed AVL Tree would be
    *
         9          //0      //1
        / \
        1 10        //1      //2
       / \  \
      0  5   11     //2      //3
    /   / \
  -1   2   6 */

    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root1);

    root1 = deleteNode(root1, 10);

    /* The AVL Tree after deletion of 10
         1
        / \
        0  9
        / / \
      -1 5  11
        / \
        2 6 */
    cout << "\nPreorder traversal after"
        << " deletion of 10 \n";
    preOrder(root1);
}