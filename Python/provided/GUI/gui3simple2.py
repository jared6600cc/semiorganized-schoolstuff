# Relatively prettier and more reusable

import tkinter as tk

def drawCir(x1,y1,x2,y2):
    cir1 = canvas.create_oval(x1,y1,x2,y2)
    cir2 = canvas.create_oval(x1+1,y1+1,x2-1,y2-1, fill="white")
    canvas.pack()

root = tk.Tk()
canvas = tk.Canvas(root, width=300, height=500, borderwidth=0, highlightthickness=0, bg="white")
canvas.grid()

canvas.create_line(30, 75, 30, 200, width = 2, arrow=tk.LAST)
canvas.create_text(50, 145, text='a') 
#coord = 10, 50, 70, 110

#cir = canvas.create_oval(10, 50, 70, 110, fill="red")
x1 = 10
y1 = 50
dia = 40
drawCir(x1,y1,x1+dia,y1+dia)
canvas.create_text(30, 70, text='0') 
y1 = 200
drawCir(x1,y1,x1+dia,y1+dia)
canvas.create_text(30, 220, text='1') 
root.wm_title("Circles, lines, and Arcs")
root.mainloop()
