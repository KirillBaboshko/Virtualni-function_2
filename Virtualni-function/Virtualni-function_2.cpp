#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Math.h>
using namespace std;
class A
{
public:
	int val=1;
};
class B:public virtual A
{
public:
	B()
	{
		val += 2;
	}

};
class C :public virtual A
{
public:
	C()
	{
		val += val;
	}
};
class D :public B,C
{
public:
	D()
	{
	}
	int Get_val()
	{
		return val;
	}

};
class Base
{
private:
	char* sp1;
	int size;
public:
	Base(const char* S, int s)
	{
		size = s;
		sp1 = new char[size];
	}
	virtual~Base()
	{
		cout << "Base";
		delete[]sp1;
	}
};
class Derivaed :public Base
{
private:
	char* sp2;
	int size2;
public:
	Derivaed(const char* S1, int s1, const char* S2, int s2) :Base(S1, s1)
	{
		size2 = s2;
		sp2 = new char[size2];
	}
	virtual~Derivaed()
	{
		cout << "Derived";
		delete[]sp2;
	}
};
//class Something
//{
//public:
//	virtual ~Something() = 0;
//	~Something() {}
//};
class Boss
{
public:
	Boss(){}
	virtual void root(int a,int b,int c) = 0;
};
class Lin :public Boss
{
public:
	Lin(){}
	virtual void root(int a, int b, int c)
	{
		if (a == 0)
		{
			cout << "net korney";
		}
		else
		{
			cout << "x=" << -b / a << "\n";
		}
	}
};
class Cvad :public Boss
{
public:
	Cvad() {}
	virtual void root(int a, int b, int c)
	{
		int D;
		D = (b * b) - 4 * (c * a);
		if (D < 0)
		{
			cout << "net korney";
		}
		else 
		{
			if (D == 0)
			{
				D = sqrt(D);
				cout << "x=" << (-b + D) / (2 * a) << "\n";
			}
			else 
			{
				D = sqrt(D);
				cout << "x1=" << (-b + D) / (2 * a) << "\n";
				cout << "x2=" << (-b - D) / (2 * a) << "\n";
			}
		}
	}
};
class Fox 
{
public:
	int age;
	int maxage=6;
	Fox()
	{
		age = 1;
	}
	Fox(int a)
	{
		age = a;
	}
};
class Rabbit
{
public:
	int age;
	int maxage=4;
	Rabbit()
	{
		age = 1;
	}
	Rabbit(int a)
	{
		age = a;
	}
};
class Grass
{
public:
	int countg;
	bool grass=1;
};
class Living:virtual Grass,Rabbit,Fox
{
	Rabbit* r;
	int countfox;
	Fox* f;
	int countrabit;

public:
	Living() 
	{
		countg= rand() % 100;
		countfox = rand() % 8;
		countrabit = rand() % 20;
		r = new Rabbit[countrabit];
		f = new Fox[countfox];
	}
	void Life()
	{
		int sezon =1;
		while (countfox > 0, countrabit > 0,grass==1)
		{
			for (int i = 0; i < countfox; i++)
			{
				if (f[i].age >= f[i].maxage)
				{
					f[i]=NULL;
					countfox--;
				}
			}
			for (int i = 0; i < countrabit; i++)
			{
				if (r[i].age >= r[i].maxage)
				{
					r[i] = r[countrabit-1];
					countrabit--;
				}
			}
			if (countg < countrabit)
			{
				grass = 0;
				countg = 0;
			}
			if (countfox > countrabit)
			{
				countrabit--;
			}
			for (int i = 0; i < countfox; i++)
			{
				if (f[i].age >= f[i].maxage)
				{
					f[i] = NULL;
					countfox--;
				}
			}
			for (int i = 0; i < countrabit; i++)
			{
				r[i].age += 1;
			}
			for (int i = 0; i < countfox; i++)
			{
				f[i].age += 1;
			}
			cout << "Сезон " << sezon<<endl;
			cout << "Кроликов " << countrabit << endl;
			cout << "Лис " << countfox << endl;
			cout << "Травы " << countg << endl;
			cout << "Живём , Живём!!" << endl;
			getchar();
			for (int i = countfox; i < countfox + countfox / 2; i++)
			{
				f[i].age = 1;
			}
			countfox+=countfox/2;
			for (int i = countrabit; i < countrabit + countrabit / 2; i++)
			{
				r[i].age = 1;
			}
			countrabit+= countrabit/2;
			sezon = +1;
		}

	}

};
void main()
{
	setlocale(0, "rus");
	/*D t;
	cout << t.Get_val();

	Derivaed MyString("string 1", 9, "string 2", 9);
	Base* pBase;
	pBase = new Derivaed("string 1", 9, "string 2", 9);
	delete[] pBase;*/
	/*Boss* b[2] = { new Lin(),new Cvad() };
	for (int i = 0; i < 2; i++)
	{
		b[i]->root(1,-6,9);
	}*/
	Living l;
	l.Life();
}

