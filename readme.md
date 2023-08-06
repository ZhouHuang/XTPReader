# Fast XTP data txt reader


- Feature implementation

```python
df = pd.read_csv(f'{des_path}/{csv_name}',  skiprows=1, header=None)

df[df[0]==code].reset_index(drop=True).to_csv(f'{out_path}/{code[:6]}_{dt}.csv',header= False, index=False)

```
