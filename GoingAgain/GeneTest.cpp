/**************************************************************************

File:           GeneTest.cpp

Date: 		    18/01/2024

Author: 	    Taylor Bullard (frf22rzu)

Description:    Used as a test harness to ensure than the class works and
                performs how it is is expected to. Overloaded operators have
                also been tested. Will return false if an errors that appear
                during run-time.

Version: 	    18/01/2024 v1.00

*************************************************************************/

#include <iostream>
#include <vector>
#include "Gene.h"

using namespace std;

bool testGene() {

    int errCount;

    //creating Objects using Gene class
    Gene gene1("52052", "ggwagggt", 89);
    Gene gene2("12345", "gataa", -109);
    Gene gene3("52862", "ggwaggaagtgggt", 0);
    Gene gene4("19745", "gataggtagga", 0);
    Gene gene5("67952", "ggwaggataggtaggagataggtaggaggt", 89);
    Gene gene6("12087", "gatagataggtaggaa", 879);
    Gene gene7("65673", "gggataggtaggawaggaagtgggt", 0);
    Gene gene8("87664", "gagataggtaggataggtagga", 6665);

    //creating a collection so that more testing can be done
    std::vector<Gene> myVector;

    //testing to see if all valid genes
    try
    {
        myVector.push_back(gene1);
        myVector.push_back(gene2);
        myVector.push_back(gene3);
        myVector.push_back(gene4);
        myVector.push_back(gene5);
        myVector.push_back(gene6);
        myVector.push_back(gene7);
        myVector.push_back(gene8);
    }
    catch (exception e)
    {
        errCount++;
    }

    //testing accessor methods
    try
    {
        for (int i = 0; i < 5; ++i) {
            myVector[i].getPropensity();
            myVector[i].getId();
            myVector[i].getSequence();
        }
    }
    catch (std::exception& e)
    {
        errCount++;
    }

    //testing << operator
    try
    {
        cout << gene2;
        cout << gene1;
    }
    catch (std::exception& e)
    {
        errCount++;
    }

    //testing > overloaded operator - created own runtime exception
    try
    {
        gene1.setPropensity(1);
        gene2.setPropensity(0);

        if (gene1 > gene2)
        {

        }
        else
        {
            throw std::runtime_error("Incorrect for > ");
        }
    }
    catch (std::exception& e)
    {
        errCount++;
    }

    //testing < overloaded operator - created own runtime exception
    try
    {
        gene1.setPropensity(0);
        gene2.setPropensity(1);

        if (gene1 < gene2)
        {
            throw std::runtime_error("Incorrect for < ");
        }
    }
    catch (std::exception& e)
    {
        errCount++;
    }

    //testing = overloaded operator - created own runtime exception
    try
    {
        gene3.setPropensity(0);
        gene4.setPropensity(0);

        if (gene3 == gene4)
        {

        }
        else
        {
            throw std::runtime_error("Incorrect for == ");
        }
    }
    catch (std::exception& e)
    {
        errCount++;
    }


    //errCount > 0 if any run-time errors and would therefore return false
    if (errCount > 0)
    {
        cout << "Failed with " << errCount << " errors" << endl;
        return false;
    }
    else
    {
        cout << "Passed with no errors" << endl;
        return true;
    }



}


