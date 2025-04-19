#include "Account.h"
#include <iostream>
#include <sstream>

using namespace std;

Account::Account(string u, string p, double b) : username(u), pin(p), money(b) {}

bool Account::checkPIN(string text) {
	return text == pin;
}

void Account::naptien(double tiennap) {
	money += tiennap;
	cout << "Nap tien thanh cong!" << endl;
}

void Account::ruttien(double tienrut) {
	if (tienrut <= money) {
		money -= tienrut;
		cout << "Da rut tien thanh cong!" << endl;
	}
	else {
		cout << "Tai khoan khong du!" << endl;
	}
}

void Account::doimaPIN(string pinmoi) {
	pin = pinmoi;
	cout << "Da doi ma PIN thanh cong!" << endl;
}

void Account::intaikhoan() {
	cout << "Tai khoan quy khach con lai: " << money << " VND" << endl;
}
string Account::toString() const{
	return username + " " + pin + " " + to_string(money);
}

void Account::fromString(string line) {
	std::stringstream ss(line);
	ss >> username >> pin >> money;
}

string Account::getUsername() {
	return username;
}
