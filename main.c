#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#if defined(_WIN32)
    #define PLATFORM_NAME "Windows" // Windows
#else
    #define PLATFORM_NAME "NULL"
#endif

void clear(){ //Clear terminal screen
    if (PLATFORM_NAME == "Windows"){
        system("cls");
    }
    else {
        system("clear");
    }
}
void font_red () { // function to change fontcolor to red
  printf("\033[1;31m");
}

void font_blue() { // function to change fontcolor to blue
  printf("\033[0;34m");
}

void font_reset () { // function to reset fontcolor
  printf("\033[0m");
}

int getProperties(int n, char properties[][20], float *result){ //universal function to prompt user for parameter input on any object
    float temp = -1;
    char dummy[1000];
    for(int i=0; i<n; i++){  
        while(1){ //type error handling  
            font_blue(); // change font color to blue
            printf("Input %s> ", properties[i]);
            font_reset();    
            scanf("%f", &(temp));
            if (temp>0){
                break;
            }
            else {
                printf("Please input a valid decimal number!\n");
                scanf("%s", dummy); // to clear the buffer
            }
        }
        *result = temp;
        result++;
    }
}

int main()
{   
    int backToMenu = -1;
    char objectDimension_input[20]; //declare a string to store object type input
    int objectDimension=-1; //store object dimension, initally -1 for error handling
    char objectType_input[20]; //store user input regarding object type
    int objectType=-1; //used for object type switch case, initally -1 for error handling
    char again[10]; //string to determine where to ask loop the program again or not
    while(1) {

        /* 
        Prompts user to input object dimension, either 2D or 3D 
        Checks the validity of user input 
        IF the input is invalid use while loop to ask the user to input again
        THEN assign user input to the proper variable to make it compatible for SWITCH CASE 
        */

        while (1) {
            clear();
            font_reset(); //reset textcolor
            printf("Select object dimension\n"
                "1. 2D\n"
                "2. 3D\n");
            scanf("%s", objectDimension_input); //ask user to input object type. Input can be in terms of index number i.e. 1,2 or dimension i.e 2D,3D
            
            if (strcasecmp(objectDimension_input, "2D") == 0 || strcmp(objectDimension_input, "1") == 0){ 
                objectDimension = 1; 
                break;
            }
            else if (strcasecmp(objectDimension_input, "3D") == 0 || strcmp(objectDimension_input, "2") == 0 ){
                objectDimension = 2;
                break;
            }
            else {
                font_red(); //change font color to red
                printf("Error!!! Please retype a proper input \n");
                font_reset();
                sleep(2);
            }
        }
        
        while(1){
            clear();
            font_reset();

            if (objectDimension == 1) {
                printf("Select 2D object type\n"
                "1. Rectangle\n"
                "2. Square\n"
                "3. Circle\n"
                "4. RightTriangle\n"
                "5. Go Back to Main Menu\n");

                scanf("%s",objectType_input); //prompt user for object type
            
            //Assign user input to a variable which will be used in switch case
                if (strcasecmp(objectType_input, "Rectangle") == 0 || strcmp(objectType_input, "1") == 0){
                    objectType = 1; 
                    break;
                }
                else if (strcasecmp(objectType_input, "Square") == 0 || strcmp(objectType_input, "2") == 0 ){
                    objectType = 2;
                    break;
                }
                else if (strcasecmp(objectType_input, "Circle") == 0 || strcmp(objectType_input, "3") == 0 ){
                    objectType = 3;
                    break;
                }
                else if (strcasecmp(objectType_input, "RightTriangle") == 0 || strcmp(objectType_input, "4") == 0 ){
                    objectType = 4;
                    break;
                }
                else if (strcasecmp(objectType_input, "menu") == 0 || strcmp(objectType_input, "5") == 0 ){
                    backToMenu = 1;
                    break;
                }           
                else {
                    font_red();
                    printf("Error!!! Please retype a proper input \n");
                    font_reset();
                    sleep(2);
                }
            }
            else if (objectDimension == 2) {
                clear();
                printf("Select 3D object type\n"
                "1. Cube\n"
                "2. Cuboid\n"
                "3. Sphere\n" 
                "4. Cylinder\n" 
                "5. SquarePyramid\n" 
                "6. Cone\n"
                "7. Back to Main Menu\n");

                scanf("%s",objectType_input);

                if (strcasecmp(objectType_input, "Cube") == 0 || strcmp(objectType_input, "1") == 0){ 
                    objectType = 101; 
                    break;
                }
                else if (strcasecmp(objectType_input, "Cuboid") == 0 || strcmp(objectType_input, "2") == 0 ){
                    objectType  = 102;
                    break;
                }
                else if (strcasecmp(objectType_input, "Sphere") == 0 || strcmp(objectType_input, "3") == 0 ){
                    objectType  = 103;
                    break;
                }
                else if (strcasecmp(objectType_input, "Cylinder") == 0 || strcmp(objectType_input, "4") == 0 ){
                    objectType  = 104;
                    break;
                }
                else if (strcasecmp(objectType_input, "SquarePyramid") == 0 || strcmp(objectType_input, "5") == 0 ){
                    objectType  = 105;
                    break;
                }
                else if (strcasecmp(objectType_input, "Cone") == 0 || strcmp(objectType_input, "6") == 0 ){
                    objectType  = 106;
                    break;
                }
                else if (strcasecmp(objectType_input, "menu") == 0 || strcmp(objectType_input, "7") == 0 ){
                    backToMenu = 1;
                    break;
                }
                else {
                    font_red();
                    printf("Error!!! Please retype a proper input \n");
                    font_reset();
                    sleep(2);
                }
            }
            else {
                font_red();
                printf("Error!!!");
                font_reset();
                exit(1);
            }
        }
        if (backToMenu != -1) { //Go back to main menu
            backToMenu = -1;
            continue;
        }
        clear();
        switch(objectType)
            {
            case 1:; //Rectangle properties
                char properties1[2][20] = {"Length","Height"}; 
                float result1[] = {0};
                getProperties(2,properties1, result1); //prompt user for properties specified in the array
                printf("Perimeter : %.2f\n",2*result1[0]+2*result1[1]); //perimeter = 2*(length+height)
                printf("Area : %.2f\n",result1[0]*result1[1]); //area = length*height
                break;
            case 2:; //Square properties
                char properties2[1][20] = {"Side Length"}; 
                float result2[] = {0};
                getProperties(1,properties2, result2);
                printf("Perimeter : %.2f\n",4*result2[0]); //perimeter = 4*length
                printf("Area : %.2f\n",pow(result2[0],2)); // area = length^2
                break;
            case 3:; //Circle properties
                char properties3[1][20] = {"Radius"}; 
                float result3[] = {0};
                getProperties(1,properties3, result3);
                printf("Perimeter : %.2f\n",2*M_PI*result3[0]); //perimeter = 2*pi*r
                printf("Area : %.2f\n",M_PI*pow(result3[0],2)); // area = pi*r^2
                break;
            case 4:; //RightTriangle properties
                char properties4[2][20] = {"Base Length","Height"}; 
                float result4[] = {0};
                getProperties(2,properties4, result4);
                float hypotenuse = sqrt(pow(result4[0],2)+pow(result4[1],2));
                printf("Hypotenuse : %.2f\n",hypotenuse); //hypotenuse = sqrt(length^2 + height^2)
                printf("Perimeter : %.2f\n",result4[0]+result4[1]+hypotenuse); // perimeter = base length+ height + hypotenuse
                printf("Area : %.2f\n",result4[0]*result4[1]/2); // area = base length * height / 2
                break;
            case 101:;//Cube properties
                char properties101[1][20] = {"Side Length"};
                float result101[] = {0};
                getProperties(1, properties101, result101);
                printf("Base Area: %.2f\n", pow(result101[0],2)); // base area = length^2
                printf("Surface Area: %.2f\n", 6*pow(result101[0],2)); // surface area = 6 * base area
                printf("Volume: %.2f\n", pow(result101[0], 3));// volume = length^3
                break;
            case 102:; //Blocks/cuboid properties
                char properties102[3][20] = {"Length","Width","Height"};
                float result102[] = {0};
                getProperties(3, properties102, result102);
                //surface area = 2* length * width + 2 * length * height + 2 * width * height
                printf("Surface Area: %.2f\n", 2*result102[0]*result102[1]+2*result102[0]*result102[2]+2*result102[1]*result102[2]);
                printf("Volume: %.2f\n", result102[0]*result102[1]*result102[2]); //volume = length * height * width
                break;
            case 103:; //Sphere properties
                char properties103[1][20] = {"Radius"};
                float result103[] = {0};
                getProperties(1, properties103, result103);
                printf("Surface Area: %.2f\n", 4*M_PI*pow(result103[0],2)); //surface area = 4*pi*r^2
                printf("Volume: %.2f\n", 4*M_PI*pow(result103[0],3)/3); // volume = 4/3* pi * r^3
                break;
            case 104:; //Cylinder
                char properties104[2][20] = {"Radius","Height"};
                float result104[] = {0};
                getProperties(2, properties104, result104);
                float base_area4 = M_PI*pow(result104[0],2);
                float lateral_area4 = 2*M_PI*result104[0]*result104[1];
                printf("Base Area: %.2f\n", base_area4); // base area = pi*r^2
                printf("Lateral Surface Area: %.2f\n", lateral_area4); //lateral area = 2 * pi * radius * height
                printf("Surface Area: %.2f\n",2*base_area4+lateral_area4); //surface area = 2*base area + lateral area
                printf("Volume: %.2f\n",base_area4*result104[1]); // volume = base area * height
                break;        
            case 105:;//Square Pyramid properties
                char properties105[2][20] = {"Side Length","Height"};
                float result105[] = {0};
                getProperties(2, properties105, result105);
                float base_area5 = pow(result105[0],2);
                float lateral_area5 = result105[0]*sqrt(pow(result105[0],2)+4*pow(result105[1],2));
                printf("Base Area: %.2f\n", base_area5); //base area = length^2
                printf("Lateral Surface Area: %.2f\n", lateral_area5);// lateral surface area = length * sqrt(length^2+4*height^2)
                printf("Surface Area: %.2f\n",base_area5+lateral_area5); // surface area = base area + lateral area
                printf("Volume: %.2f\n",base_area5*result105[1]/3); //volume = 1/3 * base area * height
                break;
            case 106:;// Cone properties
                char properties106[2][20] = {"Radius","Height"};
                float result106[] = {0};
                getProperties(2, properties106, result106);
                float slant=sqrt(pow(result106[0],2)+pow(result106[1],2));
                float base_area6 = M_PI*pow(result106[0],2);
                float lateral_area6 =M_PI*result106[0]*slant;
                printf("Slant Height: %.2f\n",slant); //slant height = sqrt(radius^2 + height^2)
                printf("Base Area: %.2f\n",base_area6); // base area = pi*r^2
                printf("Lateral Surface Area: %.2f\n",lateral_area6); //lateral area = pi * radius * slant
                printf("Surface Area: %.2f\n", base_area6+lateral_area6); // surface area = base area + lateral area
                printf("Volume: %.2f\n", base_area6*result106[1]/3); //volume = 1/3 * base area * height
                break;  
            default:
                font_red();
                printf("Error, invalid object type!");
                font_reset();
                exit(1);
        }
    reinput: //Ask user whether to exit or loop the program again
        font_blue();
        printf("\nWould you like to calculate another object? (Y/N)");
        font_reset();
        scanf("%s",again);
        if (strcasecmp(again,"No") == 0 || strcasecmp(again,"N") == 0 || strcasecmp(again,"0") == 0) {
            break;
            }
        else if(strcasecmp(again,"Yes") == 0 || strcasecmp(again,"y") == 0 || strcasecmp(again,"1") == 0) {
            continue;
            }
        else{ //error handling
            font_red();
            printf("Invalid input, please type in (Y)es/(N)o! \n");
            font_reset();
            sleep(2);
            clear();
            goto reinput;
            }
    }
    return 0;
}
