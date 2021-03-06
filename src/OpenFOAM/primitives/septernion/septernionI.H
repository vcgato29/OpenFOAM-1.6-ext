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

\*---------------------------------------------------------------------------*/

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline Foam::septernion::septernion()
{}

inline Foam::septernion::septernion(const vector& t, const quaternion& r)
:
    t_(t),
    r_(r)
{}

inline Foam::septernion::septernion(const vector& t)
:
    t_(t),
    r_(quaternion::I)
{}

inline Foam::septernion::septernion(const quaternion& r)
:
    t_(vector::zero),
    r_(r)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline const Foam::vector& Foam::septernion::t() const
{
    return t_;
}


inline const Foam::quaternion& Foam::septernion::r() const
{
    return r_;
}


inline Foam::vector& Foam::septernion::t()
{
    return t_;
}


inline Foam::quaternion& Foam::septernion::r()
{
    return r_;
}


inline Foam::vector Foam::septernion::transform(const vector& v) const
{
    return t() + r().transform(v);
}


inline Foam::vector Foam::septernion::invTransform(const vector& v) const
{
    return r().invTransform(v - t());
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

inline void Foam::septernion::operator=(const septernion& tr)
{
    t_ = tr.t_;
    r_ = tr.r_;
}

inline void Foam::septernion::operator*=(const septernion& tr)
{
    t_ += r().transform(tr.t());
    r_ *= tr.r();
}


inline void Foam::septernion::operator=(const vector& t)
{
    t_ = t;
}

inline void Foam::septernion::operator+=(const vector& t)
{
    t_ += t;
}

inline void Foam::septernion::operator-=(const vector& t)
{
    t_ -= t;
}


inline void Foam::septernion::operator=(const quaternion& r)
{
    r_ = r;
}

inline void Foam::septernion::operator*=(const quaternion& r)
{
    r_ *= r;
}

inline void Foam::septernion::operator/=(const quaternion& r)
{
    r_ /= r;
}


inline void Foam::septernion::operator*=(const scalar s)
{
    t_ *= s;
    r_ *= s;
}

inline void Foam::septernion::operator/=(const scalar s)
{
    t_ /= s;
    r_ /= s;
}


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

inline Foam::septernion Foam::inv(const septernion& tr)
{
    return septernion(-tr.r().invTransform(tr.t()), conjugate(tr.r()));
}


// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

inline bool Foam::operator==(const septernion& tr1, const septernion& tr2)
{
    return (tr1.t() == tr2.t() && tr1.r() == tr2.r());
}


inline bool Foam::operator!=(const septernion& tr1, const septernion& tr2)
{
    return !operator==(tr1, tr2);
}


inline Foam::septernion Foam::operator+
(
    const septernion& tr,
    const vector& t
)
{
    return septernion(tr.t() + t, tr.r());
}


inline Foam::septernion Foam::operator+
(
    const vector& t,
    const septernion& tr
)
{
    return septernion(t + tr.t(), tr.r());
}


inline Foam::septernion Foam::operator+
(
    const septernion& tr1,
    const septernion& tr2
)
{
    return septernion(tr1.t() + tr2.t(), tr1.r() + tr2.r());
}


inline Foam::septernion Foam::operator-
(
    const septernion& tr,
    const vector& t
)
{
    return septernion(tr.t() - t, tr.r());
}


inline Foam::septernion Foam::operator-
(
    const septernion& tr1,
    const septernion& tr2
)
{
    return septernion(tr1.t() - tr2.t(), tr1.r() - tr2.r());
}


inline Foam::septernion Foam::operator*
(
    const quaternion& r,
    const septernion& tr
)
{
    return septernion(tr.t(), r*tr.r());
}


inline Foam::septernion Foam::operator*
(
    const septernion& tr,
    const quaternion& r
)
{
    return septernion(tr.t(), tr.r()*r);
}


inline Foam::septernion Foam::operator/
(
    const septernion& tr,
    const quaternion& r
)
{
    return septernion(tr.t(), tr.r()/r);
}


inline Foam::septernion Foam::operator*
(
    const septernion& tr1,
    const septernion& tr2
)
{
    return septernion
    (
        tr1.t() + tr1.r().transform(tr2.t()),
        tr1.r().transform(tr2.r())
    );
}


inline Foam::septernion Foam::operator/
(
    const septernion& tr1,
    const septernion& tr2
)
{
    return tr1*inv(tr2);
}


inline Foam::septernion Foam::operator*(const scalar s, const septernion& tr)
{
    return septernion(s*tr.t(), s*tr.r());
}


inline Foam::septernion Foam::operator*(const septernion& tr, const scalar s)
{
    return septernion(s*tr.t(), s*tr.r());
}


inline Foam::septernion Foam::operator/(const septernion& tr, const scalar s)
{
    return septernion(tr.t()/s, tr.r()/s);
}


// ************************************************************************* //
