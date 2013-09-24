/*
 * Vectorizer.h
 *
 *  Created on: Sep 17, 2013
 *      Author: owner
 */

#ifndef VECTORIZER_H_
#define VECTORIZER_H_
struct vectorizer{
	//A - Acquistion Mode
	//T - Track Mode
	//L - Track-Lock Mode
	char cMode;

};
char getMode();
void setMode();
// 1 = TRUE
// 0 = FALSE
int acquistionMode();
int trackMode();
int trackLockMode();

#endif /* VECTORIZER_H_ */
