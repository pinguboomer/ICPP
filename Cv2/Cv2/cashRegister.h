#pragma once
#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include"receipt.h"

class CashRegister
{
	static int idCounter;
	Receipt* receipts;
public:
	CashRegister();
	~CashRegister(); // destruktor
	int receiptCounter;
	Receipt& createReceipt(double cost, double dph);
	Receipt& getReceipt(int id);
	double getCostAllReceipts() const;
	double getCostWithDPHAllReceipts() const;
private:
};
#endif // !CASH_REGISTER_H
