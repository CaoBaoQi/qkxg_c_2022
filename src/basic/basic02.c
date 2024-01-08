void basic02_demo01();

void basic02_demo02();

void basic02_demo03();

void basic02_demo04();

void basic02_demo05();

void basic02_demo06();

#include <string.h>
#include "../common/cbq.h"

/**
 * @author caobaoqi
 * @name basic02
 * @date 2024/1/8 14:54
 */
int main() {
    basic02_demo01();
    basic02_demo02();
    basic02_demo03();
    basic02_demo04();
    basic02_demo05();
    return 0;
}

/**
 * 嵌套的 for 循环来实现冒泡排序算法:
 * 外层循环 for (i = 0; i < n - 1; i++) 控制了排序的轮数 在每一轮中 内层循环会执行比较和交换操作
 * 内层循环 for (j = 0; j < n - 1 - i; j++) 用于比较相邻的元素 并根据需要进行交换 由于每一轮都会将当前最大的元素移动到末尾 所以内层循环的终止条件是 n - 1 - i
 * 在内层循环中，通过比较 arr[j] 和 arr[j + 1] 的大小来确定它们的顺序 如果 arr[j] 大于 arr[j + 1] 则交换它们的位置 确保较大的元素在后面
 * 交换操作使用了一个临时变量 temp 将 arr[j] 的值保存起来 然后将 arr[j + 1] 的值赋给 arr[j] 最后将 temp 的值赋给 arr[j + 1] 完成两个元素的交换
 * 这样 每一轮内层循环执行完毕后 当前轮最大的元素就会被放置在正确的位置上
 * <p>
 * 内层循环的终止条件 n - 1 - i 是基于以下观察：每一轮冒泡排序都会将当前轮中最大的元素移动到末尾的正确位置上
 * 在第一轮比较中 通过内层循环的交换操作，最大的元素会被移动到数组的最后一个位置（即 arr[n-1]）
 * 在第二轮比较中 由于最大的元素已经在正确的位置上，内层循环只需要比较和交换剩下的元素 这样最大的元素不会被再次考虑
 * 在第三轮比较中 第二大的元素会被移动到倒数第二个位置（即 arr[n-2]）
 * 以此类推 每一轮冒泡排序都会将当前轮中最大的元素移动到正确的位置上 因此内层循环的终止条件可以逐渐减少 避免重复比较已经排好序的元素
 * 综上所述 内层循环的终止条件 n - 1 - i 是为了优化冒泡排序算法的性能 避免不必要的比较操作 因为在每一轮中，已经有 i 个元素被排好序了
 * @param arr arr
 * @param n length
 */
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("the %d result: ", i + 1);
        for (j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

/**
 ?* 冒泡排序
 ?* 核心思想：
 !* - 假设数组长度为 N
 !* - 进行 N 轮循环，每轮循环都选出一个最大的数放到后面
 !* - 每次循环中，从第一个数开始，让其与后面的数两两比较，如果更大，就交换位置，如果更小，就不动
 */
void basic02_demo01() {
    printHeader("basic02_demo01");

    /**
     * 给定序列: 3 5 7 2 9 0 6 7 1 8 4
     * 1. 从序列的第一个元素开始 依次比较相邻的两个元素 如果前一个元素大于后一个元素 则交换它们的位置
     !* - 第 1 轮:   7 > 2 --> 3 5 2 7 9 0 6 7 1 8 4
     !* -           9 > 0 --> 3 5 2 7 0 9 6 7 1 8 4
     !* -           9 > 6 --> 3 5 2 7 0 6 9 7 1 8 4
     !* -           9 > 7 --> 3 5 2 7 0 6 7 9 1 8 4
     !* -           9 > 1 --> 3 5 2 7 0 6 7 1 9 8 4
     !* -           9 > 8 --> 3 5 2 7 0 6 7 1 8 9 4
     !* -           9 > 4 --> 3 5 2 7 0 6 7 1 8 4 9
     ** 第一轮排序结束后 序列为: [3 5 2 7 0 6 7 1 8 4 9] 最大的元素 9 已经排在了序列的最后 对除最后一个元素外的剩余元素进行第二轮排序，重复步骤 1
     ?* 第 2 轮排序结束后 序列为: [3 2 5 0 6 7 1 7 4 8 9] 最大的元素 8 已经排在了序列的最后
     ?* 第 3 轮排序结束后 序列为: [2 3 0 5 6 1 7 4 7 8 9] 最大的元素 7 已经排在了序列的最后
     ?* 第 4 轮排序结束后 序列为: [2 0 3 5 1 6 4 7 7 8 9] 最大的元素 7 已经排在了序列的最后
     ?* 第 5 轮排序结束后 序列为: [0 2 3 1 5 4 6 7 7 8 9] 最大的元素 6 已经排在了序列的最后
     ?* 第 6 轮排序结束后 序列为: [0 2 1 3 4 5 6 7 7 8 9] 最大的元素 5 已经排在了序列的最后
     ?* 第 7 轮排序结束后 序列为: [0 1 2 3 4 5 6 7 7 8 9] 最大的元素 4 已经排在了序列的最后
     ?* 第 8 轮排序结束后 序列为: [0 1 2 3 4 5 6 7 7 8 9] 最大的元素 3 已经排在了序列的最后
     ?* 第 9 轮排序结束后 序列为: [0 1 2 3 4 5 6 7 7 8 9] 最大的元素 2 已经排在了序列的最后
     ?* 第 10 轮排序结束后 序列为: [0 1 2 3 4 5 6 7 7 8 9] 最大的元素 1 已经排在了序列的最后
     */
    int arr[11] = {3, 5, 7, 2, 9, 0, 6, 7, 1, 8, 4};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("------------------------------------\nbefore sort: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n------------------------------------\n");

    bubbleSort(arr, length);

    printf("------------------------------------\nafter sort: ");
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n------------------------------------\n");
    printFooter("basic02_demo01");
}

/**
 ?* 斐波那契数列解法 其二
 ?* 学习了数组，我们来看看如何利用数组来计算斐波那契数列 这里 采用动态规划 的思想
 ?* 动态规划算法通常用于求解具有某种最优性质的问题。在这类问题中，可能会有许多可行解每一个解都对应于一个值
 ?* 我们希望找到具有最优值的解。动态规划算法与分治法类似，其基本思想也是将待求解问题分解成若干个子问题，先求解子问题，然后从这些子问题的解得到原问题的解。
 * <p>
 ** 我们可以在一开始创建一个数组，然后从最开始的条件不断向后推导，从斐波那契数列的规律我们可以得知：
 ** fib[i] = fib[i - 1] + fib[i - 2]（这里fib代表斐波那契数列）
 ** 得到这样的一个关系（递推方程）就好办了，我们要求解数列第i个位置上的数，只需要知道i - 1和i - 2的值即可，这样，一个大问题，就分成了两个小问题，比如现在我们要求解斐波那契数列的第5个元素：
 ** fib[4] = fib[3] + fib[2]现在我们只需要知道fib[3]和fib[2]即可，那么我们接着来看：
 ** fib[3] = fib[2] + fib[1]以及fib[2] = fib[1] + fib[0]
 ** 由于fib[0]和fib[1]我们已经明确知道是1了，那么现在问题其实已经有结果了，把这些小问题的结果组合起来不就能得到原来大问题的结果了吗？
 * <p>
 !* 现在请你设计一个 C 语言程序 利用 动态规划 的思想解决斐波那契数列问题
 */
void basic02_demo02() {
    printHeader("basic02_demo02");

    printFooter("basic02_demo02");
}

/**
 ?* 打家劫舍  来源：力扣（LeetCode）No.198 打家劫舍：https://leetcode.cn/problems/house-robber/

 */
void basic02_demo03() {
    printHeader("basic02_demo03");

    printFooter("basic02_demo03");
}

/**
 * 字符串的本质
 !* - char cbq01[] = {'H', 'E', 'L', 'L', 'O',' ', 'C', 'B', 'Q', '\0'}
 !* - const char cbq02[] = "HELLO CBQ"
 ** cbq01 中 '\0' 代表字符串结束标志 | 无论内容是什么，字符串末尾必须添加一个 ‘\0’ 字符（ASCII 码为 0）表示结束
 ** 双引号囊括的字符串实际上就是一个 const char 数组类型的值
 */
void basic02_demo04() {
    printHeader("basic02_demo04");
    char cbq01[] = {'H', 'E', 'L', 'L', 'O', ' ', 'C', 'B', 'Q', '\0'};
    const char cbq02[] = "HELLO CBQ";

    printf("cbq01 = %s \n| cbq02 = %s ", cbq01, cbq02);


    printFooter("basic02_demo04");
}

/**
 * 回文串 是一个正读和反读都一样的字符串
 * 请你实现一个 C 语言程序判断用户输入的字符串（仅出现英文字符）是否为 回文串
 */
void basic02_demo05() {
    printHeader("basic02_demo05");

    /**
     !* 从 control 控制台获取一个 str 字符串并取出 \n
     */
    char str[100];
    printf("Please Input str: \n");
    fgets(str, sizeof(str), stdin);
    /**
     ?* strcspn 是一个 C 语言标准库函数，它的原型如下： size_t strcspn(const char *str1, const char *str2)
     ?* strcspn 函数用于计算字符串 str1 开头连续不包含字符串 str2 中任何字符的长度
     ?* 具体来说，strcspn 函数会从 str1 的开头开始逐个字符地与 str2 中的字符进行比较 直到遇到 str2 中的任何字符，或者到达 str1 的末尾为止
     ?* 函数返回的是在遇到第一个 str2 中的字符之前 str1 开头连续的字符个数
     ** 下面是一个示例:
     ** #include <stdio.h>
     ** #include <string.h>
     ** int main() {
     **      char str1[] = "Hello, World!";
     **      char str2[] = " ,!";
     **      size_t len = strcspn(str1, str2);
     **      printf("连续不包含 %s 中任何字符的长度为 %zu\n", str2, len);
     **      return 0;
     ** }
     !* 在这个示例中，str1 是一个字符串 "Hello, World!"，str2 是一个包含空格、逗号和感叹号的字符串 " ,!"
     !* strcspn(str1, str2) 的返回值是 7，表示字符串 str1 开头连续不包含 str2 中任何字符的长度为 7
     */
    str[strcspn(str, "\n")] = '\0';
    int length = strlen(str);
    int i = 0, j = length - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            printf("%s is not back str\n", str);
            return;
        }
        i++;
        j--;
    }
    printf("%s is back str\n", str);
    printFooter("basic02_demo05");
}

/**
 * 字符串匹配 KMP 算法
 * 现在请你设计一个 C 语言程序 判断第一个字符串中是否包含了第二个字符串
 * eg: str1 = "abcdabbc"
 *     str2 = "cda"
 * 比如上面的例子中 很明显第一个字符串包含了第二个字符串
 */
void basic02_demo06() {
    printHeader("basic02_demo06");

    printFooter("basic02_demo06");
}