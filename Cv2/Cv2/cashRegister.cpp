#include "cashRegister.h"
#include "receipt.h"
#include <exception>

int CashRegister::idCounter = 1000;


CashRegister::CashRegister()
{
	//CashRegister* cashRegister = new CashRegister[10];
	receipts = new Receipt[10];
	receiptCounter = 0;
}

CashRegister::~CashRegister()
{
	//delete[]
}

Receipt& CashRegister::createReceipt(double cost, double dph)
{
	if (receiptCounter == 10) {
		throw new std::exception("CashRegister is full.");
	}

	receipts[receiptCounter].SetId(idCounter);
	receipts[receiptCounter].SetCost(cost);
	receipts[receiptCounter].SetDph(dph);
	int idReceipt = receiptCounter;
	idCounter++;
	receiptCounter++;
	return receipts[idReceipt];
}

Receipt& CashRegister::getReceipt(int id)
{
	for (int i = 0; i < sizeof(receipts); i++)
	{
		if (receipts[i].GetId() == id) {
			return receipts[i];
		}
	}
	return receipts[0];
}

double CashRegister::getCostAllReceipts() const
{
	double sum = 0;
	for (int i = 0; i < receiptCounter; i++)
	{
		sum += receipts[i].GetCost();
	}
	return sum;
}

double CashRegister::getCostWithDPHAllReceipts() const
{
	double sum = 0;
	for (int i = 0; i < receiptCounter; i++)
	{
		sum += receipts[i].GetCost() * (1 + receipts[i].GetDph());
	}
	return sum;
}
