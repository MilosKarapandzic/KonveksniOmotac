#include <iostream>;
#include "mnogougao.h"
using namespace std;

int main()
{
	float x, y;
	cout << "Unesite tacke, kad zavrsite unesite slovo." << endl;
	vector<tacka> Temena;
	while (cin >> x >> y) Temena.push_back(tacka(x, y, 0));
	mnogougao m1(Temena);
	cout << "konveksni omotac : " << endl;
	for (auto& tacka : m1.tacke)
	{
		cout << tacka.x << " " << tacka.y << endl;
	}
}