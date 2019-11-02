/*
 * SSegment_int.h
 *
 *  Created on: Feb 21, 2018
 *      Author: Mohamed Sobhy
 */

#ifndef SSEGMENT_INT_H_
#define SSEGMENT_INT_H_

/*
* function to choose the ssegment then write the value you want to be shown
* If you want ssegment far away from the LCD  just type SSEGMENT_ONE
* If you want ssegment near from LCD just type SSEGMENT_TWO
*
*/

#define SSEGMENT_RIGHT 10
#define SSEGMENT_LEFT 20


void Ssegment_void_WriteNum(uint8 Copy_uint8_SsegmentNum , uint8 Copy_uint8_Num);


#endif /* SSEGMENT_INT_H_ */
