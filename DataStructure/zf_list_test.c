#include "zf_list.h"
#include <stdio.h>
#include <stdlib.h>
 
 
#define SZ 32
 
#define CNT 30
 
struct ourstu {
	struct list_head list;
	char name[SZ];
	int num;
};
 
struct list_head head;// =  {&head,&head};
 
static int demo_init(void)
{
	int i;
	struct ourstu *stu;
 
	struct list_head *pos, *n;
 
	for (i = 0; i < CNT; i++) {
		stu = malloc(sizeof(struct ourstu));
		if (NULL == stu) {
			goto error0;
		}
		stu->num = i;
		sprintf(stu->name, "spring%d", i);
 
		list_add_tail(&stu->list, &head);
	}
 
	list_for_each (pos, &head) {
		stu = container_of(pos, struct ourstu, list);            
		printf("%s's number %d\n", stu->name, stu->num);
	}
 
 
	return 0;
 
error0:
	list_for_each_safe(pos, n, &head) {
		stu = container_of(pos, struct ourstu, list);    
		printf("%s see bye...\n", stu->name);
		free(stu);
	}
 
	return -1;
}
 
 
 
static void demo_exit(void)
{
	struct list_head *n, *pos;
	struct ourstu *stu;
 
	list_for_each_safe(pos, n, &head) {
		stu = container_of(pos, struct ourstu, list);    
		printf("%s say bye...\n", stu->name);
		free(stu);
	}
 
	printf("see you, kernel...\n");
}
 
int main()
{
	INIT_LIST_HEAD(&head);
		
	demo_init();
	sleep(5);
	demo_exit();
}

