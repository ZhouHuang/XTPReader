#include "XTPReader.hh"

#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(XTPReader, m) {

    m.doc() = "pybind11 module for xtp data reading";

    py::class_< XTPReader >(m, "XTPReader")
        .def(py::init<const char*, int, int, char, int, bool>());

}