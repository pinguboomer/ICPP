#include "Objekt.h"
#include "StatickyObjekt.h"
#include "PohyblivyObjekt.h"
#include "Hra.h"
#include <iostream>

int main(int argc, char** argv) {
	Objekt* objekt1 = new StatickyObjekt(3, TypPrekazky::Skala);
	objekt1->SetX(10);
	objekt1->SetY(20);
	StatickyObjekt* so1 = dynamic_cast<StatickyObjekt*>(objekt1);
	Objekt* objekt2 = new Objekt(4);
	objekt2->SetX(25);
	objekt2->SetY(28);
	Objekt* objekt3 = new StatickyObjekt(5, MalaRostlina);
	objekt3->SetX(30);
	objekt3->SetY(40);
	StatickyObjekt* so2 = dynamic_cast<StatickyObjekt*>(objekt3);
	Objekt* objekt4 = new PohyblivyObjekt(6);
	objekt4->SetX(10);
	objekt4->SetY(10);
	PohyblivyObjekt* po2 = dynamic_cast<PohyblivyObjekt*>(objekt4);
	Hra* hra = new Hra();
	hra->vlozObjekt(objekt1);
	hra->vlozObjekt(objekt2);
	hra->vlozObjekt(objekt3);
	hra->vlozObjekt(objekt4);
	int* pole = hra->najdiIdStatickychObjektu(0, 50, 0, 50);
	std::cout << "Id statickych objektu: ";
	for (int i = 0; i < sizeof(pole); i++)
	{
		std::cout << pole[i] << " ";
	}
	std::cout << std::endl;
	hra->najdiPohybliveObjektyVOblasti(5, 5, 50);

	std::cout << std::endl;
	Objekt* objekt = new StatickyObjekt{ 1, TypPrekazky::MalaRostlina };
	StatickyObjekt* so = dynamic_cast<StatickyObjekt*>(objekt);
	if (so != nullptr)
		std::cout << "objekt je StatickyObjekt(nebo jeho potomek) " << so->GetTypPrekazky();
	return 0;

}