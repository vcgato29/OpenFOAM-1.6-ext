/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    Foam::C

Description
    Graphite

SourceFiles
    C.C

\*---------------------------------------------------------------------------*/

#ifndef solid_C_H
#define solid_C_H

#include "solid.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class C;

Ostream& operator<<
(
     Ostream&,
     const C&
);


/*---------------------------------------------------------------------------*\
                            Class C Declaration
\*---------------------------------------------------------------------------*/

class C
:
    public solid
{
public:

    //- Runtime type information
    TypeName("C");


    // Constructors

        //- Construct null
        C();

        //- Construct from solid
        C(const solid& s);

        //- Construct from Istream
        C(Istream& is);


    // I-O

        //- Write the function coefficients
        void writeData(Ostream& os) const;


    //- Ostream Operator
    friend Ostream& operator<<(Ostream& os, const C& s);
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
