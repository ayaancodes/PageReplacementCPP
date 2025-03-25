# Lab 3: Page Replacement Algorithms

## Overview
This project simulates and analyzes classic page replacement algorithms—**FIFO** and **LRU**—using a page reference string. It evaluates their behavior under varying frame sizes and investigates **Belady's Anomaly** through both a known sequence and a programmatically generated one.

---

## Features Implemented

### ✅ Question 1: Page Reference Generator
- A reference string is loaded from `data/references.txt`
- The string contains 1000 randomly generated page numbers ranging from 1 to 20
- Simulates realistic page access patterns

### ✅ Question 2: Page Replacement Algorithms
- Implements both **FIFO** and **LRU** algorithms
- Simulates each algorithm for **frame sizes 1 through 10**
- Outputs total page faults for each algorithm and frame size
- Results are exported to `data/page_faults.csv`
- A Python script (`plot_faults.py`) generates the graph `data/page_faults_graph.png`

### ✅ Question 3: Belady’s Anomaly
- Tests FIFO using the known Belady anomaly sequence: `1 2 3 4 1 2 5 1 2 3 4 5`
- Confirms the anomaly where page faults **increase** with more frames
- Also tests LRU for the same input (which does not show the anomaly)
- ✅ Bonus: Programmatically generates random sequences and finds a valid Belady anomaly case using seeds
- Graph `data/belady_anomaly_graph.png` plots FIFO and LRU results for 3 and 4 frames

---

## File Structure

```
.
├── data/
│   ├── references.txt                # Input page reference stream
│   ├── page_faults.csv              # Output of frame sizes vs faults
│   ├── page_faults_graph.png        # Graph for Question 2
│   └── belady_anomaly_graph.png     # Graph for Question 3
│
├── src/
│   ├── main.cpp                     # Main driver for simulation
│   ├── q1_generator.cpp/.h         # (Optional) Page reference generator
│   ├── q2_algorithms.cpp/.h        # FIFO and LRU implementations
│   ├── q3_belady.cpp/.h            # Belady anomaly detection
│   └── utils.cpp/.h                # Helper methods (if used)
│
├── plot_faults.py                  # Graphs Q2 results
├── plot_belady.py                  # Graphs Q3 Belady anomaly
├── Makefile                        # Build instructions
└── README.md                       # This file
```

---

## How to Compile & Run

### 💪 Prerequisites
- C++17 compatible compiler (e.g., `g++`)
- Python 3 with `matplotlib` and `pandas` installed

### 📟 Build the program

```bash
make
```

### ▶️ Run the simulation

```bash
./lab3
```

You will see:
- Page fault counts for FIFO and LRU (Question 2)
- CSV output in `data/page_faults.csv`
- Belady’s anomaly test results (Question 3)

---

## Plot the Graphs

### 📊 Question 2: FIFO vs LRU

```bash
python3 plot_faults.py
```

Generates: `data/page_faults_graph.png`

### 📈 Question 3: Belady’s Anomaly

```bash
python3 plot_belady.py
```

Generates: `data/belady_anomaly_graph.png`

---

## Submission Requirements Met ✅

| Requirement | Status |
|------------|--------|
| Page reference string generated | ✅ Yes (from `references.txt`) |
| FIFO and LRU algorithms tested | ✅ Yes |
| Page faults plotted for frames 1-10 | ✅ Yes, see `page_faults_graph.png` |
| Belady’s anomaly shown (known sequence) | ✅ Yes |
| Bonus: Sequence **programmatically generated** showing anomaly | ✅ Yes |
| Belady anomaly graph | ✅ Yes, see `belady_anomaly_graph.png` |
| Code organized and clean | ✅ Yes |

---

## Notes
- You may adjust the reference string or frame sizes as needed in `main.cpp`
- Seed range and randomness in `q3_belady.cpp` can be tuned to test deeper anomalies

---

## Author
**Ayaan Munshi**  
Western University – SE3313B: Operating Systems

