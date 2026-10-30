#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Function to display a set
void display(set<int> s) {
    if (s.empty()) {
        cout << "No members found.";
        return;
    }
    for (int id : s) {
        cout << id << " ";
    }
    cout << endl;
}

// Function for Union
set<int> findUnion(set<int> A, set<int> B) {
    set<int> result;

    set_union(A.begin(), A.end(),
              B.begin(), B.end(),
              inserter(result, result.begin()));

    return result;
}

// Function for Intersection
set<int> findIntersection(set<int> A, set<int> B) {
    set<int> result;

    set_intersection(A.begin(), A.end(),
                     B.begin(), B.end(),
                     inserter(result, result.begin()));

    return result;
}

// Function for Difference
set<int> findDifference(set<int> A, set<int> B) {
    set<int> result;

    set_difference(A.begin(), A.end(),
                   B.begin(), B.end(),
                   inserter(result, result.begin()));

    return result;
}

int main() {

    set<int> fiction;
    set<int> nonFiction;
    set<int> research;

    int n, id;

    cout << "=============================================\n";
    cout << "   LIBRARY BOOK BORROWING MANAGEMENT SYSTEM\n";
    cout << "=============================================\n\n";

    // Fiction
    cout << "Enter number of members who borrowed Fiction books: ";
    cin >> n;

    cout << "Enter Member IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> id;
        fiction.insert(id);
    }

    // Non-Fiction
    cout << "\nEnter number of members who borrowed Non-Fiction books: ";
    cin >> n;

    cout << "Enter Member IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> id;
        nonFiction.insert(id);
    }

    // Research Papers
    cout << "\nEnter number of members who borrowed Research Papers: ";
    cin >> n;

    cout << "Enter Member IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> id;
        research.insert(id);
    }

    int choice;

    do {

        cout << "\n\n========== LIBRARY ANALYSIS MENU ==========\n";
        cout << "1. Display all borrowing records\n";
        cout << "2. Fiction UNION Non-Fiction\n";
        cout << "3. Fiction INTERSECTION Non-Fiction\n";
        cout << "4. Fiction DIFFERENCE Non-Fiction\n";
        cout << "5. Fiction INTERSECTION Research\n";
        cout << "6. Non-Fiction INTERSECTION Research\n";
        cout << "7. Members borrowing from ALL THREE categories\n";
        cout << "8. All unique members\n";
        cout << "9. Exit\n";
        cout << "===========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "\nFiction Borrowers: ";
                display(fiction);

                cout << "Non-Fiction Borrowers: ";
                display(nonFiction);

                cout << "Research Paper Borrowers: ";
                display(research);
                break;

            case 2:
                cout << "\nMembers who borrowed Fiction OR Non-Fiction:\n";
                display(findUnion(fiction, nonFiction));
                break;

            case 3:
                cout << "\nMembers who borrowed BOTH Fiction AND Non-Fiction:\n";
                display(findIntersection(fiction, nonFiction));
                break;

            case 4:
                cout << "\nMembers who borrowed Fiction but NOT Non-Fiction:\n";
                display(findDifference(fiction, nonFiction));
                break;

            case 5:
                cout << "\nMembers who borrowed BOTH Fiction AND Research Papers:\n";
                display(findIntersection(fiction, research));
                break;

            case 6:
                cout << "\nMembers who borrowed BOTH Non-Fiction AND Research Papers:\n";
                display(findIntersection(nonFiction, research));
                break;

            case 7: {
                set<int> temp;

                temp = findIntersection(fiction, nonFiction);

                cout << "\nMembers who borrowed ALL THREE categories:\n";
                display(findIntersection(temp, research));

                break;
            }

            case 8: {
                set<int> temp;

                temp = findUnion(fiction, nonFiction);
                temp = findUnion(temp, research);

                cout << "\nAll unique library members:\n";
                display(temp);

                break;
            }

            case 9:
                cout << "\nThank you for using the Library System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}
