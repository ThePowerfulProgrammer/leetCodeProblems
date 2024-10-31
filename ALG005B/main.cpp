#include <iostream>

using namespace std;

class Main
{
    public:
        Main(int size, int x, int y); // ctor
        void generateBackGround();

    private:
        int sizeOfShape;
        int xCentre;
        int yCentre;
};

Main::Main(int size, int x, int y)
{
    if ((size>= 2 && size <=9) && (x >= 1 && x <= 79) && (y >= 1 &&  y <= 25) )
    {
        sizeOfShape = size;
        xCentre = x;
        yCentre = y;
    }
    else
    {
        return;
    }
}

void Main::generateBackGround()
{
    // (6,30,9)
    int left = xCentre - sizeOfShape + 1;
    int right = xCentre + sizeOfShape - 1;
    int top = yCentre - sizeOfShape + 1;
    int bottom = yCentre + sizeOfShape - 1;

        for (int i=1;i<=25;i++)
        {
            for (int j=1;j<=79;j++)
            {
                if (j == xCentre && i == yCentre)
                {
                    cout << "$"; // print centre
                }
                else if ((i == top || i == bottom) && j == xCentre)
                {
                    cout << "$"; // print topmost and bottommost
                }
                else if ((j == left || j == right) && i == yCentre)
                {
                    cout << "$"; // print leftmost and rightmost
                }
                else if (j%10 == 0)
                {
                    cout << j/10;
                }
                else if (i%10 == 0 && j == 1)
                {
                    cout << i/10;
                }
                else
                {
                    // alwayss sizeOfShape - 2
                    /* needs to be done sizeOfShape - 2 times for top and bottom diagonals */
                    bool printed = false;

                    for (int d=1;d<sizeOfShape;d++)
                    {


                      if ( (i == top+d && (j == xCentre + d || j == xCentre-d ) ||  (i==bottom-d && (j==xCentre-d || j == xCentre+d))   ))
                      {
                        cout << "$";
                        printed = true;
                        break;
                      }
                    }



                    if (!printed)
                    {
                      cout << "=";
                    }

                }
            }


            cout << endl;
        }
}

int main()
{

    Main main(6,30,9);
    main.generateBackGround();
}
