/* Experiment 11: Symbol table operations. */
#include <stdio.h>
#include <string.h>

typedef struct { char label[32]; int address; } Symbol;
Symbol table[50];
int count = 0;

int search(const char *label) {
    for (int i = 0; i < count; i++)
        if (strcmp(table[i].label, label) == 0) return i;
    return -1;
}
void insert(void) {
    char label[32]; int address;
    printf("Enter label: "); scanf("%31s", label);
    if (search(label) >= 0) { puts("Duplicate symbol"); return; }
    if (count == 50) { puts("Symbol table is full"); return; }
    printf("Enter address: "); scanf("%d", &address);
    strcpy(table[count].label, label);
    table[count++].address = address;
}
void display(void) {
    puts("Label\tAddress");
    for (int i = 0; i < count; i++)
        printf("%s\t%d\n", table[i].label, table[i].address);
}
void modify(void) {
    char label[32]; int address;
    printf("Enter label: "); scanf("%31s", label);
    int index = search(label);
    if (index < 0) { puts("No such symbol"); return; }
    printf("Enter new address: "); scanf("%d", &address);
    table[index].address = address;
    puts("Address updated");
}
int main(void) {
    int choice;
    do {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Modify\n5.Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) return 1;
        if (choice == 1) insert();
        else if (choice == 2) display();
        else if (choice == 3) {
            char label[32]; printf("Enter label: "); scanf("%31s", label);
            puts(search(label) >= 0 ? "Label is found" : "Label is not found");
        } else if (choice == 4) modify();
    } while (choice != 5);
    return 0;
}
