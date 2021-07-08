/*
 * math.h
 *
 * Created: 7/7/2021 5:19:33 AM
 *  Author: DELLL
 */ 


#ifndef MATH_H_
#define MATH_H_

#define SET_BIT(REG,BIT)	(REG|=(1<<BIT))
#define CLR_BIT(REG,BIT)	(REG&=~(1<<BIT))
#define TOG_BIT(REG,BIT)	(REG^=(1<<BIT))
#define GET_BIT(REG,BIT)	(REG&(1<<BIT))



#endif /* MATH_H_ */