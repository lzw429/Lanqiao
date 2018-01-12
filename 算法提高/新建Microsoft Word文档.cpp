#include <iostream>

using namespace std;
bool file[2018];

int newFile() {
    for (int i = 1; i != 2013; i++)
        if (!file[i]) {
            file[i] = true;
            return i;
        }
}

int main() {
    int n, fileNum = 0;
    cin >> n;
    for (int i = 0; i != n; i++) {
        string op;
        cin >> op;
        if (op == "New") {
            cout << newFile() << endl;
        } else if (op == "Delete") {
            int id;
            cin >> id;
            if (!file[id])
                cout << "Failed" << endl;
            else {
                file[id] = false;
                cout << "Successful" << endl;
            }
        }
    }
    return 0;
}

