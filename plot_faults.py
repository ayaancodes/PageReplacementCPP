import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("data/page_faults.csv")

plt.figure(figsize=(10, 6))
plt.plot(df["FrameSize"], df["FIFO"], marker='o', label='FIFO')
plt.plot(df["FrameSize"], df["LRU"], marker='o', label='LRU')
plt.title("Page Faults vs Frame Size")
plt.xlabel("Frame Size")
plt.ylabel("Page Faults")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("data/page_faults_graph.png")
plt.show()
