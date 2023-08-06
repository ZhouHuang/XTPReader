#pragma once

#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <set>
#include <filesystem>
#include <iostream>
#include <fstream>

#include "csv.h"

using std::map;
using std::unordered_map;
using std::string;
using std::vector;
using std::set;
class XTPReader {
  public:
    explicit XTPReader(const char* path
                    , int code_col
                    , int header=-1
                    , int skiprows=0
                    , bool ignore_BOM=true)
     : m_path{path} , m_code_col{code_col} , m_header{header}
     , m_skip_rows{skiprows} , m_ignore_BOM{ignore_BOM}
     {
         if (-1 != header) {
             throw std::runtime_error("input header not implemented");
         }
     };

    XTPReader(const XTPReader&) = delete;

    void read_csv();

    void to_csv(const char*, const string& , const string&);

    set<string> get_stocks_code_list();

    vector<vector<string>> get_stock_data(string stk_code);

  private:
    static const int NCOL{12};
    string m_path;
    int m_code_col;
    int m_header;
    int m_skip_rows;
    bool m_ignore_BOM;

    set<string> m_stk_code_list;
    
    unordered_map<string, vector<vector<string>> > m_data;
};
