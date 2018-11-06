/*        Benign           *
****************************
*  string subEnemiesArray  *
****************************
*   void setSubEnemy       *
****************************/


#include <string>
#include "Thief.h"
#include "Benign.h"
#include <iostream>
#include <ctime>

using namespace std;

void Benign::setSubEnemy()                     // will need to return an object
{
	int useElement = randomize(0, 100);

	(useElement % 2 == 0 ? arr[0] : arr[1]);
}