#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Calculation {
    double a, b, result;
    char op;
};

int main() {
    vector<Calculation> history;
    int choice;

    while (true) {
        cout << "\n===== Calculator =====\n";
        cout << "1. Add  2. Subtract  3. Multiply  4. Divide  5. History  6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting...\n";
            break;
        }

        if (choice == 5) {
            for (int i = 0; i < history.size(); i++) {
                cout << i + 1 << ". "
                     << fixed << setprecision(2)
                     << history[i].a << " "
                     << history[i].op << " "
                     << history[i].b << " = "
                     << history[i].result << endl;
            }
            continue;
        }

        double a, b, result;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        switch (choice) {
            case 1:
                result = a + b;
                cout << "Result: " << fixed << setprecision(2) << result << endl;
                history.push_back({a, b, result, '+'});
                break;

            case 2:
                result = a - b;
                cout << "Result: " << fixed << setprecision(2) << result << endl;
                history.push_back({a, b, result, '-'});
                break;

            case 3:
                result = a * b;
                cout << "Result: " << fixed << setprecision(2) << result << endl;
                history.push_back({a, b, result, '*'});
                break;

            case 4:
                if (b == 0) {
                    cout << "Cannot divide by zero.\n";
                } else {
                    result = a / b;
                    cout << "Result: " << fixed << setprecision(2) << result << endl;
                    history.push_back({a, b, result, '/'});
                }
                break;

            default:
                cout << "Invalid choice.\n";
        }

        // Keep only last 10 calculations
        if (history.size() > 10) {
            history.erase(history.begin());
        }
    }

    return 0;
}
