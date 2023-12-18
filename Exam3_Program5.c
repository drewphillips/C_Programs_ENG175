//Copy/Pasted from D2L to zyBooks on 11/21/23 for grading.

#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


//read in a radius and height in int main(void)
//use one udf for Rectangular Solid:  calculate the surface area and volume, print in udf

   //Surface Area  2(length*width + length*height + width*height)
   //Volume: V = length*width*height

   double CalcRecSolid(double radius, double height) {
   double length;
   double width;
   double SurfaceArea;
   double Volume;
   length = radius * 2;
   width = radius * 2;
   SurfaceArea =  ((length * width + length * height + width * height) * 2);
   Volume = (length * width * height);

   printf(" The surfice area is %.2lf", SurfaceArea);
   printf(" The volume is : %.2lf", Volume);

    return 0; }


    //use one udf for cone:  calculate the volume print in int main(void), no pointers

   //Volume = 1/3* pi * r*r*h

   double CalcCone(double radius, double height) {
   double Volume;
   double ConeVoulme;
   Volume = 1.0/3.0 * (M_PI * radius * radius * height);

 
   printf(" The cone volume is : %.2lf", ConeVoulme );

    return ConeVoulme; }


int main()
{
   double radius;
   double height;
   int userSelection;

   printf("Program #5\n\n");
   printf("Dean Phillips\n");

   //read in a radius and height in int main(void)
   printf("read in a radius and height\n");
   scanf("%lf", &radius);
   scanf("%lf", &height);

   //create a menu to choose from pyramid, rectangular solid, cylinder and cone
   //for pyramid:  print "you chose pyramid" and no calculations

   printf("You have 4 menu options to chouse from, 1) pyramid, 2) rectangular solid, 3) cylinder and 4) cone:\n");
   scanf("%d", &userSelection);

   if (userSelection == 1) {
       printf ("you chose 1) pyramid\n");
   }

   else if (userSelection == 2) {
       CalcRecSolid(radius, height);
       
   }

   else if (userSelection == 3) {
       printf ("you chose 3) cylinder\n");
   }

   else if (userSelection == 4) {
       printf ("The volume of the cone is: %.2lf"), CalcCone(radius, height);
   }

   else {
       printf("You can onbbly selct 1-4, please try again");
   }






 /*
 Write a C program to ...

   
 
   use one udf for Rectangular Solid:  calculate the surface area and volume, print in udf
       Surface Area: A = 2(length*width + length*height + width*height)
       Volume: V = length*width*height
   for cylinder:  print "you chose cylinder" and no calculations
   use one udf for cone:  calculate the volume print in int main(void), no pointers
       Volume = 1/3* pi * r*r*h
   do not loop

*/

   return 0;
}

/*
PROGRAM #5

(1pts) read in a radius and height in int main(void)
(2pts) create a menu to choose from pyramid, sphere, cylinder and cone
(1pt)  for pyramid:  print "you chose pyramid" and no calculations
(-2 of 3pts) use one udf for Rectangular Solid and print in udf
    Surface Area: A = 2(length*width + length*height + width*height)
    Volume: V = length*width*height
(1pt)  for cylinder:  print "you chose cylinder" and no calculations
(-2 of 3pts) use one udf for cone:  calculate the volume and print in int main(void)
         no pointers
         Volume = 1/3* pi * r*r*h
do not loop

Test case: r = 6.5 h = 12.5
           Rect Solid SA = 148 with l=4  w=6  h=5  code prints 988.00 and 2112.50
                      Vol = 120
           Cone Vol = 553.05    code prints 0.00
*/