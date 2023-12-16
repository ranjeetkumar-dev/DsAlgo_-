// #include <stdio.h>

// struct phone
// {
//     char name[20];
//     int ram;
//     int storage;
//     float display;
//     int price;
// };

// int main()
// {

//     struct phone p[2];

//     for (int i = 0; i < 2; i++)
//     {
//         printf("enter details of phone %d\n", i + 1);

//         printf("name:");
//         scanf("%s", &p[i].name);

//         printf("ram:");
//         scanf("%d", &p[i].ram);

//         printf("storage:");
//         scanf("%d", &p[i].storage);

//         printf("display:");
//         scanf("%f", &p[i].display);

//         printf("price:");
//         scanf("%d", &p[i].price);
//     }
//     printf("\n");

//     for (int i = 0; i < 2; i++)
//     {
//         printf("details of phone %d \n", i + 1);
//         printf("name:%s\n", p[i].name);
//         printf("ram:%d\n", p[i].ram);
//         printf("storage:%d\n", p[i].storage);
//         printf("display:%f\n", p[i].display);
//         printf("price:%d\n", p[i].price);
//     }

//     return 0;
// }



#include <stdio.h>


struct Phone {
    char brand[20];
    char model[20];
    int storage;
    float display_size;
    int battery_capacity;
};

int main() {
    
    struct Phone phones[5];

    // Fill data for each phone in the array
    for (int i = 0; i < 5; i++) {
        printf("Enter details for Phone %d:\n", i + 1);
        printf("Brand: ");
        scanf("%s", phones[i].brand);

        printf("Model: ");
        scanf("%s", phones[i].model);

        printf("Storage (in GB): ");
        scanf("%d", &phones[i].storage);

        printf("Display Size (in inches): ");
        scanf("%f", &phones[i].display_size);

        printf("Battery Capacity (in mAh): ");
        scanf("%d", &phones[i].battery_capacity);

        printf("\n");
    }

    // Display the data for each phone in the array
    printf("Phone Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("Phone %d:\n", i + 1);
        printf("Brand: %s\n", phones[i].brand);
        printf("Model: %s\n", phones[i].model);
        printf("Storage: %d GB\n", phones[i].storage);
        printf("Display Size: %.2f inches\n", phones[i].display_size);
        printf("Battery Capacity: %d mAh\n", phones[i].battery_capacity);
        printf("\n");
    }

    return 0;
}
