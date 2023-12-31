#include "XTPReader.hh"

void XTPReader::read_csv(int ex) {
    /*
    *   ex = 1, SH, ex = 2, SZ
    */
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
        if (code.size() > 6) {
            continue;
        }
        if (code.size() < 6) {
            code = string(6-code.size(), '0') + code;
        }
        if (1 == ex) {
            if (code.at(0) != '6') {
                continue;
            }
        } else if (2 == ex) {
            if (code.at(0) != '3' && code.at(0) != '0') {
                continue;
            }
        }
        info[m_code_col] = code;
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

void XTPReader::to_csv(const char* path, const string& code, const string& dt) {
    if (nullptr == path) {
        throw std::runtime_error("input path is empty");
    } else {
        if (0 == strlen(path)) {
            throw std::runtime_error("input path is empty");
        }
    }
    string f_path = "";
    if ('/' != path[0]) {
        f_path = string(fs::current_path()) + "/" + string(path) + "/" + code + "_" + dt + ".csv";
    } else {
        f_path = string(path) + "/" + code + "_" + dt + ".csv";
    }

    if (fs::exists(f_path)) {
        std::cout << "file path " << f_path << " code " << code  << " dt " << dt << std::endl;
        throw std::runtime_error(" already exists.");
    }
    std::ofstream outFile(f_path, std::ios::out);

	if (!outFile.is_open()) {
        std::cout << "file path " << f_path << " code " << code  << " dt " << dt << std::endl;
        throw std::runtime_error(" can not be opened");
    } else {
        for (const auto& line : m_data[code]) {
            for(int i = 0; i< line.size();  ++ i){
                outFile << line.at(i);
                if (i != line.size()-1) outFile << ',';
            }
            outFile << std::endl;
        }
	}
    outFile.close();

}
