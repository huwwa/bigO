import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data.csv")

df.columns = df.columns.str.strip()

plt.plot(df['n'], df['T(n)'], linestyle='-')
plt.xlabel("n")
plt.ylabel("T(n)")
plt.grid(True)
plt.xticks(rotation=45)
plt.tight_layout()

plt.savefig("plot.png")

plt.clf()
