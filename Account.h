#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;

class Account {
private:
	string username;
	string pin;
	double money;
public:
	Account(string u = "", string p = "", double m = 0);
	
	bool checkPIN(string text);
	void naptien(double tiennap);
	void ruttien(double tienrut);
	void doimaPIN(string pinmoi);
	void intaikhoan();
	string toString () const;
	void fromString(string line);
	string getUsername();
};
#endif