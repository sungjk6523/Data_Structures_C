#include<stdio.h>
#include<string.h>

typedef struct _education {
	char elements[20];
	char middle[20];
	char high[20];
	char college[20];
} edu;

typedef struct _human {
	char name[20];
	enum tagField { female, male } sex;
	edu edu;
} human;


int main() {
	human Being;
	char sex[6];
	printf("Name:");
	scanf("%s", Being.name);

	printf("Sex:");
	scanf("%s", sex);
	if (strcmp(sex, "male") == 0)
		Being.sex = male;
	else
		Being.sex = female;
	
	printf("Elements:");
	scanf("%s", Being.edu.elements);
	printf("Middle:");
	scanf("%s", Being.edu.middle);
	printf("High:");
	scanf("%s", Being.edu.high);
	printf("College:");
	scanf("%s", Being.edu.college);

}
