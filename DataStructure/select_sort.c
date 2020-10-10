/*
选择排序(Selection sort)是一种简单直观的排序算法。它的基本思想是：
	首先在未排序的数列中找到最小(or最大)元素，然后将其存放到数列的起始位置；接着，再从剩余未排序的元素中继续寻找最小(or最大)元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。


选择排序时间复杂度
	选择排序的时间复杂度是O(N2)。
	假设被排序的数列中有N个数。遍历一趟的时间复杂度是O(N)，需要遍历多少次呢？N-1！因此，选择排序的时间复杂度是O(N2)。

选择排序稳定性
	选择排序是稳定的算法，它满足稳定算法的定义。
	算法稳定性 -- 假设在数列中存在a[i]=a[j]，若在排序之前，a[i]在a[j]前面；并且排序之后，a[i]仍然在a[j]前面。则这个排序算法是稳定的！

*/

/**
 * 选择排序
 */

#include <stdio.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) (a^=b,b^=a,a^=b)

/*
 * 选择排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
void select_sort(int a[], int n)
{
    int i;        // 有序区的末尾位置
    int j;        // 无序区的起始位置
    int min;    // 无序区中最小元素位置

    for(i=0; i<n; i++)
    {
        min=i;

        // 找出"a[i+1] ... a[n]"之间的最小元素，并赋值给min。
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min])
                min=j;
        }

        // 若min!=i，则交换 a[i] 和 a[min]。
        // 交换之后，保证了a[0] ... a[i] 之间的元素是有序的。
        if(min != i)
            swap(a[i], a[min]);
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

    select_sort(a, ilen);

    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
}

