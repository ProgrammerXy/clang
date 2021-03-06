#include "stdio.h"

/*
 * _____________________________________________________________
 * | 运算符  |  含义   | 优先级  | 举例  |          说明            |
 * |________|________|________|______|__________________________|
 * |        |        |        |      | 如果a为1,~a为0;            |
 * |   ~    | 按位取反 |  高    |  ~a  | 如果a为0,~a为1;            |
 * |------------------------------------------------------------|
 * |        |         |       |      |  只有a和b同时为1,结果才为1;  |
 * |    &   |  按位与  |  高    | a&b  | 只要a和b其中一个为0,结果为0. |
 * |____________________________________________________________|
 * |        |         |       |      |  如果a和b不同,其结果为1;     |
 * |    ^   | 按位异或  |  低   | a^b  |  如果a和b相同,其结果为0.     |
 * |_____________________________________________________________|
 * |        |         |       |      | 只要a和b其中一个为1,结果为1;  |
 * |    |   |  按位或  |  最低  | a|b  | 只要a和b同时为0,结果为0.     |
 * |_____________________________________________________________|
*/

int main(void){
    int mask = 0xFF;
    int v1 = 0xABCDEF;
    int v2 = 0xABCDEF;
    int v3 = 0xABCDEF;

    /*
     *  mask = 000000000000000011111111
     *    v1 = 101010111100110111101111
     */

    /*
     * 只有全为1才为1,其他为0
     * 000000000000000011101111
     * 0xEF
     */
    v1 &= mask;
    /*
     * 有1就为1,其他为0
     * 101010111100110111111111
     * 0xABCDFF
     */
    v2 |= mask;
    /*
     * 有异便为1,其他为0
     * 101010111100110100010000
     * 0xABCD10
     */
    v3 ^= mask;
    printf("v1 -> 0x%X \n",v1);
    printf("v2 -> 0x%X \n",v2);
    printf("v3 -> 0x%X \n",v3);
    return 0;
}