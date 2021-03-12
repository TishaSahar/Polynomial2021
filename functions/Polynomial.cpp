#include "Polynomial.h"


monom monom::operator = (const monom &_m) {							//Оператор присваивания
	a = _m.a;
	deg = _m.deg;
	return *this;
}
ostream &operator << (ostream &out, const monom &m) {			    //Перегрузка потока вывода
	int k = (m.deg / 10000); int j = (m.deg - (k * 10000)) / 100; int i = m.deg % 100;
	out << m.a << "(x^" << i << ")(y^" << j << ")(z^" << k << ") ";
	return out;
}

Polynom::Polynom(const Polynom& _p) {//Конструктор копирования
	Node* node = _p.first;
	while (node->next != NULL) {
		this->addM(node->value);
		node = node->next;
	}
}

void Polynom::Clear()
{
	if (this->first != NULL)
	{
		Node* node = this->first;
		Node* next;
		while (node != NULL)
		{
			next = node->next;
			delete node;
			node = next;
		}
		this->first = NULL;
	}
	count = 0;
}

void Polynom::Print() {				//Печать полинома	
	if (this->count == 0)
	{
		cout << "Polynom is empty" << endl;
		return;
	}

	Node* node = this->first;
	cout << "f(x,y,z) = ";
	while (node != NULL) {
		if (node->next == NULL) {
			cout << node->value << endl;
			system("pause");
			return;
		}
		cout << node->value;
		if (node->next->value.getA() > 0) cout << "+ ";
		//else cout << " ";
		node = node->next;
	}
	return;
}

void Polynom::addM(monom _m) {		//Добавление монома в конец полинома
	Node* node = new Node(_m, NULL);
	if (this->first == NULL)
		this->first = node;
	else
		this->tail->next = node;
	this->tail = node;
	count++;
}

void Polynom::SortDeg() {
	Node* node = this->first;
	monom *ar = new monom[count];
	int k = 0;
	while (node != NULL) {
		ar[k] = node->value;
		node = node->next;
		k++;
	}

	for (int i = 0; i < k; i++)
		for (int j = i; j < k - 1; j++)
			if (ar[i].getDeg() > ar[i + 1].getDeg()) {
				monom t = ar[i];
				ar[i] = ar[j];
				ar[j] = t;
			}

	this->Clear();
	for (int i = 0; i < k; i++)
		this->addM(ar[i]);
}

const Polynom Polynom::operator+(const Polynom& RV)const {
	Node *left = first;
	Node *right = RV.first;

	Polynom Res;

	while ((left != NULL) && (right != NULL)) {
		if (left->value.getDeg() > right->value.getDeg())
			Res.addM(right->value);
		if (left->value.getDeg() == right->value.getDeg()) {
			double a = left->value.getA() + right->value.getA();
			int i = left->value.getI();
			int j = left->value.getJ();
			int k = left->value.getK();
			monom m(a, i, j, k);
			Res.addM(m);
		}
		else {
			Res.addM(left->value);
		}
		left = left->next;
		right = right->next;
	}

	while (right != NULL) {
		double a = right->value.getA();
		int i = right->value.getI();
		int j = right->value.getJ();
		int k = right->value.getK();
		monom m(a, i, j, k);
		Res.addM(m);
		right = right->next;
	}
	while (left != NULL) {
		double a = left->value.getA();
		int i = left->value.getI();
		int j = left->value.getJ();
		int k = left->value.getK();
		monom m(a, i, j, k);
		Res.addM(m);
		left = left->next;
	}

	return Res;
}

const Polynom Polynom::operator-(const Polynom& RV)const {
	Node *left = first;
	Node *right = RV.first;

	Polynom Res;

	while ((left != NULL) && (right != NULL)) {
		if (left->value.getDeg() > right->value.getDeg())
			Res.addM(right->value);
		if (left->value.getDeg() == right->value.getDeg()) {
			double a = left->value.getA() - right->value.getA();
			int i = left->value.getI();
			int j = left->value.getJ();
			int k = left->value.getK();
			monom m(a, i, j, k);
			Res.addM(m);
		}
		else {
			Res.addM(left->value);
		}
		left = left->next;
		right = right->next;
	}

	while (right != NULL) {
		double a = right->value.getA();
		int i = right->value.getI();
		int j = right->value.getJ();
		int k = right->value.getK();
		monom m(a, i, j, k);
		Res.addM(m);
		right = right->next;
	}
	while (left != NULL) {
		double a = left->value.getA();
		int i = left->value.getI();
		int j = left->value.getJ();
		int k = left->value.getK();
		monom m(a, i, j, k);
		Res.addM(m);
		left = left->next;
	}

	return Res;
}

const Polynom Polynom::operator*(const Polynom& RV)const {
	Polynom Res;
	Node* left = first;
	Node* right = RV.first;

	while (left != NULL) {
		Node* right = RV.first;
		while (right != NULL) {
			double a = (left->value.getA() * right->value.getA());
			int i = left->value.getI() + right->value.getI();
			int j = left->value.getJ() + right->value.getJ();
			int k = left->value.getK() + right->value.getK();
			monom m(a, i, j, k);
			Res.addM(m);
			right = right->next;
		}
		left = left->next;
	}

	return Res;
}

Polynom Polynom::operator=(const Polynom& P) {
	if (this->first == NULL) {
		first = P.first;
		tail = P.tail;
		count = P.count;
	}
	else {
		this->Clear();
		first = P.first;
		tail = P.tail;
		count = P.count;
	}
	return *this;
}

monom Polynom::operator[](const int index) {
	if (index >= count)
		throw logic_error("Index out of the range");
	else {
		int counter = 0;
		Node* node = first;
		while (counter++ != index)
			node = node->next;

		return node->value;
	}
}

double Polynom::counter(double x0, double y0, double z0) {
	Node *node = first;
	double res = 0.0;

	while (node != NULL) {
		double x = pow(x0, node->value.getI());
		double y = pow(y0, node->value.getJ());
		double z = pow(z0, node->value.getK());
		double a = node->value.getA();
		res += a*x*y*z;
		node = node->next;
	}

	return res;
}