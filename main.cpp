#include <iostream>

using namespace std;


const int N = 64;


struct list
{
    char name[N];
    list* left;
    list* right;
};


void list_extend();
void list_print();
list* list_find(char value[]);
void list_delete();


list* head;


int main()
{
    head = nullptr;

    char temp[N];
    while (strcmp(temp, "0") != 0)
    {
        cout << "List: ";
        list_print();
        cout << "[0] Exit\n";
        cout << "[1] Extend\n";
        cout << "[2] Find\n";
        cin >> temp;
        if (strcmp(temp, "1") == 0)
        {
            list_extend();
        }
        else if (strcmp(temp, "2") == 0)
        {
            cout << "Enter name to find: ";
            cin >> temp;
            list* ans = list_find(temp);
            if (ans != nullptr)
            {
                cout << ans << "\n";
            }
            else
            {
                cout << "not found\n";
            }
        }
    }
    list_delete();
    return 0;
}


void list_extend()
{
    list* elem;
    char temp[N];
    elem = new list;
    cout << "Enter new name (# - for end): ";
    cin >> elem->name;
    while (strcmp(elem->name, "#") != 0)
    {
        if (head == nullptr)
        {
            head = elem;
            elem->right = head;
            elem->left = head;
        }
        else
        {
            elem->right = head;
            elem->left = head->left;
            head->left->right = elem;
            head->left = elem;
        }
        elem = new list;
        cout << "Enter new name (# - for end): ";
        cin >> elem->name;
    }
    delete elem;
}


void list_print()
{
    list* elem;
    elem = head;
    cout << "[";
    if (head != nullptr)
    {
        do {
            cout << (elem != head ? ", \n" : "\n") << elem << ": " << elem->name;
            elem = elem->right;
        } while (elem != head);
        cout << "\n";
    }

    cout << "]\n";
}


list* list_find(char value[])
{
    list* elem;
    elem = head;
    if (head != nullptr)
    {
        do {
            if (strcmp(elem->name, value) == 0)
            {
                return elem->left;
            }
            elem = elem->right;
        } while (elem != head);
    }
    return nullptr;
}


void list_delete()
{
    list* elem;
    list* next;
    elem = head;
    if (head != nullptr)
    {
        do {
            next = elem->right;
            delete elem;
            elem = next;
        } while (elem != head);
    }
    head = nullptr;
}