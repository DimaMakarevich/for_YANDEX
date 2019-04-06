#include<iostream>
#include <string> 

using namespace std;

/*
1������ ����� ������ �������
2������ ������ �� �������� ��������������� � �� ����� ��������� ������ ����������������� 
*/



struct Tree
{
	int num_pass;;
	string surname;
	Tree *left, *right;
} *root;

int kol = 0;

int i = 0;
int *data_num = new int[100];
string *name = new string[50];

Tree *Del_Info(Tree **root, int pas)
{
	Tree *Del, *Prev_del, *T, *Prev_t;
	Del = *root;
	Prev_del = NULL;

	while (Del != NULL && Del->num_pass != pas)
	{
		Prev_del = Del;
		if (Del->num_pass > pas)
		{
			Del = Del->left;
		}
		else
		{
			Del = Del->right;
		}
	}

		if (Del == NULL)
		{
			cout << "������� �������� ��� " <<endl;
			return *root;
		}

		if (Del->right == NULL)
		{
			T = Del->left;
		}
		else
		{
			if (Del->left == NULL)
			{
				T = Del->right;
			}
			else
			{
				Prev_t = Del; ////////
				T = Del->left;
				while (T->right != NULL)
				{
					Prev_t = T;
					T = T->right;
				}

				if (Prev_t == Del)
				{
					T->right = Del->right;
				}
				else
				{
					T->right = Del->right;
					Prev_t->right = T->left;
					//T->left = Prev_t;
					T->left = Del->left;
				}
			}
		}
		
		if (Del == *root)
		{
			*root = T;
		}
		else
		{
			if (Del->num_pass < Prev_del->num_pass)
			{
				Prev_del->left = T;
			}
			else
			{
				Prev_del->right = T;
			}
		}

		delete Del;
		return *root;
}

Tree *List(int pas,string sur)
{
	Tree *t = new Tree;
	t->num_pass = pas;
	t->surname = sur;
	t->left = t->right = NULL;
	return t;
}

void Del_Tree(Tree **t)
{
	if (*t != NULL)
	{
		Del_Tree(&(*t)->left); 			
		Del_Tree(&((*t)->right));
		delete *t;
	}
}


void creation(Tree **root, int pass, string surname)
{
	Tree *prev=NULL, *t;
	bool find = true;
	t = *root;

	while (t != NULL && find)
	{
		prev = t;
	
		if (pass == t->num_pass)
		{
			find = false;
		}
		else
		{
			if (pass < t->num_pass)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
		}
	}

	if (find == true)
	{
		t = List(pass, surname);

		if (pass < prev->num_pass)
		{
			prev->left = t;
		}
		else
		{
			prev->right = t;
		}
	}



}

//void viev_all(Tree *root,int level)
//{
//	string str;
//
//	if (root != NULL)
//	{
//		viev_all(root->right, level++);
//
//		for (int i = 0; i < level; i++)
//		{
//			//str = str + "  ";
//			cout << "   ";
//		}
//
//		cout << root->num_pass << endl;
//		viev_all(root->left, level++);
//	}
//}

void vie1(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->num_pass << endl;
	vie1(root->left);
	vie1(root->right);
}

void vie2_dlay_balance(Tree *root)
{
	if (root == NULL)
	{
		return;
	}

	vie2_dlay_balance(root->left);
	data_num[i] = root->num_pass;
	name[i] = root->surname;
	i++;
	vie2_dlay_balance(root->right);
}

void vie2(Tree *root)
{	
	if (root == NULL)
	{
		return;
	}

	vie2(root->left);
	cout << root->num_pass << endl;
	vie2(root->right);
}


void vie3(Tree *root) 
{
	if (root == NULL)
	{
		return;
	}

	vie3(root->left);
	vie3(root->right);
	cout << root->num_pass << endl;
}

void View_Tree(Tree *p, int level) {
	string str;
	if (p) {
		View_Tree(p->right, level + 1);		// ������ ���������
		for (int i = 0; i < level; i++) str = str + "    ";
		//Form1->Memo1->Lines->Add(str + IntToStr(p->info));
		cout << str << p->num_pass<<endl ;
		View_Tree(p->left, level + 1); 			// ����� ���������
	}
}


void view_1(Tree **root, int pass)	//ssdelat ne �� ����� ���������  � ����� �������� 
{
	Tree *prev = NULL, *t;
	bool find = true;
	t = *root;

	while (t != NULL && find)
	{
		prev = t;

		if (pass == t->num_pass)
		{
			find = false;
			cout << t->surname<<"\t" << t->num_pass << endl;;
		}
		else
		{
			if (pass < t->num_pass)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
		}
	}

							
}


void  task(Tree *root)
{
	
	//
	//if (root == NULL)
	//{
	//	return;
	//}
	
	if (root->left != NULL && root->right != NULL)
	{
		kol++;
	}

	/*if (root->left != NULL || root->right != NULL)
	{
		task(root->left);
		task(root->right);
	}*/
	
	if (root->left != NULL )
	{
		task(root->left);
		
	}
	if (root->right != NULL)
	{
		task(root->right);
	}
}

void Make_Blns(Tree **p, int n, int k, int *a, string *b) 
{
	if (n == k) 
	{
		*p = NULL;
		return;
	}
	else 
	{
		int m = (n + k) / 2;
		 *p = new Tree;
		(*p)->num_pass= a[m];
		(*p)->surname = b[m];
		Make_Blns(&(*p)->left, n, m, a, b);
		Make_Blns(&(*p)->right, m + 1, k, a, b );
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	int pass1 = 2342,pass2=4567,pass3=9867,pass4=1234,pass5=3900,pass6=11000;
	string sur1 = "Makarevich",sur2="Avilov",sur3="Gamag",sur4="Oxxy", sur5 = "55555", sur6 = "66666";
	//root = NULL;////
	root = List(pass1, sur1);

//	creation(&root, pass1, sur1);
	creation(&root, pass2, sur2);
	creation(&root, pass3, sur3);
	creation(&root, pass4, sur4);
	creation(&root, pass5, sur5);
	creation(&root, pass6, sur6);

menu:

	cout << "1) ������ ����� ������+" << endl;
	cout << "2) ������� ������� �������� �� ������ ��������+" << endl;
	cout << "3) ������� �������� � �������� ������ ��������+" << endl;
	cout << "4) �������������� ������ ������+ " << endl;
	cout << "5) ����� ����� ����� ������� 2 �������+ " << endl;
	cout << "6) ����� ����������  ----------" << endl;
	cout << "7) �����+ " << endl;
	cout << "8) ������, ������������ � �������� �����+ " << endl;
	
	int p;
	cin >> p;

	switch (p)
	{

	case 1: 
	{
	
		int pass;
		string surname;
		cout << "\n ������� ����� ��������  " << endl;
		cin >> pass;
		cout << "\n ������� ������� " << endl;
		cin >> surname;
		
		creation(&root, pass, surname);
		
		break;
	}
	case 2:
	{
		int pass;
		cout << "\n ������� ����� ��������  " << endl;
		cin >> pass;

		view_1(&root, pass);
		
		 
		break;
	}

	case 3:
	{
		int pass;
		cout << "\n ������� ����� ��������  " << endl;
		cin >> pass;

		//del_1(&root, pass);
		Del_Info(&root, pass);
		break;
	}

	case 4:
	{
		Tree *bal = new Tree;

		vie2_dlay_balance(root);
		//Del_Tree(&root);
		
		Make_Blns(&bal,0,i,data_num,name);
		i = 0;
		
		root = bal;

		break;
	}

	case 5:
	{
		task(root);
		cout <<"����� ������ � ����� ���������: " <<kol<<endl;
		kol = 0;
		break;
	}

	case 6:
	{

		 View_Tree(root,0);
		break;
	}

	case 7:
	{

		return 0;
		break;
	}

	case 8:
	{
		cout << "-------------------������ �����-------------------------------------------------------------------" << "\n";
		vie1(root);
		cout << "-------------------������������ �����------------------------------------------------------------" << "\n";
		vie2(root);
		cout << "-------------------�������� �����----------------------------------------------------------------" << "\n";
		vie3(root);
		cout << "-------------------------------------------------------------------------------------------------" << "\n";
		break;
	}
	

	}
	
	goto menu;
	system("pause");
	//return 0;
}