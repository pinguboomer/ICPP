#include<iostream>

struct Trojuhelnik
{
	int a;
	int b;
	int c;
};

bool lzeSestrojit(Trojuhelnik t)
{
	if (t.a + t.b > t.c && t.a + t.c > t.b && t.b + t.c > t.a) {
		return true;
	}
	else {
		return false;
	}
}

bool lzeSestrojit2(Trojuhelnik* t)
{
	if (t->a + t->b > t->c && t->a + t->c > t->b && t->b + t->c > t->a) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char** argv)
{
	int a;
	int b;
	int c;
	int pocet;
	std::cout << "Zadej pocet trojuhelniku: ";
	std::cin >> pocet;
	Trojuhelnik* pole = new Trojuhelnik[pocet];
	for (int i = 0; i < pocet; i++)
	{
		std::cout << "Nacten trojuhelnik " << i+1 << std::endl;
	}
	delete[] pole;
	Trojuhelnik trojuhel;
	Trojuhelnik* ukazatel = new Trojuhelnik();
	std::cout << "Zadej a: ";
	std::cin >> a;
	std::cout << "Zadej b: ";
	std::cin >> b;
	std::cout << "Zadej c: ";
	std::cin >> c;
	trojuhel.a = a;
	trojuhel.b = b;
	trojuhel.c = c;
	ukazatel->a = a;
	ukazatel->b = b;
	ukazatel->c = c;
	if (a + b > c && a + c > b && b + c > a) {
		int obvod;
		obvod = a + b + c;
		std::cout << "obvod: " << obvod << std::endl;
	}
	else {
		std::cout << "nelze sestrojit!" << std::endl;
	}

	if (lzeSestrojit(trojuhel)) {
		int obvod;
		obvod = trojuhel.a + trojuhel.b + trojuhel.c;
		std::cout << "obvod pomoci struct: " << obvod << std::endl;
	}
	else {
		std::cout << "nelze sestrojit pomoci struct!";
	}
	if (lzeSestrojit2(ukazatel)) {
		int obvod;
		obvod = ukazatel->a + ukazatel->b + ukazatel->c;
		std::cout << "obvod pomoci struct2: " << obvod << std::endl;
	}
	else {
		std::cout << "nelze sestrojit pomoci struct2!";
	}

	delete ukazatel;

}

