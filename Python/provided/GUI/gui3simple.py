# Hard-coded, ugly version

import tkinter as tk

root = tk.Tk()
canvas = tk.Canvas(root, width=300, height=500, borderwidth=0, highlightthickness=0) 

canvas.create_line(40, 75, 40, 200, width = 2, arrow=tk.LAST)

cir = canvas.create_oval(10, 50, 70, 110, fill="red")

coord = 10, 200, 70, 260

cir = canvas.create_oval(coord, fill="red")

canvas.create_text(50, 145, text='a') 

canvas.pack()

root.wm_title("Circles, lines, and Arcs")
root.mainloop()
