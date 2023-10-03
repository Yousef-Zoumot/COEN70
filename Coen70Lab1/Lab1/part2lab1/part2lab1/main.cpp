//
//  main.cpp
//  part2lab1
//
//  Created by Yousef Zoumot on 1/5/16.
//  Copyright (c) 2016 Yousef Zoumot. All rights reserved.
//

/* Lab1B.cpp */
/*#include <iostream>
using namespace std;
int main() {
    int score[10];
    for (int i=0; i < 10; i++) {
        score[i]=3*i;
        cout << score[i];
    }
    return 0;
}*/

/*Lab1C.cpp*/
#include <iostream>
using namespace std;
const double PI = 3.14159265359;
void GetRadius(double&);
void ShowResults(double, double, double);
int main() {
    cout << "Program computes surface area and "
    << "volume of a sphere.\n";
    double radius, // radius of sphere
    surfaceArea = 0, // its surface area
    volume = 0; // its volume
    GetRadius(radius);
    surfaceArea = 4.0 * PI * radius * radius;
    volume = surfaceArea * radius / 3.0;
    ShowResults(radius, surfaceArea, volume);
    return 0;
}
void GetRadius(double& rad) {
    cout << "Enter radius of sphere: ";
    cin >> rad;
}
void ShowResults(double rad, double area, double vol) {
    cout << "Radius of sphere is " << rad << " inches\n";
    cout << "Its surface area is " << area
    << "sq. inches\n" << "Its volume is " << vol
    << " cubic inches.\n\n";
}


