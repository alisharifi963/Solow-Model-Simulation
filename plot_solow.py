import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("solow_growth.csv")

plt.figure(figsize=(8, 5))
plt.plot(data["Time"], data["Capital"], label="Capital (K)", linewidth=2)
plt.plot(data["Time"], data["Output"], label="Output (Y)", linewidth=2)

plt.xlabel("Time")
plt.ylabel("Value")
plt.title("Solow Growth Model Simulation")
plt.legend()
plt.grid(True)

plt.show()
