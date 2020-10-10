/*
直接插入排序(Straight Insertion Sort)的基本思想:
	把n个待排序的元素看成为一个有序表和一个无序表。开始时有序表中只包含1个元素，无序表中包含有n-1个元素，排序过程中每次从无序表中取出第一个元素，将它插入到有序表中的适当位置，使之成为新的有序表，重复n-1次可完成排序过程。

直接插入排序时间复杂度
	直接插入排序的时间复杂度是O(N2)。
	假设被排序的数列中有N个数。遍历一趟的时间复杂度是O(N)，需要遍历多少次呢？N-1！因此，直接插入排序的时间复杂度是O(N2)。

直接插入排序稳定性
	直接插入排序是稳定的算法，它满足稳定算法的定义。
	算法稳定性 -- 假设在数列中存在a[i]=a[j]，若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！

*/

 /**
 * 直接插入排序
 */

#include <stdio.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

/*
 * 直接插入排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void insert_sort(int a[], int n)
{
    int i, j, k;

    for (i = 1; i < n; i++)
    {
        //为a[i]在前面的a[0...i-1]有序区间中找一个合适的位置
        for (j = i - 1; j >= 0; j--)
            if (a[j] < a[i])
                break;

        //如找到了一个合适的位置
        if (j != i - 1)
        {
            //将比a[i]大的数据向后移
            int temp = a[i];
            for (k = i - 1; k > j; k--)
                a[k + 1] = a[k];
            //将a[i]放到正确位置上
            a[k + 1] = temp;
        }
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

    insert_sort(a, ilen);

    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
}