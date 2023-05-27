#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

typedef struct node {
	char data;
	struct node *left;
    struct node *right;
} node;

node* newNode(char c) {
	node* n = new node;
	n->data = c;
	n->left = n->right = nullptr;
	return n;
}

node* build(string& s) {
	stack<node*> littleTree;
	stack<char> fuhao;
	node *t, *t1, *t2;

	int p[123] = { 0 };
	p['+'] = p['-'] = 1, p['/'] = p['*'] = 2, p['^'] = 3,
	p[')'] = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(')
			fuhao.push(s[i]);

		else if (isalpha(s[i])) {
			t = newNode(s[i]);
			littleTree.push(t);
		}

		else if (p[s[i]] > 0) {
			while (!fuhao.empty() && fuhao.top() != '('
                    && ((s[i] != '^' && p[fuhao.top()] >= p[s[i]])
                        || (s[i] == '^' && p[fuhao.top()] > p[s[i]]))) {
				t = newNode(fuhao.top());
				fuhao.pop();

				t1 = littleTree.top();
				littleTree.pop();

				t2 = littleTree.top();
				littleTree.pop();

				t->left = t2;
				t->right = t1;

				littleTree.push(t);
			}
			fuhao.push(s[i]);
		}

		else if (s[i] == ')') {
			while (!fuhao.empty() && fuhao.top() != '(') {
				t = newNode(fuhao.top());
				fuhao.pop();
				t1 = littleTree.top();
				littleTree.pop();
				t2 = littleTree.top();
				littleTree.pop();
				t->left = t2;
				t->right = t1;
				littleTree.push(t);
			}
			fuhao.pop();
		}
	}
	t = littleTree.top();
	return t;
}

void pOrder(node* head) {
	if (head != nullptr)
	{
		pOrder(head->left);
		pOrder(head->right);
		cout << head->data;
	}
}

int main() {
	string s;
	cin >> s;
	node* head = build(s);

	pOrder(head);
	return 0;
}

