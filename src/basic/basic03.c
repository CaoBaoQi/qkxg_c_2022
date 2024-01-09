void basic03_demo01();

void basic03_demo02(int a, int b);

void basic03_demo03(int *a, int *b);

void basic03_demo04();

void basic03_demo05();

void basic03_demo06();

void basic03_demo07();


#include "../common/cbq.h"
#define COUNT 3

typedef struct Student {
    int id;
    int age;
    char *name;
} Student;


/**
 * @author caobaoqi
 * @name C 程序设计-03-数组、指针、结构体、枚举
 * @date 2024/1/9 12:26
 */
int main() {
    int a = 1, b = 2;
    basic03_demo01();
    basic03_demo02(a, b);
    printf("Swap By Value| a = %d,b = %d\n", a, b);
    basic03_demo03(&a, &b);
    printf("Swap By Address| a = %d,b = %d\n", a, b);
    basic03_demo04();
    basic03_demo05();
    basic03_demo06();
    basic03_demo07();
    return 0;
}

/**
 * 结构体的定义及使用
 */
void basic03_demo01() {
    printHeader("basic03_demo01");

    Student cbq = {1, 21, "CaoBaoQi"};
    Student *cbq_p = &cbq;

    printf("show info by struct: {id = %d, age = %d, name = %s}\n", cbq.id, cbq.age, cbq.name);
    printf("show info by struct pointer(Complex) {id = %d, age = %d, name = %s}\n", (*cbq_p).id, (*cbq_p).age,
           (*cbq_p).name);
    /**
     !* (*cbq_p).id 等同于 cbq_p->id
     */
    printf("show info by struct pointer(Simple) {id = %d, age = %d, name = %s}\n", cbq_p->id, cbq_p->age, cbq_p->name);

    printFooter("basic03_demo01");

}

/**
 * 值传递
 */
void basic03_demo02(int a, int b) {
    int temp = b;
    b = a;
    a = temp;
}

/**
 * 址传递
 */
void basic03_demo03(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

/**
 * 结构体空间大小的计算
 * sizeof 关键字
 * typedef struct Object {
        char a;
        int b;
        short c;
    }Object;
  ** 结构体中的各个数据要求字节对齐，规则如下：
  **规则一：结构体中元素按照定义顺序依次置于内存中，但并不是紧密排列的。从结构体首地址开始依次将元素放入内存时，元素会被放置在其自身对齐大小的整数倍地址上（0默认是所有大小的整数倍）
  **规则二：如果结构体大小不是所有元素中最大对齐大小的整数倍，则结构体对齐到最大元素对齐大小的整数倍，填充空间放置到结构体末尾。
  **规则三：基本数据类型的对齐大小为其自身的大小，结构体数据类型的对齐大小为其元素中最大对齐大小元素的对齐大小。
  !* 其中 char 为 1B int 4B short 2B
  !* char占据 1 个字节
  !* int占据 4 个字节 因为前面存了一个 char 按理说应该从第 2 个字节开始存放 但是根据规则一 必须在自己的整数倍位置上存放 2 不是 4 的整数倍位置，这时离 1 最近的下一个整数倍地址就是 4 了，所以前面空 3 个字节的位置出来，然后再放置
  !* 前面存完 int 之后，就是从 8 开始了 刚好满足 short（2B）的整数倍，但是根据规则二，整个结构体大小必须是最大对齐大小的整数倍（这里最大对齐大小是 int，所以是 4），存完 short 之后，只有 10 个字节，所以屁股后面再补两个空字节，这样就可以了
  !* | char 1B | 3B | int 4B | short 2B | 2B |
  !* |1              4        8          10   12|
 */
void basic03_demo04() {
    printHeader("basic03_demo04");

    typedef struct Object {
        char a;
        int b;
        short c;
    } Object;
    printf("struct Object size is = %llu", sizeof(Object));

    printFooter("basic03_demo04");
}

/**
 * 结构体数组和指针
 */
void basic03_demo05() {
    printHeader("basic03_demo05");
    Student students[COUNT] = {{1, 21, "CBQ"},
                           {2, 21, "CBH"},
                           {3,18,"CB"}};

    for (int i = 0; i < COUNT; ++i){
        printf("INFO: name = %s, id = %d, age = %d \n", students[i].name, students[i].id, students[i].age);

    }

    printFooter("basic03_demo05");
}

/**
 * 联合体 联合体的大小至少是其内部最大类型的大小
 */
void basic03_demo06() {
    printHeader("basic03_demo06");

    typedef union Teacher{
        int id;
        char name;
    }Teacher;

    printf("union Teacher size is = %llu\n", sizeof(Teacher));
    printf("=========================\n");
    Teacher teacher;
    teacher.id = 1;
    printf("teacher id = %d \n", teacher.id);
    /**
     !* teacher id = 1
     !* teacher name = 1
     联合体公用一段空间
     */
    printf("teacher name = %d \n", teacher.name);

    printFooter("basic03_demo06");
}

/**
 * 枚举的使用
 */
void basic03_demo07(){
    printHeader("basic03_demo07");

    enum status { low = 1, middle = 2, high = 3};
    printf("low: %d\n", low);
    printf("middle: %d\n", middle);
    printf("high: %d\n", high);

    /**
     * low2 由于是第一个，所以还是从 0 开始
     * 不过 middle2 这里已经指定为 6 了 所以紧跟着的 high2 初始值就是 middle2 的值 +1 了
     * 因此 low2 现在是 0 middle就是 6 high2 就是 7 了
     */
    enum status2 {low2, middle2 = 6, high2};
    printf("low2: %d\n", low2);
    printf("middle2: %d\n", middle2);
    printf("high2: %d\n", high2);


    printFooter("basic03_demo07");
}

