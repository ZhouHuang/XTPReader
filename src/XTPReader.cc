#include "XTPReader.hh"

void XTPReader::read_csv() {
    io::CSVReader<NCOL> rd(m_path);

    vector<string> info(NCOL, "");
    for (int i = 0; i<m_skip_rows; ++i) {
        try {
            rd.read_row(info[0], info[1], info[2], info[3]
                        ,info[4], info[5], info[6], info[7], info[8]
                        ,info[9],info[10],info[11]);
        } catch (...) {
            // skip rows...
        }
    }

    while(rd.read_row(info[0], info[1], info[2], info[3]
                ,info[4], info[5], info[6], info[7], info[8]
                ,info[9],info[10],info[11])){
        auto code = info[m_code_col];
        m_data[code].push_back(info);
        m_stk_code_list.insert(code);
    }
    
}

set<string> XTPReader::get_stocks_code_list() {
    return m_stk_code_list;
}

vector<vector<string>> XTPReader::get_stock_data(string stk_code) {
    return m_data[stk_code];
}

void XTPReader::to_csv(const char* path, const string& code) {
    //
}
