# include <stdio.h>
# include <string.h>

struct Student {
    char name[20];
    int age;
};

void PrintStudent(struct Student stu[5]) {
    for (int i=0; i<5; i++) {
		printf("mame: %s, age: %d\n", stu[i].name, stu[i].age);
    }
}

int main(void) {
    struct Student stu[5] = {{"John", 22}, {"Mike", 21}, {"Siri", 23}, {"Tom", 20}, {"Joe", 19}};
    PrintStudent(stu);
    return 0;
}
