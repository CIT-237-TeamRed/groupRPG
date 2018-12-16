// Daniel Richardson

/*        Vicious          *
****************************
*   string characteristic  *
****************************
*      bool hostile        *
****************************
*       Vicious()          *
*   virtual void setEnemy()*
*   virtual void print()   *
****************************/

#include <iostream>
#include "Vicious.h"   // this whole cpp may not be necessary


using namespace std;

Vicious::Vicious()
{
	setCharacteristic(characteristic);
}
