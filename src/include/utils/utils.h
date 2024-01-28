/*
 This header file declares small inline utility functions
 */

#ifndef UTILS_H
#define UTILS_H

inline void toLower(char* str){
    while(*str){
	*str = tolower(*str);
	str++;
    }
}
