from Tkinter import *
from tkFileDialog import *

filename = None

def newfile():
    global filename
    filename="Untitled"
    text.delete(0.0,END)

def savefile():
    global filename
    t = text.get(0.0,END)
    f = open(filename,'w')
    f.write(t)
    f.close()

def saveas():
    f=asksaveasfile(mode='w')
    t=text.get(0.0,END)
    try:
        f.write(t.rstrip())
    except:
        showerror(title="Oops!",message="Unable to save file...")

def openfile():
    global filename
    f=askopenfile(mode='r')
    filename=f.name
    t=f.read()
    text.delete(0.0,END)
    text.insert(0.0,t)

root = Tk()
root.title("My Python Text Editor")
root.minsize(width=400,height=400)
root.maxsize(width=400,height=400)


text=Text(root,width=400,height=400)
text.pack()

menubar = Menu(root)
filemenu = Menu(menubar)
filemenu.add_command(label="New",command=newfile)
filemenu.add_command(label="Open",command=openfile)
filemenu.add_command(label="Save",command=savefile)
filemenu.add_command(label="SaveAs...",command=saveas)

filemenu.add_separator()
filemenu.add_command(label="Quit",command=root.quit)
menubar.add_cascade(label="File",menu=filemenu)

root.config(menu=menubar)
root.mainloop()
