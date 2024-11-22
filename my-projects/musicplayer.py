import tkinter as tk #used to create Graphical User Interfaces (GUIs)
from tkinter import ttk
from tkinter import filedialog
import pygame
import os
from tkinter import messagebox
import requests
from io import BytesIO
from PIL import Image, ImageTk #Python Imaging Library (PIL)

#Creating main class and creating the root window
class MusicPlayer:

    def __init__(self,root,bg_image_url): #root window
        self.root = root

        #title and sizing
        self.root.title("Yolia's Music Player~")
        self.root.geometry("700x600")
        self.root.resizable(True, True)

        #setting the background image from web URL
        try:
            response = requests.get(bg_image_url) #get image from URL
            response.raise_for_status() #raise error for bad responses
            img_data = BytesIO(response.content) #converts image content to bytes
            image = Image.open(img_data) #open image using PIL
            image = image.resize((700, 600), Image.LANCZOS) #resizes to fit window
            self.bg_image =  ImageTk.PhotoImage(image) #converts to PhotoImage
            self.bg_label = ttk.Label(self.root, image=self.bg_image)
            self.bg_label.place(relx=0, rely=-0, relwidth=1, relheight=1)
        except Exception as e:
            print(f"Error: Cannot load background image from URL. {e}")

        #styling window
        s = ttk.Style()
        s.theme_use('clam')
        s.configure('.', background='black', foreground='black')
        s.configure('TFrame', background='white', foreground='white')
        s.configure('TButton', font=('Arial', 12), background='black', foreground='white',
                                            activebackground='brown', activeforeground='white')
        s.configure('TLabel', font=('Arial', 12), background='black', foreground='white')
        s.configure('TScale', background='white')

        # Initializing Pygame
        pygame.init()

        # Initializing Pygame Mixer
        pygame.mixer.init()
if __name__ == "__main__":
    root = tk.Tk()
    bg_image_url = "https://i.pinimg.com/736x/14/2a/5c/142a5c966dfc0dc5064b85a40b031fdd.jpg"
    player = MusicPlayer(root, bg_image_url)
    root.mainloop()