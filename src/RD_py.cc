#include "XTPReader.hh"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>

namespace py = pybind11;

PYBIND11_MODULE(XTPReader, m) {

    m.doc() = "pybind11 module for xtp data reading";

    py::class_< XTPReader >(m, "XTPReader")
        .def(py::init<const char*, int, int, int>())
        .def("read_csv", &XTPReader::read_csv)
        .def("get_stocks_code_list", &XTPReader::get_stocks_code_list)
        .def("get_stock_data", &XTPReader::get_stock_data)
        .def("to_csv", &XTPReader::to_csv);

}