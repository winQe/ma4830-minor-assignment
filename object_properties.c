#include <stdio.h>
#include <string.h>

int getProperties(int n, int properties[])

int main()
{
    char objectType_input[20]; //declare a string to store object type input
    int objectDimension=-1;
    int objectType;


    /* Checks the validity of user input 
    IF the input is invalid use while loop to ask the user to input again
    THEN assign 
    */

    while (1) {
        printf("Select object dimension\n"
            "1. 2D\n"
            "2. 3D\n");
        scanf("%s", objectType_input); //ask user to input object type. Input can be in terms of index number i.e. 1,2 or dimension i.e 2D,3D
        
        if (strcasecmp(objectType_input, "2D") == 0 || strcmp(objectType_input, "1") == 0){ 
            objectDimension = 1; 
            break;
        }
        else if (strcasecmp(objectType_input, "3D") == 0 || strcmp(objectType_input, "2") == 0 ){
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
        }
        else if (objectDimension == 2) {
            printf("Select 3D object type\n"
            "1. Cube\n"
            "2. Cuboid\n"
            "3. Sphere\n" 
            "4. Cylinder\n" 
            "5. Square Pyramid\n" 
            "6. Triangular Pyramid\n");
        }
        else {
            printf("Error!!!");
            exit();
        }
    }
    switch
    
    
    //switch(objectType) {
    //    case 1



    //}

    printf("%d INPUT %s",objectDimension,objectType_input);

    return 0;
}