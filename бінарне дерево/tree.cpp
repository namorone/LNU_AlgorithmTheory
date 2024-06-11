#include <iostream>
#include<Windows.h>
using namespace std;
// Структура - вузол дерева
struct tnode
{
    int field;           // поле данних
    struct tnode* left;  // ліве відгалуження
    struct tnode* right; // праве відгалуженнч
};
// Вивід вузлів дерева (в індиксній формі)
void treeprint(tnode* tree)
{
    if (tree != NULL)
    {      //Доки не зустрінеться пустий вузол
        treeprint(tree->left);  //Рекурсивна функція виведення лівого піддерева
        cout << tree->field << " "; //Відобрпжує корінь дерева
        treeprint(tree->right); //Рекурсивна функція виведення правого піддерева
    }
}
// Добавлення вузлів в дерево
struct tnode* addnode(int x, tnode* tree)
{
    if (tree == NULL)     // якщо дерева немає, то формируєм корінь
    {
        tree = new tnode; //память під вузел
        tree->field = x;   //поле даних
        tree->left = NULL;
        tree->right = NULL; //відгалужження ініціалізуємо пустотою
    }
    else
        if (x < tree->field)
        {
            //якщо елемент x менше корінного, ідемо вліво
            tree->left = addnode(x, tree->left);
            //Рекурсивно добавляєм елемент
        }
        else
        { //інакше йдемо вправо
            tree->right = addnode(x, tree->right); //Рекурсивно добавляємо элемент
        }
    return(tree);
}
//звільнення пам'яті дерева
void freemem(tnode* tree)
{
    if (tree != NULL)    // якщо дерево не пусте
    {
        freemem(tree->left);   // рекурсивно видаляєм ліву гілку
        freemem(tree->right);  // рекурсивно видаляєм праву гілку
        delete tree;           // видаляєм корінь
    }
}
// Тест
int main()
{    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    struct tnode* root = 0;    // Огодлошуєм структуру дерева
    int a;
    // В циклі вводимо 8 вузлів дерева
    for (int i = 0; i < 8; i++)
    {
        cout << "Enter the node " << i + 1 << ": ";
        cin >> a;
        root = addnode(a, root); // розміщіємо введений елемант на дереві
    }
    treeprint(root);    // виводимо елементи  дерева, получаєм відсортований масив
    freemem(root);      // видаляємо виділену пам'ять
    cin.get();  cin.get();
    return 0;
}