import tkinter as tk

root = tk.Tk()
canvas = tk.Canvas(root, width=300, height=500, borderwidth=0, highlightthickness=0, bg="white")
canvas.grid()

def _create_circle(self, x, y, r, **kwargs):
    return self.create_oval(x-r, y-r, x+r, y+r, **kwargs)
tk.Canvas.create_circle = _create_circle

def _create_circle_arc(self, x, y, r, **kwargs):
    if "start" in kwargs and "end" in kwargs:
        kwargs["extent"] = kwargs["end"] - kwargs["start"]
        del kwargs["end"]
    return self.create_arc(x-r, y-r, x+r, y+r, **kwargs)
tk.Canvas.create_circle_arc = _create_circle_arc

#def _create_line(self, x1, y1, x2, y2, **kwargs):
#    return self.create_line(x1, y1, x2, y2, **kwargs)
#tk.Canvas.create_line = _create_line

canvas.create_line(100, 100, 100, 450, width = 2, arrow=tk.LAST)

canvas.create_circle(100, 120, 50, fill="blue", outline="#DDD", width=4)
canvas.create_circle_arc(100, 120, 48, fill="green", outline="", start=45, end=140)
canvas.create_circle_arc(100, 120, 48, fill="green", outline="", start=275, end=305)
canvas.create_circle_arc(100, 120, 45, style="arc", outline="white", width=6, start=270-25, end=270+25)
canvas.create_circle(150, 40, 20, fill="#BBB", outline="")



root.wm_title("Circles, lines, and Arcs")
root.mainloop()
