#include <iostream>
#include <vector>
#include <regex>

using namespace std;

struct Person {

    Person() {
        firstName = "";
        lastName = "";
        phone = "";
    }

    string firstName, lastName, phone;
};

bool comparePeople(const Person &p1, const Person &p2) {
    if (p1.lastName != p2.lastName) {
        return p1.lastName < p2.lastName;
    }
    return p1.firstName < p2.firstName;
}

int main() {
    cin.sync_with_stdio(false);
    int elements;
    int i = 0;
    cin >> elements;
    string temp;
    vector<Person> people(elements, Person());
    while (i < elements) {
        cin >> temp;
        if (people[i].firstName == "") {
            people[i].firstName = temp;
        } else if (people[i].lastName == "") {
            people[i].lastName = temp;
        } else {
            people[i].phone = temp;
            i++;
        }
    }
    sort(people.begin(), people.end(),  [](Person a, Person b) { return comparePeople(a, b); });
    for (auto p: people) {
        cout << p.firstName << ' ' << p.lastName << ' ' << p.phone << '\n';
    }
}
