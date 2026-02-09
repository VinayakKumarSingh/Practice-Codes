import tkinter as tk
from tkinter import messagebox
import math
import time

class JosephusSimulation:
    def __init__(self, master):
        self.master = master
        master.title("Josephus Problem Simulation")

        # Input for number of people
        self.label_n = tk.Label(master, text="Number of People (n):")
        self.label_n.pack()
        self.entry_n = tk.Entry(master)
        self.entry_n.pack()

        # Input for step count
        self.label_k = tk.Label(master, text="Step Count (k):")
        self.label_k.pack()
        self.entry_k = tk.Entry(master)
        self.entry_k.pack()

        # Start button
        self.start_button = tk.Button(master, text="Start Simulation", command=self.start_simulation)
        self.start_button.pack()

        # Reset button
        self.reset_button = tk.Button(master, text="Reset", command=self.reset)
        self.reset_button.pack()

        # Canvas for drawing
        self.canvas = tk.Canvas(master, width=400, height=400, bg='white')
        self.canvas.pack()

        self.people = []
        self.radius = 150  # Radius of the circle

    def josephus(self, n, k):
        people = list(range(1, n + 1))
        index = 0
        elimination_order = []

        while len(people) > 1:
            index = (index + k - 1) % len(people)
            elimination_order.append(people.pop(index))
            self.update_display(people, elimination_order)

        return people[0]

    def update_display(self, people, elimination_order):
        self.canvas.delete("all")  # Clear the canvas
        angle_step = 360 / len(people)  # Angle between each person

        # Draw remaining people
        for i, person in enumerate(people):
            angle = math.radians(i * angle_step)
            x = 200 + self.radius * math.cos(angle)
            y = 200 + self.radius * math.sin(angle)
            self.canvas.create_oval(x - 20, y - 20, x + 20, y + 20, fill='lightblue', outline='black')
            self.canvas.create_text(x, y, text=str(person), font=("Arial", 12))

        # Highlight eliminated person
        if elimination_order:
            eliminated_person = elimination_order[-1]
            index = elimination_order.index(eliminated_person)
            angle = math.radians(index * angle_step)
            x = 200 + self.radius * math.cos(angle)
            y = 200 + self.radius * math.sin(angle)
            self.canvas.create_oval(x - 20, y - 20, x + 20, y + 20, fill='red', outline='black')
            self.canvas.create_text(x, y, text=str(eliminated_person), font=("Arial", 12), fill='white')

        self.master.update()
        time.sleep(1)  # Pause for a second to visualize the elimination

    def start_simulation(self):
        try:
            n = int(self.entry_n.get())
            k = int(self.entry_k.get())
            if n <= 0 or k <= 0:
                raise ValueError("Both n and k must be positive integers.")
            last_person = self.josephus(n, k)
            messagebox.showinfo("Result", f"The last person standing is: {last_person}")
        except ValueError as e:
            messagebox.showerror("Input Error", str(e))

    def reset(self):
        self.entry_n.delete(0, tk.END)
        self.entry_k.delete(0, tk.END)
        self.canvas.delete("all")

if __name__ == "__main__":
    root = tk.Tk()
    app = JosephusSimulation(root)
    root.mainloop()
