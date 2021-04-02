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

bool operator != (monom& l, monom& r) {
	if (l.getA() - r.getA() != 0.0) {
		return true;
	}
	if (l.getDeg() != r.getDeg()) {
		return true;
	}
	return false;
}


Polynom::Polynom(const Polynom& _p) {//Конструктор копирования
	Node* node = new Node(_p.first->value, _p.first->next);
	tail = first = new Node(_p.first->value, _p.first->next);
	count = 1;
	node = node->next;
	while (node != NULL) {
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

void Polynom::addM(monom _m) {	//Добавление монома в конец полинома
	if (_m.getA() == 0.00000) return;
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
		for (int j = i; j < k - 1; j++) {
			if (ar[j].getDeg() > ar[j + 1].getDeg()) {
				monom t = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = t;
			}
		}
	for(int i = 0; i < k-1; i ++)
		if (ar[i].getDeg() == ar[i + 1].getDeg()) {
			double a = ar[i].getA() + ar[i+1].getA();
			monom t1(a, ar[i].getI(), ar[i].getJ(), ar[i].getK());
			monom t2(0.0, 0, 0, 0);
			ar[i+1] = t1; ar[i] = t2;
		}
	this->Clear();
	for (int i = 0; i < k; i++)
		this->addM(ar[i]);
}

const Polynom Polynom::operator+(const Polynom& RV)const {
	Node *left = first; monom *ml = new monom[this->count];
	Node *right = RV.first;monom *mr = new monom[RV.count];

	int i = 0;
	while (right != NULL) {
		mr[i] = right->value;
		i++;
		right = right->next;
	}
	int j = 0;
	while (left != NULL) {
		ml[j] = left->value;
		j++;
		left = left->next;
	}

	int maxind = i + j;
	i = j = 0;

	monom *res = new monom[maxind];

	int k = 0;
	while ((i + j) < maxind) {
		if (mr[i].getDeg() < ml[j].getDeg()) {
			res[k] = mr[i];
			k++;
			i++;
		}
		else
			if(mr[i].getDeg() == ml[j].getDeg()) {
				double a = mr[i].getA() + ml[j].getA();
				monom t(a, mr[i].getI(), mr[i].getJ(), mr[i].getK());
				res[k] = t;
				k++; maxind--;
				i++; j++;
			}
			else
				if (mr[i].getDeg() > ml[j].getDeg()) {
					res[k] = ml[j];
					k++;
					j++;
				}
	}
	Polynom Res;
	for (int ind = 0; ind < maxind; ind++) {
		Res.addM(res[ind]);
	}
 
	return Res;
}

const Polynom Polynom::operator-(const Polynom& RV)const {
	Polynom Res(*this + (RV*(-1.0)));



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
	
	Res.SortDeg();
	return Res;
}

Polynom Polynom::operator=(const Polynom& _p) {
	Node* node = new Node(_p.first->value, _p.first->next);
	tail = first = new Node(_p.first->value, _p.first->next);
	count = 1;
	node = node->next;
	while (node != NULL) {
		this->addM(node->value);
		node = node->next;
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

const Polynom Polynom::operator*(const double RV)const {
	Polynom Res;
	if (this->count == 0) return Res;
	Node *left = first;
	while (left != NULL) {
		double _a = RV*left->value.getA();
		monom _m(_a, left->value.getI(), left->value.getJ(), left->value.getK());
		Res.addM(_m);
		left = left->next;
	}
	return Res;
}

bool operator == (const Polynom& l, const Polynom& r) {
	if (l.count != r.count) return false;
	Node *left = l.first;
	Node *right = r.first;
	while (left != NULL) {
		if (left->value != right->value) {
			return false;
		}
		left = left->next;
		right = right->next;
	}

	return true;
}