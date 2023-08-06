# Fast XTP data txt reader


- Feature implementation

```python
df = pd.read_csv(f'{des_path}/{csv_name}',  skiprows=1, header=None)

am_df[code_col] = am_df[code_col].apply(lambda s : str(s).lstrip('\ufeff').zfill(6))
_stock_list = list(am_df[code_col].unique())
_stock_list = [s for s in _stock_list if len(s)==6 and (s[0] == '0' or s[0]=='3')]

df[df[0]==code].reset_index(drop=True).to_csv(f'{out_path}/{code[:6]}_{dt}.csv',header= False, index=False)

```
