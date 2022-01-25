#include <iostream>

using namespace std;

class Data
{
private:
    string BookId, NameBook, Author, yearSpreaded;

public:
    Data()
    {
        BookId = NameBook = Author = yearSpreaded = "";
    }

    Data(string bookId, string name, string author, string year)
    {
        this->BookId = bookId;
        this->NameBook = name;
        this->Author = author;
        this->yearSpreaded = year;
    }

    void showInfo()
    {
        cout << "ID: " << this->BookId << endl;
        cout << "Title: " << this->NameBook << endl;
        cout << "Author: " << this->Author << endl;
        cout << "Year Spreaded: " << this->yearSpreaded << endl;
    }

    string getBookId() { return BookId; }
    string getNameBook() { return NameBook; }
    string getAuthor() { return Author; }
    string getYear() { return yearSpreaded; }
};

class Node
{
public:
    Data data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() { first = nullptr; }
    ~LinkedList()
    {
        Node *p = first;

        while (first)
        {
            first = first->next;
            delete p;
            p = first;
        }
    }

    void Insert(int, Data);

    int Length();

    void Display();

    Node *Search(string Author);

    int getPosByID(string);
};

int LinkedList::Length()
{
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void LinkedList::Display()
{
    Node *p = first;
    if (p == nullptr)
    {
        cout << "Empty List" << endl;
    }
    else
    {
        while (p)
        {
            cout << "----------------------------" << endl;
            p->data.showInfo();
            cout << "----------------------------" << endl;
            p = p->next;
        }
    }
}

void LinkedList::Insert(int index, Data data)
{
    Node *t, *p = first;

    if (index < 0 || index > Length())
    {
        return;
    }

    t = new Node;
    t->data = data;
    t->next = nullptr;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

Node *LinkedList::Search(string TargetAuthor)
{
    Node *p = first;
    Node *target;
    while (p)
    {
        if (p->data.getAuthor() == TargetAuthor)
        {
            target = p;
            break;
        }
        p = p->next;
    }
    return target;
}

int LinkedList::getPosByID(string TargetID)
{
    Node *p = first;
    int idx = 0;
    while (p)
    {
        if (p->data.getBookId() == TargetID)
            break;
        idx++;
        p = p->next;
    }
    return idx;
}

int main()
{
    LinkedList BookList;
    Data data("NA001", "Xem Nhau La Di Vang", "Nguyen Le Dong Manh", "2022");
    Data data2("NA002", "Xem Nhau La Di Vang 2", "Nguyen Le Dong Manh", "2022");
    Data data3("500112", "Xem Nhau La Di Vang 3", "Nguyen Le Dong Manh", "2022");
    Data data4("500113", "Xem Nhau La Di Vang 4", "Pham Giang", "2022");
    BookList.Insert(0, data);
    BookList.Insert(1, data2);
    BookList.Insert(2, data3);
    BookList.Insert(3, data4);
    Node *target = BookList.Search("Pham Giang");
    cout << "List of author " << endl;
    BookList.Display();
    cout << "The result of Search progress with target name :Pham Giang " << endl;
    target->data.showInfo();

    int position = BookList.getPosByID("500112");
    Data newBook("NA003", "Rieng Mot Goc Troi", "Nguyen Le Dong Manh", "2022");
    BookList.Insert(position, newBook);
    cout << "----------------New list---------------" << endl;
    BookList.Display();
    return 0;
}