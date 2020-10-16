#include"receipt.h"
#include"cashRegister.h"
#include <iostream>

int main(int argc, char** argv)
{
	/*Receipt receipt = Receipt();
	receipt.SetId(1001);
	receipt.GetId();

	const Receipt receipt2 = Receipt();
	receipt.GetId();*/

	CashRegister* cashRegister1 = new CashRegister();
	cashRegister1->createReceipt(100, 0.2);
	cashRegister1->createReceipt(200, 0.2);
	std::cout << cashRegister1->getCostAllReceipts() << std::endl;
	std::cout << cashRegister1->getCostWithDPHAllReceipts() << std::endl;
	return 0;
}