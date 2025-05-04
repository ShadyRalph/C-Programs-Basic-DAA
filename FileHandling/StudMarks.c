#include <stdio.h>
#include <stdlib.h>
#define Namelen 50
#define Sublen 3
typedef struct stud {
    char name[Namelen];
    int marks[Sublen];
    int total_marks;
} Student;
int main() {
    FILE *input_file = fopen("marks.txt", "r");
    if (input_file == NULL) {
        printf("Error opening marks.txt file.\n");
        return 1;
    }
    FILE *output_file = fopen("total_marks.txt", "w");
    if (output_file == NULL) {
        printf("Error opening total_marks.txt file.\n");
        fclose(input_file);
        return 1;
    }
    Student students[10];
    int num_students = 0;
    while (fscanf(input_file, "%s %d %d %d", students[num_students].name, &students[num_students].marks[0], &students[num_students].marks[1], 
        &students[num_students].marks[2]) != EOF) 
        
        {
        students[num_students].total_marks = 0;
        for (int i = 0; i < Sublen; i++) {
            students[num_students].total_marks += students[num_students].marks[i];
        }
        num_students++;
    }
    for (int i = 0; i < num_students; i++) {
        fprintf(output_file, "%s %d\n", students[i].name, students[i].total_marks);
    }
    fclose(input_file);
    fclose(output_file);
    printf("Total marks generated successfully.\n");
    return 0;
}
