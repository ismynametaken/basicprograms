
//int function(int, int, int, int, int , int , int , int);

int function(int, int);
int gX = 5;
int gY;
int main(void)
{

int mX = 25;
int mY = 26;
int mZ = 27;

//mY = function(mX,mY, 1, 2, 3, 4, 5, 6);
mY = function(mX,mY);

gY = mZ*100;
}

//int function(int mX,int mY, int a1, int a2, int a3, int a4, int a5, int a6)
int function(int mX,int mY)
{
   int fnX = 0x50;
   int fnY = 0x51;
   fnY = mX*mY*gX*fnX;

   return(fnY);
   
}
