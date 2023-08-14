/*A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to display
whole data sorted in ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword. Use Binary Search Tree for
implementation.(Binary Tree Implementaion)*/

#include <iostream>
#include <string>
using namespace std;

struct node
{
    string key;
    string meaning;
    node *left = NULL;
    node *right = NULL;
};

class Dictionary_Tree
{
public:
    node *root;
    Dictionary_Tree()
    {
        root = NULL;
    }
    node *add(node *r, node *temp)
    {
        if (r == NULL)
        {
            return temp;
        }
        if (r->key > temp->key)
        {
            r->left = add(r->left, temp);
        }
        else
        {
            r->right = add(r->right, temp);
        }
        return r;
    }

    node *minval(node *r)
    {
        while (r->left != NULL)
        {
            r = r->left;
        }
        return r;
    }

    node *delete_key(node *r, string k)
    {
        if (r == NULL)
            return NULL;
        if (r->key > k)
        {
            r->left = delete_key(r->left, k);
        }
        else if (r->key < k)
        {
            r->right = delete_key(r->right, k);
        }
        else
        {
            if (!r->left && !r->right)
            {
                return NULL;
            }
            else if (r->left && !r->right)
            {
                return r->left;
            }
            else if (!r->left && r->right)
            {
                return r->right;
            }
            else
            {
                node *rep = minval(r->right);
                r->key = rep->key;
                r->meaning = rep->meaning;
                r->right = delete_key(r->right, rep->key);
                return r;
            }
        }
        return r;
    }

    void display(node *r)
    {
        if (r != NULL)
        {
            display(r->left);
            cout << r->key << ":" << r->meaning << endl;
            display(r->right);
        }
    }

    void update(node *r, string k)
    {
        if (r != NULL)
            r->meaning = k;
        else
            cout << "Invalid input!!!" << endl;
    }

    node *find(node *r, string k)
    {
        while (r != NULL)
        {
            if (r->key == k)
            {
                return r;
            }
            if (r->key > k)
            {
                r = r->left;
            }
            else
            {
                r = r->right;
            }
        }
        return NULL;
    }
};

int main()
{
    Dictionary_Tree obj;
    bool flag = true;
    int ch;
    string s, k;
    node *t;
    while (flag)
    {
        cout << "MENU" << endl;
        cout << "1.Add" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Display" << endl;
        cout << "4.Update" << endl;
        cout << "5.Find" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            t = new node();
            cout << "Enter key:";
            cin >> t->key;
            cout << "Enter meaning:";
            cin >> t->meaning;
            if (obj.root == NULL)
            {
                obj.root = t;
            }
            else
            {
                obj.add(obj.root, t);
            }

            break;

        case 2:
            cout << "Enter key to be deleted:";
            cin >> s;
            obj.delete_key(obj.root, s);
            break;

        case 3:
            obj.display(obj.root);
            cout << endl;
            break;

        case 4:
            cout << "Enter key you want to update:";
            cin >> s;
            cout << "Enter new meaning:";
            cin >> k;
            obj.update(obj.find(obj.root, s), k);
            break;

        case 5:
            cout << "Enter key to find:";
            cin >> s;
            t = obj.find(obj.root, s);
            if (t != NULL)
            {
                cout << t->key << ":" << t->meaning << endl;
            }
            else
            {
                cout << "Not Present";
            }
            break;

        case 6:
            flag = false;
            break;

        default:
            cout << "Invalid input" << endl;
            break;
        }
    }

    return 0;
}