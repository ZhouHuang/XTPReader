import pandas as pd 
import numpy as np 

from XTPReader import XTPReader

def main():
    path = "./test/demo_t.csv"
    
    code_col = 6
    header=-1
    skiprows=2
    rd = XTPReader(path, code_col, header, skiprows)

    rd.read_csv()
    stk_list = rd.get_stocks_code_list()

    for code in stk_list:
        data = rd.get_stock_data(code)
        for line in data:
            for content in line:
                print(content, end=" ")
            print()


    out_path = './t1'
    code = '000629'
    dt = '20230801'
    rd.to_csv(out_path, code, dt)

if __name__ == '__main__':
    main()