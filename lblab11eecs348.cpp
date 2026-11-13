
#include <iostream>
#include <vector>
using namespace std;

bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    // Loop starts at index 1 instead of index 0, this skips the first attendance record
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += attendance_records[i] == 0;
    }
    return absent_count >= 3;
}

int main() {

    /*
    Q1: There is a fault in the program.
    The loop starts at index 1 instead of index 0, meaning it skips the first
    attendance record which will undercount absences and return a potentially wrong result.

    Q2:
    Input: {1}
    Expected output: false, actual output: false.
    The vector only contains one element, so the loop condition is immediately
    false and the loop body never executes.
    */

    vector<int> test1 = {1};
    int expected1 = 0;
    int actual1 = 0;

    cout << boolalpha;
    cout << "Test 1 attendance record: ";
    for (int i = 0; i < test1.size(); ++i) cout << test1[i] << " ";
    cout << "\nExpected absence count: " << expected1;
    cout << "\nActual absence count: " << actual1;
    cout << "\nExpected output: false";
    cout << "\nActual output: " << fail_lecture(test1) << endl;

    /*
    Q3:
    Input: {1,1,1,1,1,1,1,1,1,1}
    Expected output: false, actual output: false.
    The loop executes, but skipping the first record does not change the
    absence count because every student is present. The internal state is correct.
    */

    vector<int> test2 = {1,1,1,1,1,1,1,1,1,1};
    int expected2 = 0;
    int actual2 = 0;

    cout << "\nTest 2 attendance record: ";
    for (int i = 0; i < test2.size(); ++i) cout << test2[i] << " ";
    cout << "\nExpected absence count: " << expected2;
    cout << "\nActual absence count: " << actual2;
    cout << "\nExpected output: false";
    cout << "\nActual output: " << fail_lecture(test2) << endl;


    /*Q4:
    Input: {0,1,1,1,1,1,1,1,1,1}
    Expected output: false, actual output: false.
    The first student is absent, but the loop skips that record. The absence
    counter is incorrect, however the returned result is still false because
    fewer than three students are absent.
    */

    vector<int> test3 = {0,1,1,1,1,1,1,1,1,1};
    int expected3 = 1;
    int actual3 = 0;

    cout << "\nTest 3 attendance record: ";
    for (int i = 0; i < test3.size(); ++i) cout << test3[i] << " ";
    cout << "\nExpected absence count: " << expected3;
    cout << "\nActual absence count: " << actual3;
    cout << "\nExpected output: false";
    cout << "\nActual output: " << fail_lecture(test3) << endl;


    /*Q5:
    Input: {0,0,0,1,1,1,1,1,1,1}
    Expected output: true, actual output: false.
    Three students are absent, so the function should return true, but the
    first student is skipped by the loop so it only counts two absences,
    which returns an incorrect output.
    */

    vector<int> test4 = {0,0,0,1,1,1,1,1,1,1};
    int expected4 = 3;
    int actual4 = 2;

    cout << "\nTest 4 attendance record: ";
    for (int i = 0; i < test4.size(); ++i) cout << test4[i] << " ";
    cout << "\nExpected absence count: " << expected4;
    cout << "\nActual absence count: " << actual4;
    cout << "\nExpected output: true";
    cout << "\nActual output: " << fail_lecture(test4) << endl;

    return 0;
}
