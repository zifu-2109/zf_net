bin = balance_binary_tree zf_list zf_rbtree offsetof container_of zf_kernel_rbtree bubble_sort \
quick_sort insert_sort shell_sort select_sort heap_sort merge_sort bucket_sort radix_sort

all:$(bin)

balance_binary_tree:balance_binary_tree.c
	gcc -g -o balance_binary_tree balance_binary_tree.c

zf_list:zf_list_test.c
	gcc -g -o zf_list zf_list_test.c

zf_rbtree:zf_rbtree.c zf_rbtree_test.c
	gcc -g -o zf_rbtree zf_rbtree.c zf_rbtree_test.c

offsetof:offsetof.c
	gcc -g -o offsetof offsetof.c

container_of:container_of.c
	gcc -g -o container_of container_of.c

zf_kernel_rbtree:zf_kernel_rbtree.c zf_kernel_rbtree_test.c
	gcc -g -o zf_kernel_rbtree zf_kernel_rbtree.c zf_kernel_rbtree_test.c

bubble_sort:bubble_sort.c
	gcc -g -o bubble_sort bubble_sort.c

quick_sort:quick_sort.c
	gcc -g -o quick_sort quick_sort.c

insert_sort:insert_sort.c
	gcc -g -o insert_sort insert_sort.c

shell_sort:shell_sort.c
	gcc -g -o shell_sort shell_sort.c

select_sort:select_sort.c
	gcc -g -o select_sort select_sort.c

heap_sort:heap_sort.c
	gcc -g -o heap_sort heap_sort.c
	
merge_sort:merge_sort.c
	gcc -g -o merge_sort merge_sort.c

bucket_sort:bucket_sort.c
	gcc -g -o bucket_sort bucket_sort.c

radix_sort:radix_sort.c
	gcc -g -o radix_sort radix_sort.c

clean:
	rm -f $(bin)