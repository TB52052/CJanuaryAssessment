/**************************************************************************

File:           Gene.h

Date: 		    18/01/2024

Author: 	    Taylor Bullard (frf22rzu)

Description:    Class for Gene including it's constructor and class specific
                methods. I have decided to make the constructors in-line,
                putting them with the over-loaded operators. There was an
                issue with putting overloaded operators << and >> in an
                additional c++ file as was not linked

                private variables now placed at the bottom of the class
                (just more hidden now)

Version: 	    18/01/2024 v1.00

*************************************************************************/

#ifndef GENE_H
#define GENE_H

#include <string>
#include <iomanip>
#include <iostream>

class Gene
{

public:

    //constructor method for Gene - inline outside of class
    Gene(std::string id, std::string sequence, double propensity);

    Gene();

    //Accessor methods
    const std::string &getId() const {
        return id;
    }

    const std::string &getSequence() const {
        return sequence;
    }

    double getPropensity() const {
        return propensity;
    }

    //setPropensity - as on the assignment brief
    void setPropensity(double propensity) {
        Gene::propensity = propensity;
    }

    //class specific methods - display provides some information
    void display()
    {
        std::cout << "ID: "          << id << std::endl
                  << "Sequence: "    << sequence << std::endl
                  << "Propensity: "  << propensity << std::endl;
    }

private:

    //private variables
    std::string id, sequence;
    double propensity;

};

//constructor for Gene inline
inline Gene::Gene(std::string id, std::string sequence, double propensity)
{
    this -> id         = id;
    this -> sequence   = sequence;
    this -> propensity = propensity;
}

//default constructor
inline Gene::Gene()
{
    this -> id         = " ";
    this -> sequence   = " ";
    this -> propensity = 0.0;
}


//overriding IO operators
inline std::ostream& operator<<(std::ostream &os, const Gene &g)
{
    char c = '"';

    return os << c << g.getId() << c << ","
              << c << g.getSequence() << c << ","
              << g.getPropensity() << std::endl;
}

inline std::istream& operator>>(std::istream &is, Gene &g)
{
    std::string id, sequence;
    double propensity;

    char c;

    if (is >> std::quoted(id) >> c >> std::quoted(sequence) >> c >> propensity)
    {
        if (c == ',')
        {
            g = Gene(id, sequence, propensity);
        }
        else
        {
            is.clear(std::ios_base::failbit);
        }
    }
    return is;
}

//relational operators
inline bool operator == (const Gene &a, const Gene &b)
{
    return a.getPropensity() == b.getPropensity();
}

//these are in the Gene.cpp file
inline bool operator != (const Gene &a, const Gene &b);

inline bool operator <= (const Gene &a, const Gene &b);

inline bool operator >= (const Gene &a, const Gene &b);

inline bool operator<(const Gene &a, const Gene &b)
{
    if (a.getPropensity() < b.getPropensity()) return true;
    if (a.getPropensity() > b.getPropensity()) return false;

    return false;
}

inline bool operator > (const Gene &a, const Gene &b)
{
    if (a.getPropensity() > b.getPropensity()) return true;
    if (a.getPropensity() < b.getPropensity()) return false;

    return true;
}

inline bool testGene();

#endif