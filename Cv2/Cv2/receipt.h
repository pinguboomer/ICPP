#pragma once
#ifndef RECEIPT_H
#define RECEIPT_H

class Receipt {
private:
	int id;
	double cost;
	double dph;
public:
	void SetId(int id);
	int GetId() const;
	void SetCost(double cost);
	double GetCost() const;
	void SetDph(double dph);
	double GetDph() const;

};
#endif