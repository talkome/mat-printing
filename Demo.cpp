/**
 * Demo program for mat exercise.
 * 
 * Author: Tal Zichlinsky
 * Since : 2022-01
 */

#include "mat.hpp"

using namespace std;


int main() {

//    cout << "case 1." << ariel::mat(11, 7, '@', '-') << endl;
///**
//     case 1.
//        @@@@@@@@@@@
//        @---------@
//        @-@@@@@@@-@
//        @-@@----@-@
//        @-@@@@@@@-@
//        @---------@
//        @@@@@@@@@@@
//*/
//
//    cout << "case 2." << ariel::mat(11, 3, 'V', 'X') << endl;
//
//    cout << "case 3." << ariel::mat(11, 5, 'a', 'A') << endl;
//
//    cout << "case 4." << ariel::mat(13, 13, '1', '3') << endl;
//
//    cout << "case 5." << ariel::mat(5, 5, '5', '5') << endl;
//
//    cout << "case 6." << ariel::mat(5, 7, 'X', 'V') << endl;
//
//    cout << "case 7." << ariel::mat(11, 11, '*', ' ') << endl;
//
//    cout << "case 8." << ariel::mat(11, 13, 'R', '-') << endl;
//
//    cout << "case 9." << ariel::mat(23, 3, '>', '<') << endl;
//
//    cout << "case 10." << ariel::mat(21, 1, '|', '&') << endl;

	cout << ariel::mat(9, 7, '@', '-') << endl;
/* Should print:
                    @@@@@@@@@
                    @-------@
                    @-@@@@@-@
                    @-@---@-@
                    @-@@@@@-@
                    @-------@
                    @@@@@@@@@
*/
	cout << ariel::mat(13, 5, '@', '-') << endl;
/* Should print:
                    @@@@@@@@@@@@@
                    @-----------@
                    @-@@@@@@@@@-@
                    @-----------@
                    @@@@@@@@@@@@@
*/
	try {
		cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
	}
}
