import matplotlib.pyplot as plt

# Belady's Anomaly Example (from hardcoded values)
frame_sizes = [3, 4]
fifo_faults = [9, 10]  # FIFO anomaly: more faults at 4 frames
lru_faults = [10, 8]   # LRU behaves as expected

plt.figure(figsize=(8, 5))
plt.plot(frame_sizes, fifo_faults, marker='o', label='FIFO (shows anomaly)')
plt.plot(frame_sizes, lru_faults, marker='o', label='LRU (no anomaly)')

plt.title("Belady’s Anomaly: Page Faults vs Frame Size")
plt.xlabel("Frame Size")
plt.ylabel("Page Faults")
plt.xticks(frame_sizes)
plt.grid(True)
plt.legend()

plt.tight_layout()
plt.savefig("data/belady_anomaly_graph.png")
plt.show()
