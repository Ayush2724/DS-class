#include <stdio.h>
#define MAX 100

int hash(int key)
{
    return key % 100;
}

// Linear Probing for collision resolution
void linearProbe(int table[], int index, int key)
{
    int i;

    // No collision
    if(table[index] == -1)
    {
        table[index] = key;
    }
    else
    {
        printf("Collision detected! Applying Linear Probing...\n");

        // Search forward
        for(i = index + 1; i < MAX; i++)
        {
            if(table[i] == -1)
            {
                table[i] = key;
                return;
            }
        }

        // Wrap around
        for(i = 0; i < index; i++)
        {
            if(table[i] == -1)
            {
                table[i] = key;
                return;
            }
        }

        printf("Hash table is full!\n");
        
    }
}

// Display hash table
void display(int table[])
{
    int i, x;

    printf("Do you want the filtered or unfiltered table? (1 = filtered, 0 = unfiltered): ");
    scanf("%d", &x);

    printf("\nFinal Hash Table (Index : Key)\n");

    for(i = 0; i < MAX; i++)
    {
        if(x == 1)   // FILTERED
        {
            if(table[i] != -1)
                printf("%d : %d\n", i, table[i]);
        }
        else if (x == 0)        // UNFILTERED
        {
            printf("%d : %d\n", i, table[i]);
        }
    }
}

int main()
{
    int table[MAX], key, index, choice, i;

    // Initialize hash table
    for(i = 0; i < MAX; i++)
        table[i] = -1;

    printf("Collision Handling using Linear Probing\n");

    do
    {
        printf("\nEnter 4-digit Employee ID: ");
        scanf("%d", &key);

        index = hash(key);
        linearProbe(table, index, key);

        printf("Do you want to insert another ID? (1/0): ");
        scanf("%d", &choice);

    } while(choice == 1);
    
    display(table);
    return 0;
}