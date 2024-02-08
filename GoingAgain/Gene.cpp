/**************************************************************************

File:           Gene.cpp

Date: 		    18/01/2024

Author: 	    Taylor Bullard (frf22rzu)

Description:    Initially was going to put the inline functions from
                the header file into this cpp file. However there were
                some problems with linking an the operators below are
                the only that would go across

Version: 	    18/01/2024 v1.00

*************************************************************************/

#include "Gene.h"

bool operator != (const Gene &a, const Gene &b)
{
    return !(a == b);
}

bool operator <= (const Gene &a, const Gene &b)
{
    return !(a > b);
}

bool operator >= (const Gene &a, const Gene &b)
{
    return !(a < b);
}
