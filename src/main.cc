#include "XTPReader.hh"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    const string path = "./test/demo_t.csv";

    int code_col = 6;
    int header = -1;
    int skiprows = 2;
    XTPReader rd(path.c_str(), code_col, header, skiprows);

    int ex = 2;
    rd.read_csv(ex);
    auto stk_list = rd.get_stocks_code_list();

    for (const auto &code : stk_list) {
        printf("code %s\n", code.c_str());
        auto data = rd.get_stock_data(code);
        for (const auto &line : data) {
            for (const auto &content : line) {
                cout << content << " ";
            }
            cout << endl;
        }
    }

    const char* out_path = "./";
    string dt = "20230803";

    for (const auto &code : stk_list) {

        printf("code %s\n", code.c_str());
        rd.to_csv(out_path, code, dt);
    }

    return 0;
}
