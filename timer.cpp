/* time example */
#include <iostream>      
#include <ctime>       /* time_t, struct tm, difftime, time, mktime */
using namespace std;
int main ()
{

  time_t timer;
  struct tm y2k = {0};
  double seconds;

  y2k.tm_hour = 12;   y2k.tm_min = 0; y2k.tm_sec = 0;
  y2k.tm_year = 120; y2k.tm_mon = 5; y2k.tm_mday = 12;




  cout << "Rand Max = " << RAND_MAX << endl;

 for(int i : {1,2,3,4,5,6,7,8,9,10})
 {

    srand((unsigned int)(time(NULL)));
  cout << rand() << endl;
  timer = time(NULL);  /* get current time; same as: timer = time(NULL)  */
  seconds = difftime(timer,mktime(&y2k));
  cout << "Seconds since June 12 , 2020 in the current timezone:  " << seconds << endl;
 }
  return 0;
}
