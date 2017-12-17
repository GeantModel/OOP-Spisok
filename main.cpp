#include <stdlib.h>
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T value;
    int number;
    Node *Next;
    Node *Previous;
};

template <class T>
class List{
public:
    Node <T> *Begin;
    Node <T> *End;
    List():Begin(NULL),End(NULL){};
    ~List();
    void AddBegin(T value);
    void AddEnd(T value);
    void ShowBegin();
    void ShowEnd();
    void add2(T value, int number);
};
template <class T>
List <T>::~List <T> () {
    Node <T> *temp;
    while (Begin) {
        temp = Begin->Next;
        delete Begin;
        Begin = temp;
    }
}
template <class T>
void List <T>::AddBegin(T value) {
    Node <T> *temp = new Node <T>;
    temp->Previous = NULL;
    temp->value = value;

    if (Begin!= NULL) {
        Node <T> *buff = Begin;
        while (buff != NULL) {
            (buff->number) += 1;
            buff = buff->Next;
        }
        temp->number = ((Begin->number) - 1);
        temp->Next = Begin;
        Begin->Previous = temp;
        Begin = temp;
    } else {
        temp->number = 1;
        temp->Next = NULL;
        Begin = End = temp;
    }
}
template <class T>
void List <T>::AddEnd(T value) {
    Node <T> *temp = new Node <T>;
    temp->Next = NULL;
    temp->value = value;

    if (Begin != NULL) {
        temp->number = ((End->number) + 1);
        temp->Previous = End;
        End->Next = temp;
        End = temp;
    } else {
        temp->number = 1;
        temp->Previous = NULL;
        Begin = End = temp;
    }
}

template <class T>
void List <T>::add2(T value, int number) {
    if (number == 1) {
        AddBegin(value);
    } else if( number ==((End->number) + 1) ) {
        AddEnd(value);
    } else if(number > ((End->number) + 1) ) {
        cout << "Cannot add element to position " << number << endl;
    } else {
        Node <T> *buff = Begin;
        while ((buff->number) != number) {
            buff = buff->Next;
        }
        Node <T> *buffprev = buff->Previous;
        Node <T> *temp = new Node <T>;
        temp->value = value;
        temp->number = number;

        buffprev->Next = temp;
        temp->Previous = buffprev;
        temp->Next = buff;
        buff->Previous = temp;
        while (buff != NULL) {
            (buff->number) += 1;
            buff = buff->Next;
        }
    }
}

template <class T>
void List <T>::ShowBegin() {
    Node <T> *temp = Begin;
    while (temp != NULL) {
        cout << temp->number << " = " << temp->value << "; ";
        temp = temp->Next;
    }
    cout << endl;
}

template <class T>
void List <T>::ShowEnd() {
    Node <T> *temp = End;
    while (temp != NULL) {
        cout << temp->number << " = " << temp->value << "; ";
        temp = temp->Previous;
    }
    cout << endl;
}

int main () {
    List <double> lst;

    lst.AddEnd(100.1);
    lst.AddEnd(200);
    lst.AddEnd(300.3);
    lst.AddEnd(400);

    lst.AddBegin(500.1);
    lst.AddBegin(600);

    lst.add2(700,2);
    lst.add2(10,1);
    lst.add2(99,15); // error
    lst.add2(99,9);

    lst.AddEnd(444.2);

    lst.ShowBegin();
    cout << endl;
    lst.ShowEnd();
}