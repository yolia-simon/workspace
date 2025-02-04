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

    def __init__(self,root): #root window
        self.root = root

        #title and sizing
        self.root.title("Yolia's Music Player~")
        self.root.geometry("700x600")
        self.root.resizable(True, True)

        T = tk.Text(root, height=5, width = 52)
        intro = "Welcome to my music player! <3"
        T.grid(row=0,column=0, columnspan=2, pady=(10,20))
        T.insert(tk.END, intro)

        # Setting the background image
        self.bg_image =  tk.PhotoImage(file = os.path.join(os.getcwd(), "my-projects/music-player/imgfolder", "background.png"))
        self.bg_label = ttk.Label(self.root, image=self.bg_image)
        self.bg_label.place(relx=0, rely=-0, relwidth=1, relheight=1)

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

        #playlist frame - holds list of songs in playlist
        self.playlist_frame = tk.Frame(self.root)
        self.playlist_frame.grid(row=0, column=0, padx=10, pady=10)

        #listbox - displays list of songs
        #error here
        self.playlist = tk.Listbox(self.playlist_frame, width=40, height=20)
        self.playlist.pack(fill=tk.BOTH, expand=True)
        self.playlist.bind("<<ListboxSelect>>", self.play_selected_song)

    #control frame - holds play/pause/skip back/skip forward buttons as well as volume control
        self.control_frame = ttk.Frame(self.root)
        self.control_frame.grid(row=0, column=1, padx=10, pady=10)
        self.control_frame.configure(border=1, relief="groove", borderwidth=2)

        #background img for control frame
        self.bg_image3 = tk.PhotoImage(file= os.path.join(os.getcwd(), "my-projects/music-player/imgfolder", "pinkgradient.png"))#enter name of file
        self.bg_image3 = ttk.Label(self.control_frame, image=self.bg_image3)
        self.bg_image3.place(relx=0, rely=0, relheight=1, relwidth=1)

        #Play/Pause button
        self.play_var = tk.StringVar()
        self.play_var.set("Play")
        self.play_pause_button = ttk.Button(self.control_frame, textvariable=self.play_var, command=self.play_pause)
        self.play_pause_button.grid(row=1, column=0, padx=10, pady=10)

        #skip back/forward buttons
        self.skip_backward_button = ttk.Button(self.control_frame, text="⏪", command=self.skip_backward)
        self.skip_backward_button.grid(row=2, column=0, padx=10, pady=10)
        self.skip_forward_button = ttk.Button(self.control_frame, text="⏩", command=self.skip_backward)
        self.skip_forward_button.grid(row=3, column=0, padx=10, pady=10)

        #displays status of current song and volume control feature
        self.status_var = tk.StringVar()
        self.status_var.set("Volume Control")
        self.status_label = ttk.Label(self.control_frame, textvariable=self.status_var)
        self.status_label.grid(row=4, column=0, padx=10, pady=10)
        self.volume_var = tk.DoubleVar() # Volume control
        self.volume_scale = ttk.Scale(self.control_frame, orient="horizontal", from_=0, to=1,variable=self.volume_var, command=self.set_volume)
        self.volume_scale.grid(row=5, column=0, padx=10, pady=10)

        #import music button
        self.import_button = ttk.Button(self.control_frame, text="Import Music Files", command=self.import_music)
        self.import_button.grid(row=6, column=0, padx=10,pady=10)

        #progress bar
        self.progress_bar = ttk.Progressbar(self.control_frame, orient='horizontal', length=325, mode="determinate")
        self.progress_bar.grid(row=8, column=0, padx=10, pady=10)

        #shows how much time has elapsed in the song
        self.elapsed_time = ttk.Label(self.control_frame, text="00:00")
        self.elapsed_time.grid(row=9, column=0, padx=10, pady=10)

        #displays current song
        self.current_song = ""

        #checks if song is paused or not
        self.paused = False

    def play_selected_song(self, event): #function that plays selected song
        selection = self.playlist.curselection()
        if not selection: #no song selected
            messagebox.showerror("Error", "No song has been selected. Please select your song before playing.")
            return

        selected_song = self.playlist.get(selection[0]) # gets first selected item
        self.current_song = selected_song

        try:
            pygame.mixer.music.load(self.current_song)
            self.status_var.set("Now Playing: " + os.path.basename(self.current_song)[0:40]+"...")
            self.progress_bar["maximum"] = pygame.mixer.Sound(self.current_song).get_length()
            self.update_progressbar()
            pygame.mixer.music.play()
            self.play_var.set("Pause")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to play the song.\n{e}")

    def play_pause(self): # function to play/pause current song using if loop
        if self.paused:
            pygame.mixer.music.unpause()
            self.paused = False
            self.play_var.set("Pause")
        else:
            pygame.mixer.music.pause()
            self.paused = True
            self.play_var.set("Play")

    # Function to skip to the previous song
    # using the skip backward button
    def skip_backward(self):
        # skip to the previous song
        selection = self.playlist.curselection()
        if selection:
            prev_song_index = int(selection[0]) - 1
            if prev_song_index >= 0:
                prev_song = self.playlist.get(prev_song_index)
                self.current_song = prev_song
                pygame.mixer.music.load(self.current_song)
                self.status_var.set("Now Playing: " + os.path.basename(self.current_song)[0:40]+"...")
                pygame.mixer.music.play()
                self.play_var.set("Pause")
            else:
                messagebox.showwarning("Warning", "This is the first song.")
        else:
            messagebox.showerror("Error", "No song is selected.")

    # Function to set the volume
    # using the volume scale
    def set_volume(self, val):
        volume = float(val)
        pygame.mixer.music.set_volume(volume)


    # Function to import music files
    # using the import button
    def import_music(self):
        # import multiple music files from the local directory
        file_paths = filedialog.askopenfilenames()
        for file_path in file_paths:
            #if already in the playlist, don't add it again
            if file_path not in self.playlist.get(0, tk.END):
                self.playlist.insert(tk.END, file_path)

    # Function to update the progress bar
    def update_progressbar(self):
        current_time = pygame.mixer.music.get_pos() / 1000
        self.progress_bar["value"] = current_time
        minutes, seconds = divmod(int(current_time), 60)
        self.elapsed_time.config(text="{:02d}:{:02d}".format(minutes, seconds))
        self.root.after(1000, self.update_progressbar)


#main program starts here
root = tk.Tk()
MusicPlayer(root)

#runs main window loop
root.mainloop()
