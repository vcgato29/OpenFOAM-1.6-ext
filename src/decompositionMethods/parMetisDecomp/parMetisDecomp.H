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
    Foam::parMetisDecomp

Description

SourceFiles
    parMetisDecomp.C

\*---------------------------------------------------------------------------*/

#ifndef parMetisDecomp_H
#define parMetisDecomp_H

#include "decompositionMethod.H"

namespace Foam
{

/*---------------------------------------------------------------------------*\
                        Class parMetisDecomp Declaration
\*---------------------------------------------------------------------------*/

class parMetisDecomp
:
    public decompositionMethod
{
    // Private data

        const polyMesh& mesh_;


    // Private Member Functions

        //- Disallow default bitwise copy construct
        parMetisDecomp(const parMetisDecomp&);

        //- Disallow default bitwise assignment
        void operator=(const parMetisDecomp&);


        //- Insert list in front of list
        template<class Type>
        static void prepend(const UList<Type>&, List<Type>&);

        //- Insert list at end of list
        template<class Type>
        static void append(const UList<Type>&, List<Type>&);

        label decompose
        (
            Field<int>& xadj,
            Field<int>& adjncy,
            const pointField& cellCentres,
            Field<int>& cellWeights,
            Field<int>& faceWeights,
            const List<int>& options,

            List<int>& finalDecomp
        );


public:

    //- Runtime type information
    TypeName("parMetis");


    // Constructors

        //- Construct given the decomposition dictionary and mesh
        parMetisDecomp
        (
            const dictionary& decompositionDict,
            const polyMesh& mesh
        );


    // Destructor

        ~parMetisDecomp()
        {}


    // Member Functions

        //- parMetis handles Foam processor boundaries
        virtual bool parallelAware() const
        {
            return true;
        }

        //- Decompose cells with weights
        virtual labelList decompose
        (
            const pointField& points,
            const scalarField& pointWeights
        );

        //- Decompose cell clusters with weights on clusters
        virtual labelList decompose
        (
            const labelList& cellToRegion,
            const pointField& regionPoints,
            const scalarField& regionWeights
        );

        //- Decompose cells with weights with explicitly provided connectivity
        virtual labelList decompose
        (
            const labelListList& globalCellCells,
            const pointField& cc,
            const scalarField& cWeights
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include "parMetisDecompTemplates.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
