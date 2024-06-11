#include <iostream>
#include<Windows.h>
using namespace std;
// ��������� - ����� ������
struct tnode
{
    int field;           // ���� ������
    struct tnode* left;  // ��� �����������
    struct tnode* right; // ����� �����������
};
// ���� ����� ������ (� �������� ����)
void treeprint(tnode* tree)
{
    if (tree != NULL)
    {      //���� �� ����������� ������ �����
        treeprint(tree->left);  //���������� ������� ��������� ����� ��������
        cout << tree->field << " "; //³������� ����� ������
        treeprint(tree->right); //���������� ������� ��������� ������� ��������
    }
}
// ���������� ����� � ������
struct tnode* addnode(int x, tnode* tree)
{
    if (tree == NULL)     // ���� ������ ����, �� �������� �����
    {
        tree = new tnode; //������ �� �����
        tree->field = x;   //���� �����
        tree->left = NULL;
        tree->right = NULL; //������������ ���������� ��������
    }
    else
        if (x < tree->field)
        {
            //���� ������� x ����� ��������, ����� ����
            tree->left = addnode(x, tree->left);
            //���������� ��������� �������
        }
        else
        { //������ ����� ������
            tree->right = addnode(x, tree->right); //���������� ���������� �������
        }
    return(tree);
}
//��������� ���'�� ������
void freemem(tnode* tree)
{
    if (tree != NULL)    // ���� ������ �� �����
    {
        freemem(tree->left);   // ���������� �������� ��� ����
        freemem(tree->right);  // ���������� �������� ����� ����
        delete tree;           // �������� �����
    }
}
// ����
int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct tnode* root = 0;    // ��������� ��������� ������
    int a;
    // � ���� ������� 8 ����� ������
    for (int i = 0; i < 8; i++)
    {
        cout << "Enter the node " << i + 1 << ": ";
        cin >> a;
        root = addnode(a, root); // ��������� �������� ������� �� �����
    }
    treeprint(root);    // �������� ��������  ������, ������� ������������ �����
    freemem(root);      // ��������� ������� ���'���
    cin.get();  cin.get();
    return 0;
}