/*
* Пример использования паттерна
* visitor.
*/


#include <string> 
#include <cmath>
#include <iostream>

#include "expression.h"
#include "binaryoperation.h"
#include "number.h"
#include "variable.h"
#include "functioncall.h"

#include "scope.h"

#include "transformer.h"
#include "copysyntaxtree.h"
#include "foldconstants.h"

bool check_equals(Expression const *left, Expression const *right)
{
    void* &p_1 = (void* &)*left;
    void* &p_2 = (void* &)*right;
    return p_1 == p_2;
}

int main() 
{   
    return 0;
}

