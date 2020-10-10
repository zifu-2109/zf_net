/*
冒泡排序(Bubble Sort)，又被称为气泡排序或泡沫排序。
	它是一种较简单的排序算法。它会遍历若干次要排序的数列，每次遍历时，它都会从前往后依次的比较相邻两个数的大小；如果前者比后者大，则交换它们的位置。这样，一次遍历之后，最大的元素就在数列的末尾！ 	采用相同的方法再次遍历时，第二大的元素就被排列在最大元素之前。重复此操作，直到整个数列都有序为止！

冒泡排序时间复杂度
	冒泡排序的时间复杂度是O(N2)。
	假设被排序的数列中有N个数。遍历一趟的时间复杂度是O(N)，需要遍历多少次呢？N-1次！因此，冒泡排序的时间复杂度是O(N2)。

冒泡排序稳定性
	冒泡排序是稳定的算法，它满足稳定算法的定义。
	算法稳定性 -- 假设在数列中存在a[i]=a[j]，若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！

*/

/**
 * 冒泡排序：C 语言
 */

#include <stdio.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
// 交互数值
#define swap(a,b)    (a^=b,b^=a,a^=b)

void print(int no, int a[], int n)
{
	int i = 0;

	printf("第%d轮：", no);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n");
}

/*
 * 冒泡排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void bubble_sort1(int a[], int n)
{
    int i, j, no = 1;

    for (i=n-1; i>0; i--)
    {
        // 将a[0...i]中最大的数据放在末尾
        for (j=0; j<i; j++)
        {
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }

		print(no++, a, n);
    }
}

/*
 * 冒泡排序(改进版)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void bubble_sort2(int a[], int n)
{
    int i, j, no = 1;
    int flag;                 // 标记

    for (i=n-1; i>0; i--)
    {
        flag = 0;            // 初始化标记为0

        // 将a[0...i]中最大的数据放在末尾
        for (j=0; j<i; j++)
        {
            if (a[j] > a[j+1])
            {
                swap(a[j], a[j+1]);
                flag = 1;    // 若发生交换，则设标记为1
            }
        }

		print(no++, a, n);

        if (flag==0)
            break;            // 若没发生交换，则说明数列已有序。
    }
}

void main()
{
    int i;
    int a[] = {20,40,30,10,60,50};
    int ilen = LENGTH(a);

    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");

    bubble_sort1(a, ilen);

	printf("\n\n优化排序算法\n");

	int a1[] = {20,40,30,10,60,50};
    int ilen1 = LENGTH(a1);
    bubble_sort2(a1, ilen1);
}

