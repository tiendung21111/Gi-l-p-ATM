#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Account.h"
using namespace std;

vector<Account> loadAccounts(const string& filename) {
    ifstream file(filename);
    vector<Account> accs;
    string line;
    while (getline(file, line)) {
        Account a;
        a.fromString(line);
        accs.push_back(a);
    }
    return accs;
}

void saveAccounts(const string& filename, const vector<Account>& accounts) {
    ofstream file(filename);
    for (const auto& acc : accounts) {
        file << acc.toString() << endl;
    }
}

Account* findAccount(vector<Account>& accounts, const string& username) {
    for (auto& acc : accounts)
        if (acc.getUsername() == username)
            return &acc;
    return nullptr;
}

int main() {
	vector<Account> accounts = loadAccounts("atm_data.txt");
    string username, pin;
    cout << "====== DANG NHAP ATM ======\n";
    cout << "Ten dang nhap: ";
    cin >> username;
    cout << "Ma PIN: ";
    cin >> pin;

    Account* user = findAccount(accounts, username);

    if (user == nullptr || !user->checkPIN(pin)) {
        cout << "Sai ten dang nhap hoac ma PIN!\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n======= MENU ATM =======\n";
        cout << "1. Xem so du\n";
        cout << "2. Rut tienn\n";
        cout << "3. Nap tien\n";
        cout << "4. Doi ma PIN\n";
        cout << "5. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        switch (choice) {
        case 1:
            user->intaikhoan();
            break;
        case 2: {
            double amt;
            cout << "Nhap so tien muon rut: ";
            cin >> amt;
            user->ruttien(amt);
            break;
        }
        case 3: {
            double amt;
            cout << "Nhap so tien muon nap: ";
            cin >> amt;
            user->naptien(amt);
            break;
        }
        case 4: {
            string newPin;
            cout << "Nhap ma PIN moi: ";
            cin >> newPin;
            user->doimaPIN(newPin);
            break;
        }
        case 5:
            cout << "Dang thoat và luu du lieu...\n";
            break;
        default:
            cout << "❌ Lua chon khong hop le!\n";
        }

    } while (choice != 5);

    saveAccounts("atm_data.txt", accounts);
    cout << "✅ Da luu thanh cong. Tam biet!\n";
    return 0;
}


