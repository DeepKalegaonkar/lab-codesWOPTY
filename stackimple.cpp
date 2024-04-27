#include <iostream>
using namespace std;

class treenode {
    int data;
    treenode* left;
    treenode* right;
    friend class tree;
};

class stack {
    int top;
    treenode* data[30];

public:
    stack() {
        top = -1;
    }

    void push(treenode* temp) {
        data[++top] = temp;
    }

    treenode* pop() {
        return data[top--];
    }

    int empty() {
        return top == -1;
    }

    friend class tree;
};

class tree {
    treenode* root;

public:
    tree() {
        root = NULL;
    }

    void nonrec_bincreate();
    void create_r(treenode* root);
    void preorder(treenode* root);
    void inorder(treenode* root);
    void postorder_nr(treenode* root);

    void preorder();
    void inorder();
    void postorder_nr();
};

void tree::nonrec_bincreate() {
    root = new treenode();
    cout << "Enter root data: ";
    cin >> root->data;
    root->left = root->right = NULL;
    create_r(root);
}

void tree::create_r(treenode* root) {
    char choice;
    do {
        int flag = 0;
        char ch;
        treenode* temp = root;
        treenode* curr = new treenode();
        cout << "Enter the data: ";
        cin >> curr->data;
        curr->left = curr->right = NULL;
        while (flag == 0) {
            cout << "Where do you want to enter the data: Right(R) or Left(L) " << temp->data << ": ";
            cin >> ch;
            if (ch == 'L') {
                if (temp->left == NULL) {
                    temp->left = curr;
                    flag = 1;
                } else {
                    temp = temp->left;
                    flag = 0;
                }
            }
            if (ch == 'R') {
                if (temp->right == NULL) {
                    temp->right = curr;
                    flag = 1;
                } else {
                    temp = temp->right;
                    flag = 0;
                }
            }
        }
        cout << "Do you want to add more nodes to the tree: Y/N ";
        cin >> choice;
    } while (choice == 'Y');
}

// Preorder
void tree::preorder(treenode* root) {
    stack st;
    treenode* temp = root;
    while (1) {
        while (temp != NULL) {
            cout << temp->data << " ";
            st.push(temp);
            temp = temp->left;
        }
        if (st.empty())
            break;
        temp = st.pop();
        temp = temp->right;
    }
    cout << endl;
}

void tree::preorder() {
    preorder(root);
}

// Inorder
void tree::inorder(treenode* root) {
    stack st;
    treenode* temp = root;
    while (1) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        if (st.empty())
            break;
        temp = st.pop();
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

void tree::inorder() {
    inorder(root);
}

// Postorder
void tree::postorder_nr(treenode* root) {
    stack st;
    treenode* temp = root;
    while (1) {
        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }
        if (st.empty())
            break;
        if (st.data[st.top]->right == NULL) {
            temp = st.pop();
            cout << temp->data << " ";
            while (!st.empty() && st.data[st.top]->right == temp) {
                temp = st.pop();
                cout << temp->data << " ";
            }
        }
        if (!st.empty())
            temp = st.data[st.top]->right;
        else
            break;
    }
    cout << endl;
}

void tree::postorder_nr() {
    postorder_nr(root);
}

int main() {
    tree t;
    cout << "Binary Tree \n";
    t.nonrec_bincreate();
    cout << endl;

    cout << "Preorder Traversal of Binary Tree\n";
    t.preorder();

    cout << "Inorder Traversal of Binary Tree\n";
    t.inorder();

    cout << "Postorder Traversal of Binary Tree\n";
    t.postorder_nr();

    return 0;
}
