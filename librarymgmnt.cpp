#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class LibraryItem
{
private:
    string title, author, dueDate;

public:
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem
{
    string ISBN;

public:
    Book(string t, string a, string d, string isbn)
    {
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
        if (isbn.size() < 5)
            throw invalid_argument("Invalid ISBN!");
        ISBN = isbn;
    }
    void checkOut() override { cout << "Book checked out: " << getTitle() << endl; }
    void returnItem() override { cout << "Book returned: " << getTitle() << endl; }
    void displayDetails() const override
    {
        cout << "Book: " << getTitle() << " | Author: " << getAuthor()
             << " | Due: " << getDueDate() << " | ISBN: " << ISBN << endl;
    }
};

class DVD : public LibraryItem
{
    int duration;

public:
    DVD(string t, string a, string d, int dur)
    {
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
        if (dur <= 0)
            throw invalid_argument("Invalid duration!");
        duration = dur;
    }
    void checkOut() override { cout << "DVD checked out: " << getTitle() << endl; }
    void returnItem() override { cout << "DVD returned: " << getTitle() << endl; }
    void displayDetails() const override
    {
        cout << "DVD: " << getTitle() << " | Director: " << getAuthor()
             << " | Due: " << getDueDate() << " | Duration: " << duration << " mins" << endl;
    }
};

class Magazine : public LibraryItem
{
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
    {
        setTitle(t);
        setAuthor(a);
        setDueDate(d);
        if (issue <= 0)
            throw invalid_argument("Invalid issue number!");
        issueNumber = issue;
    }
    void checkOut() override { cout << "Magazine checked out: " << getTitle() << endl; }
    void returnItem() override { cout << "Magazine returned: " << getTitle() << endl; }
    void displayDetails() const override
    {
        cout << "Magazine: " << getTitle() << " | Editor: " << getAuthor()
             << " | Due: " << getDueDate() << " | Issue: " << issueNumber << endl;
    }
};

int main()
{
    const int MAX_ITEMS = 10;
    LibraryItem *libraryItems[MAX_ITEMS];
    int count = 0, choice;

    libraryItems[count++] = new Book("Harry Potter", "J.K.Rowling", "12-4-2026", "12345");
    libraryItems[count++] = new DVD("Inception", "Christopher Nolan", "15-4-2026", 148);
    libraryItems[count++] = new Magazine("Time", "Time Editors", "20-4-2026", 101);

    do
    {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Display All Items\n2. Check Out Item\n3. Return Item\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < count; i++)
                libraryItems[i]->displayDetails();
        }
        else if (choice == 2)
        {
            int idx;
            cout << "Enter index (0-" << count - 1 << "): ";
            cin >> idx;
            if (idx >= 0 && idx < count)
                libraryItems[idx]->checkOut();
            else
                cout << "Invalid index!\n";
        }
        else if (choice == 3)
        {
            int idx;
            cout << "Enter index (0-" << count - 1 << "): ";
            cin >> idx;
            if (idx >= 0 && idx < count)
                libraryItems[idx]->returnItem();
            else
                cout << "Invalid index!\n";
        }
    } while (choice != 4);

    for (int i = 0; i < count; i++)
        delete libraryItems[i];
    return 0;
}
