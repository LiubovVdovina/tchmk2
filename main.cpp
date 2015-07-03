//
//  main.cpp
//  r22
//
//  Created by Admin on 03.07.15.
//  Copyright (c) 2015 Admin. All rights reserved.
//

#include <iostream>
#include "long_number_lib.h"
#include <string.h>
using namespace std;



int main(int argc, char* argv[])
{
    int flag_oper;
    if (argc<5)
    {
        printf("Too few parametres. Try again.\n");
        return 1;
    }
    if (argc >7)
    {
        printf("Too many parametres. Try again.\n");
        return 1;
    }
    char *file1 = argv[1];
    char *file2 = argv[3];
    char *file3 = argv[4];
    char *file4 = NULL;
    flag_oper = 0;
    
    int bin = 0;
    
    if (argc == 6)
    {
        if (!strcmp(argv[5], "-b"))
            bin = 1;
        else
            file4 = argv[5];
    }
    
    if (argc == 7)
    {
        bin = 1;
        file4 = argv[6];
    }
    
    long_class A, B, mod;
    
    if (bin == 1)
    {
        A.binaryRead_class(file1);
        B.binaryRead_class(file2);
        if (file4 != NULL)
            mod.binaryRead_class(file4);
    }
    else
    {
        A.fileRead_class(file1);
        B.fileRead_class(file2);
        if (file4 != NULL)
            mod.fileRead_class(file4);
    }
    
    long_class c;
    if (argv[2][0] == '+')
    {
        c = A + B;
        flag_oper = 1;
    }
    
    if (argv[2][0] == '-')
    {
        c = A - B;
        flag_oper = 2;
    }
    if (argv[2][0] == 'm')
    {
        c = A * B;
        flag_oper = 3;
    }
    
    if (argv[2][0] == '/')
    {
        c = A / B;
        flag_oper = 4;
    }
    
    if (argv[2][0] == '%')
        c = A % B;
    
    if (file4 != NULL)
        c = c % mod;
    
    if (argv[2][0] == '^')
    {
        if (file4 == NULL)
            c = A ^ B;
        else
            c = invoke_module_class(A, B, mod);
    }
    
    if (bin == 1)
        c.binaryWrite_class(file3, flag_oper);
    else
        c.fileWrite_class(file3);
    
    return 0;
}