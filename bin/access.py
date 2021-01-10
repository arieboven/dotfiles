#!/usr/bin/python

import tkinter as tk
import tkinter.font as font

root = tk.Tk()
root.configure(bg='#00AA00')
root.title("accessgranted")
label = tk.Label(root, bg="#000000", fg="#00AA00", text="ACCESS GRANTED", padx=20, pady=20)
label.configure(font=font.Font(family="Arimo Nerd Font Mono",size=50))
label.pack(fill="both", expand="true", padx=2, pady=2)

root.mainloop()
