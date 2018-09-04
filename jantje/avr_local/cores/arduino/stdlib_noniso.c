/*
 noniso.cpp - replacements for non-ISO functions used by Arduino core
 Copyright © 2016 Ivan Grokhotkov
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
*/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "stdlib_noniso.h"

void reverse(char* first, char* last) {
  while ((first!=last)&&(first!=--last)) {
    char c = *first;
    *first = *last;
    *last = c;
    ++first;
  }
}

char* ultoa(unsigned long value, char* result, int base) {
    if(base < 2 || base > 16) {
        *result = 0;
        return result;
    }

    char* out = result;
    unsigned long quotient = value;

    do {
        const unsigned long tmp = quotient / base;
        *out = "0123456789abcdef"[quotient - (tmp * base)];
        ++out;
        quotient = tmp;
    } while(quotient);

    reverse(result, out);
    *out = 0;
    return result;
}
