/*
 * from CSDN student programming challenge, Jan 2014
 * perfect number: if all digits of x can divide x exactly, x is called perfect number. 
 * given two inclusive boundary [a,b], a>0, find count of perfect numbers among [a,b]
 * [1,9], 12
 *
 * */

/*
 * solution is based on analysis of the perfect number
 * [1,9], 9
 * [10,19], 4(10, 11, 12, 15)
 * [20,29], 3(20, 22, 24)
 * [30, 39], 3(30,33,36)
 * [40,49], 3(40, 44, 48)
 * [50,59], 2(50, 55)
 * [60, 69], 2(60, 69)
 * [70, 79], 2(70, 77)
 * [80, 89], 2(80, 88)
 * [90, 99], 2(90, 99)
 * [1x0,1x9] = count[x0, x9]
 * [xx0, xx9] = count[x0, x9]
 * [2x0, 2x9] = 1/2*count[x0, x9]   x != 2,4,6,8
 * [4x0, 4x9] = 1/4*count[x0, x9]   x != 4,8
 * */
