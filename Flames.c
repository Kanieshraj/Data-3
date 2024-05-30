#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeCharAtIndex(char *str, int index) {
    memmove(str + index, str + index + 1, strlen(str) - index);
}
void removeCommonChars(char *str1, char *str2) {
    for (int i = 0; i < strlen(str1); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (tolower(str1[i]) == tolower(str2[j])) {
                removeCharAtIndex(str1, i);
                removeCharAtIndex(str2, j);
                i--;
                break;
            }
        }
    }
}

char calculateFLAMES(char *name1, char *name2) {
    removeCommonChars(name1, name2);
    int total_length = strlen(name1) + strlen(name2);
    char flames[] = "FLAMES";
    int flames_length = strlen(flames);
    int count = 0;
    
    for (int i = 0; i < strlen(flames); i++) {
        for (int j = 0; j < strlen(name1); j++) {
            if (flames[i] == toupper(name1[j])) {
                count++;
            }
        }
    }
    
    int result_index = (total_length - count) % flames_length;
    return flames[result_index];
}

int main() {
    char name1[100], name2[100];
    
    printf("Enter the first name: ");
    scanf("%s", name1);
    
    printf("Enter the second name: ");
    scanf("%s", name2);
    
    char result = calculateFLAMES(name1, name2);
    
    switch(result) {
        case 'F':
            printf("Friends\n");
            break;
        case 'L':
            printf("Love\n");
            break;
        case 'A':
            printf("Affection\n");
            break;
        case 'M':
            printf("Marriage\n");
            break;
        case 'E':
            printf("Enemy\n");
            break;
        case 'S':
            printf("Siblings\n");
            break;
        default:
            printf("Error\n");
    }
    
    return 0;
}
