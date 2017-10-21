#include <stdio.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

struct student{
		char genger;
		int id;
		int age;
		char name[20];
		int year;
};

int main(){
	size_t genger = offsetof(struct student,genger);
	printf("genger=%d\n",genger);
	size_t id = offsetof(struct student,id);
	printf("id=%d\n",id);
	size_t age = offsetof(struct student,age);
	printf("age=%d\n",age);
	size_t name = offsetof(struct student,name);
	printf("name=%d\n",name);
	size_t year = offsetof(struct student,year);
	printf("year=%d\n",year);
	size_t age1 = (size_t) &((struct student *)0)->age;
	printf("%d\n",age1);
	struct student *stu = 0;
	size_t age2 = (size_t)stu->age;
	printf("%d\n",age2);
}
