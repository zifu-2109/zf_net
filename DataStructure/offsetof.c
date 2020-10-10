/*
定义：offsetof在linux内核的include/linux/stddef.h中定义。

	#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
	说明：获得结构体(TYPE)的变量成员(MEMBER)在此结构体中的偏移量。
	(01)  ( (TYPE *)0 )   将零转型为TYPE类型指针，即TYPE类型的指针的地址是0。
	(02)  ((TYPE *)0)->MEMBER     访问结构中的数据成员。
	(03)  &( ( (TYPE *)0 )->MEMBER )     取出数据成员的地址。由于TYPE的地址是0，这里获取到的地址就是相对MEMBER在TYPE中的偏移。
	(04)  (size_t)(&(((TYPE*)0)->MEMBER))     结果转换类型。对于32位系统而言，size_t是unsigned int类型；对于64位系统而言，size_t是unsigned long类型。

*/

#include <stdio.h>

// 获得结构体(TYPE)的变量成员(MEMBER)在此结构体中的偏移量。
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

struct student
{
    char gender;
    int id;
    int age;
    char name[20];
};

void main()
{
    int gender_offset, id_offset, age_offset, name_offset;

    gender_offset = offsetof(struct student, gender);
    id_offset = offsetof(struct student, id);
    age_offset = offsetof(struct student, age);
    name_offset = offsetof(struct student, name);

    printf("gender_offset = %d\n", gender_offset);
    printf("id_offset = %d\n", id_offset);
    printf("age_offset = %d\n", age_offset);
    printf("name_offset = %d\n", name_offset);
}

