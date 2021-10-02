#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int getProperties(int n, char properties[][20], float *result){
    float temp = -1;
    char dummy[1000];
    for(int i=0; i<n; i++){  
        
        while(1){    
            printf("Input %s> ", properties[i]);    
            scanf("%f", &(temp));
            if (temp>0){
                break;
            }
            else {
                printf("Please input a valid decimal number!\n");
                scanf("%s", dummy);
            }
        }
        *result = temp;
        result++;
    }
}

int main()
{
    char objectDimension_input[20]; //declare a string to store object type input
    int objectDimension=-1;
    char objectType_input[20];
    int objectType;


    /* 
    Prompts user to input object dimension, either 2D or 3D 
    Checks the validity of user input 
    IF the input is invalid use while loop to ask the user to input again
    THEN assign user input to the proper variable to make it compatible for SWITCH CASE 
    */

    while (1) {
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
            (printf("Error!!! Please retype a proper input \n"));
        }
    }
    
    while(1){
        if (objectDimension == 1) {
            printf("Select 2D object type\n"
            "1. Rectangle\n"
            "2. Square\n"
            "3. Circle\n"
            "4. Triangle\n");

        scanf("%s",objectType_input);

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
        else if (strcasecmp(objectType_input, "Triangle") == 0 || strcmp(objectType_input, "4") == 0 ){
            objectType = 4;
            break;
        }        
        else {
            (printf("Error!!! Please retype a proper input \n"));
        }

        }
        else if (objectDimension == 2) {
            printf("Select 3D object type\n"
            "1. Cube\n"
            "2. Cuboid\n"
            "3. Sphere\n" 
            "4. Cylinder\n" 
            "5. SquarePyramid\n" 
            "6. TriangularPyramid\n");

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
            else if (strcasecmp(objectType_input, "TriangularPyramid") == 0 || strcmp(objectType_input, "6") == 0 ){
                objectType  = 106;
            break;
            }
            else {
                printf("Error!!! Please retype a proper input \n");
            }
        }
        else {
            printf("Error!!!");
            exit(1);
        }
    }
    // printf("%d", objectType);
    switch(objectType)
        {
        case 1:;
            break;
        case 2:;
            char properties1[1][20] = {"Side Length"};
            float result1[] = {0};
            getProperties(1,properties1, result1);
            printf("Perimeter : %.2f\n",4*result1[0]);
            printf("Area : %.2f",pow(result1[0],2));
            break;
        case 3:;
            break;
        case 4:;
            break;
        case 101:;
            char properties101[1][20] = {"Side Length"};
            float result101[] = {0};
            getProperties(1, properties101, result101);
            printf("Volume: %.2f\n", pow(result101[0], 3));
            printf("Surface Area: %.2f\n", 6*pow(result101[0],2));
            break;
        case 102:;
            break;
        case 103:;
            break;
        case 104:;
            break;
        case 105:;
            break;
        case 106:;
            break;
        
        default:
            printf("Error, invalid object type!");
            exit(1);
    }



    // printf("%d INPUT %s",objectDimension,objectType_input);

    return 0;
}