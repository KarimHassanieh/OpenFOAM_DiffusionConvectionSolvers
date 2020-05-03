/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2020 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    Steady Diffusion

Description

\*---------------------------------------------------------------------------*/

#include "fvCFD.H"
#include "simpleControl.H"
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{



    #include "setRootCase.H"
    #include "createTime.H"
    #include "createMesh.H"
    #include "createFeild.H"
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
    simpleControl simple(mesh);
//    Info<<nl<<"Mesh details = "<<endl;
//    Info<<nl<<"Mesh Center details = "<<endl;
//    Info<<mesh.C()<<endl;
//    Info<<nl<<"Mesh Volume details = "<<endl;
//    Info<<mesh.V()<<endl;
//    Info<<nl<<"Mesh Surface details = "<<endl;
//    Info<<mesh.Cf()<<endl;



while(simple.loop(runTime)){

     fvScalarMatrix Eqn
      (

        fvm::laplacian(Diffusivity,T)

       );
       Eqn.solve();

  if (runTime.outputTime())
    {
        runTime.write();
    }
  }     



   
    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
