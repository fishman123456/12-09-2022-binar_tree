// 12-09-2022-binar_tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
// структура представляющая элемент дерева
typedef struct tree_element{
    int valve; // корень
    struct three_element* left; //
    struct three_element* right;
} tree_element;

//создание элемента с заданным значением
tree_element* create_tree_element(int i);

//вставляем элемент elem в дерево с корнем root
void insert_into_tree(tree_element* root, tree_element* elem);

//печать дерева от элемента вниз
void print_tree(tree_element* cur_elem);

tree_element* create_tree_element(int i) {
    tree_element* elem = new tree_element;
    elem->valve = i;
    elem->left = NULL;
    elem->right = NULL;
} tree_element;

void insert_into_tree(tree_element* root, tree_element* elem) {
    if (elem->valve < root->valve) {
        //идем в левое поддерево
        if (root->left == NULL) {
            // левое поддерево - пустое. Сюда и вставляем новый элемент.
            root->left = elem;
        }
        else {
            //слева что то есть рекурсивно вставляем в левое поддерево
            insert_into_tree(root->right, elem);
        }
    }
    else { //идем в правое поддерево
        if (root->right == NULL) {
            root->right = elem;
        }
        else {
            insert_into_tree(root->right, elem);
        }
    }
}
void print_tree(tree_element* cur_elem) {
    if (cur_elem->left !=NULL){
        print_tree(cur_elem->left);
    }
    cout << "Valve= " << cur_elem->valve << endl;
    if (cur_elem->right !=NULL){
        print_tree(cur_elem->right);
    }
}

int main()
{
    int a[7] = { -3,1,-5,42,2,-6,8 };
    tree_element* root = create_tree_element(0);
    for (int i = 0; i < 7; i++){
        tree_element* el = create_tree_element(a[i]);
        insert_into_tree(root, el);
    }
    cout << "My tree:" << endl;
    print_tree(root);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
