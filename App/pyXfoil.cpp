/*# -*- coding: utf-8 -*-
#################################################
#
# ASK13 - Airfoil creation - Aircraft
#
# F. Nivoix - 2020 - V0.4
# For FreeCAD Versions = or > 0.17 Revision xxxx
#
# Works best with OCC/OCE = or > 6.7
# boost wrapping to Xfoil library
#
################################################*/

#include <boost/python.hpp>
#include "XFoil-lib/xfoil.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(pyxfoil)
{
    class_< XFoil >("XFoil", )
    .def("interpolate", Xfoil::interpolate)//(double xf1[], double yf1[], int n1, double xf2[], double yf2[], int n2, double mixt))
    .def("CheckAngles",Xfoil::CheckAngles)
    .def("Preprocess"Xfoil::Preprocess);
}
