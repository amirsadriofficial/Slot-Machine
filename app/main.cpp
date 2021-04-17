#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <time.h>

using namespace std;
/*--------------------------------------------------------------------------*/
int Random(int,int);
/*--------------------------------------------------------------------------*/
int main()
{
  srand(time(0));
  int rand1{},rand2{},rand3{};
  int option,bet{},chips{1000};

  do
  {
    cout << "Player's chips: $" << chips << endl;
    cout << "1) Play slot.     2) Exit. ";
    cin >> option;

    switch (option)
    {
      case 1:
      {
          while (true)
          {
            cout << "Enter your bet :";
            cin >> bet;
            if (bet > chips || bet <= 0)
            cout << "You did not enter a valid bet." << endl;
            else
            break;
          }
          rand1 = Random(2, 7);
          rand2 = Random(2, 7);
          rand3 = Random(2, 7);
          bool x10 = rand1 == 7 && rand2 == 7 && rand3 == 7;
          bool x5  = !seven && (rand1 == rand2 && rand1 == rand3 && rand2 == rand3);
          bool x3  = (rand1 == rand2) || (rand1 == rand3) || (rand2 == rand3);

          cout << rand1 << " " << rand2 << " " << rand3 << endl;

          if (x10)
          {
            chips += bet * 10;
            cout << "You win!" << endl;
          }
          else if (x5)
          {
            chips += bet * 5;
            cout << "You win!" << endl;
          }
          else if (x3)
          {
            chips += bet * 3;
            cout << "You win" << endl;
          }
          else
          chips -= bet;

        }
        break;

      case 2:
        cout << "Exiting..." << endl;
        break;
    }

    if (chips <= 0)
    break;
  }
  while (option != 2);
  if (chips <= 0) {
    cout << "You lost all your points" << endl;
  }
  return 0;
}
/*--------------------------------------------------------------------------*/
int Random(int low, int high)
{
  int random = low + rand() % ((high + 1) - low);
  return random;
}
