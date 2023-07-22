import tkinter
#import tkMessageBox

top = tkinter.Tk()

C = tkinter.Canvas(top, bg="blue", height=500, width=400)
x1 = 10
y1 = 50
x2 = 240
y2 = 210
coord = x1, y1, x2, y2
arc = C.create_arc(coord, start=0, extent=150, fill="red")

C.pack()
top.mainloop()
