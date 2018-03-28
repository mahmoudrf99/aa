#include <iostream>

using namespace std;

int main ()
{

    double weight, radius, buoyant_force;
    cout << "Enter the weight in pounds :";
    cin >> weight;
    cout <<"Enter the radius in feet :";
    cin >> radius;
    // buoyant_force = volume * y
    buoyant_force = 62.4 *((4/3)*(3.14)*(radius*radius*radius)); ;
    cout <<"The buoyant_force is : "<< buoyant_force<<"\n0";

    if  (buoyant_force >= weight)
        cout <<"The sphere will float in water \n";
    else
        cout <<"The sphere will sink in water \n";



    return 0;
}
