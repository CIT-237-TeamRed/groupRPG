// Daniel Richardson
// Nov. 8

/*        Benign           *
****************************
*   string characteristic  *
****************************
*      bool hostile        *
****************************
*       Benign()           *
*   virtual void setEnemy()*
*   virtual void print()   *
****************************/


#include <string>
#include "Benign.h"
#include <iostream>

using namespace std;

Benign::Benign(): Enemy() {
	setName("Benign");
	setCharacteristic(characteristic);
}

