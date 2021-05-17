
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*  Створити шаблонний клас – стек на основі зв’язного списку
у динамічній пам’яті. Тип елементів стеку визначається параметром
шаблона (цілі числа, дійсні числа, символи або символьні рядки).
Передбачити функції для виконання таких операцій: занесення
елемента у стек, вилучення значення з вершини стеку, виведення
усіх значень стеку на екран, перевірка чи послідовність елементів
у стеку є опуклою (починається зі зростаючої ділянки і завершується спадною).*/
int Array(char s);      //абетка на англ
int Strlen(string str);//розмір рядка


template<typename T>
class ListSteck
{
private:
    template<typename T>
    class Node
    {
    public:
        T value;
        Node* p_next;


        Node(T value = T(), Node* p_next = nullptr)
        {
            this->value = value;
            this->p_next = p_next;
        }
    };


public:
    ListSteck();
    ~ListSteck();
    void addnewel(T date); //добавлення нового елементу методом ззаду(стек)
    void deleteTop(); //видалення вершини
    void deleteBottom(); //видалення дна стеку
    int getsize() { return size; }
    void delstack(); // видалення цілого стеку
    bool checki();   //перевірка опуклості int
    bool checkc(); //перевірка опуклості char
    bool checks(); //перевірка опуклості string
    T& operator[](const int index);

    int size;
    Node<T>* bottom;
    Node<T>* top;
};
template<typename T>
ListSteck<T>::ListSteck() {
    size = 0;
    bottom = nullptr;
}
template<typename T>
ListSteck<T>::~ListSteck() {

    delstack();
}
template<typename T>
void ListSteck<T>::addnewel(T date) {

    if (bottom == nullptr) {
        bottom = new Node<T>(date);
    }
    else {
        Node<T>* tmp = this->bottom;
        while (tmp->p_next != nullptr) {
            tmp = tmp->p_next;
        }
        tmp->p_next = new Node<T>(date);
        this->top = tmp->p_next;
    }

    this->size++;

}
template<typename T>
T& ListSteck<T>::operator[](const int index) {
    int count = 0;
    Node<T>* copy_tmp = this->bottom;
    while (copy_tmp != nullptr) {

        if (count == index) {
            return copy_tmp->value;
        }
        copy_tmp = copy_tmp->p_next;
        count++;
    }
}
template<typename T>
void ListSteck<T>::deleteTop() {

    Node<T>* temp = top;
    top = top->p_next;
    delete temp;
    size--;
}
template<typename T>
void ListSteck<T>::deleteBottom() {

    Node<T>* temp = bottom;
    bottom = bottom->p_next;
    delete temp;
    size--;
}
template<typename T>
void ListSteck<T>::delstack() {
    Node<T>* temp = top;
    while (size) {
        deleteBottom();
    }
}
template<typename T>
bool ListSteck<T>::checki() {
    Node<T>* temp = bottom;
    if (bottom->value < bottom->p_next->value)
    {
        while (temp->value < temp->p_next->value || temp->value == temp->p_next->value) {
            temp = temp->p_next;
        }
        if (temp->value > temp->p_next->value) {
            cout << "\n" << "Послідовність опукла" << endl << endl;
            return true;
        }
        else { cout << "\n" << "Послідовність не опукла" << endl << endl; return false; }
    }
    else if (bottom->value > bottom->p_next->value) { cout << "\n" << "Послідовність не опукла" << endl << endl; return false; }

}
template<typename T>
bool ListSteck<T>::checkc() {
    Node<T>* temp = bottom;

    if (Array(bottom->value) < Array(bottom->p_next->value))
    {
        while (Array(temp->value) < Array(temp->p_next->value) || Array(temp->value) == Array(temp->p_next->value)) {
            temp = temp->p_next;
        }
        if (Array(temp->value) > Array(temp->p_next->value)) {
            cout << "\n" << "Послідовність опукла" << endl << endl;
            return true;
        }
        else { cout << "\n" << "Послідовність не опукла" << endl << endl;  return false; }
    }
    else if (Array(bottom->value) > Array(bottom->p_next->value)) { cout << "\n" << "Послідовність не опукла" << endl << endl; return false; }

}

template<typename T>
bool ListSteck<T>::checks() {
    Node<T>* temp = bottom;

        if (Strlen(bottom->value) < Strlen(bottom->p_next->value))
        {
            while (Strlen(temp->value) < Strlen(temp->p_next->value) || Strlen(temp->value) == Strlen(temp->p_next->value)) {
                temp = temp->p_next;
            }
            if (Strlen(temp->value) > Strlen(temp->p_next->value)) {
                cout << "\n" << "Послідовність опукла" << endl << endl;
                return true;
            }
            else { cout << "\n" << "Послідовність не опукла" << endl << endl;  return false; }
        }
        else if (Strlen(bottom->value) > Strlen(bottom->p_next->value)) { cout << "\n" << "Послідовність не опукла" << endl << endl; return false; }

}
int main() {
    system("chcp 1251");

    ListSteck<int> S1;
    S1.addnewel(66);
    S1.addnewel(11);
    S1.addnewel(17);
    S1.addnewel(6);
    S1.addnewel(3);
    S1.addnewel(2);

    cout << "\nРозмір: " << S1.getsize() << endl;
    for (int i = 0; i < S1.getsize(); i++) {
        cout << "Елемент " << i + 1 << "  " << S1[i] << endl;
    }
    cout << "\nВидалленя верхнього елементу" << endl;
    S1.deleteTop();
    cout << "\n\nРозмір: " << S1.getsize() << endl;
    for (int i = 0; i < S1.getsize(); i++) {
        cout << "Елемент " << i + 1 << "  " << S1[i] << endl;
    }
    S1.checki();

    ListSteck<string> S2;
    S2.addnewel("3211");
    S2.addnewel("fsafasfawa");
    S2.addnewel("fasfasfasfaw");
    S2.addnewel("fsafasfasf");
    S2.addnewel("dsaasas");
    S2.addnewel("dssf");
    cout << "\nРозмір: " << S2.getsize() << endl;
    for (int i = 0; i < S2.getsize(); i++) {
        cout << "Елемент " << i + 1 << "  " << S2[i] << endl;
    }
    cout << "\nВидалленя верхнього елементу" << endl;
    S2.deleteTop();
    cout << "\n\nРозмір: " << S2.getsize() << endl;
    for (int i = 0; i < S2.getsize(); i++) {
        cout << "Елемент " << i + 1 << "  " << S2[i] << endl;
    }
    S2.checks();

    ListSteck<char> S3;
    S3.addnewel('a');
    S3.addnewel('b');
    S3.addnewel('c');
    S3.addnewel('b');
    S3.addnewel('a');
    S3.addnewel('a');

    cout << "\nРозмір: " << S3.getsize() << endl;
    for (int i = 0; i < S3.getsize(); i++) {
        cout << "Елемент " << i + 1 << "  " << S3[i] << endl;
    }
    cout << "\nВидалленя верхнього елементу" << endl;
    S3.deleteTop();
    cout << "\n\nРозмір: " << S3.getsize() << endl;
    for (int i = 0; i < S3.getsize(); i++) {
        cout << "Елемент " << i + 1 << "  " << S3[i] << endl;
    }
    S3.checkc();
    return 0;
}

int Strlen(string str)
{
    return str.length();
}
int Array(char s)
{
    int res;
    switch (s) {
    case'0':res = 0; break;
    case'1':res = 1; break;
    case'2':res = 2; break;
    case'3':res = 3; break;
    case'4':res = 4; break;
    case'5':res = 5; break;
    case'6':res = 6; break;
    case'7':res = 7; break;
    case'8':res = 8; break;
    case'9':res = 9; break;
    case'a':res = 1; break;
    case'b':res = 2; break;
    case'c':res = 3; break;
    case'd':res = 4; break;
    case'e':res = 5; break;
    case'f':res = 6; break;
    case'g':res = 7; break;
    case'h':res = 8; break;
    case'i':res = 9; break;
    case'j':res = 10; break;
    case'k':res = 11; break;
    case'l':res = 12; break;
    case'm':res = 13; break;
    case'n':res = 14; break;
    case'o':res = 15; break;
    case'p':res = 16; break;
    case'q':res = 17; break;
    case'r':res = 18; break;
    case's':res = 19; break;
    case't':res = 20; break;
    case'u':res = 21; break;
    case'v':res = 22; break;
    case'w':res = 23; break;
    case'x':res = 24; break;
    case'y':res = 25; break;
    case'z':res = 26; break;
    }

    return res;
}