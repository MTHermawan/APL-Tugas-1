import tkinter as tk
from PIL import Image, ImageTk

def Calculate():
    try:
        matrix = []
        min_value = 0
        mean_value = 0
        max_value = 0
        
        # Mengambil nilai dari input matriks
        for row in entries:
            row_values = []
            for entry in row:
                val = entry.get()

                # Jika input masih ada yang kosong atau tidak valid, hentikan perhitungan
                if val == "": 
                    min_label.config(text="")
                    mean_label.config(text="")
                    max_label.config(text="")
                    return
                else:
                    row_values.append(float(val))
            matrix.append(row_values)
    
        # Menghitung nilai minimum, rata-rata, dan maksimum
        for i in range(2):
            for j in range(3):
                if i == 0 and j == 0:
                    min_value = matrix[i][j]
                    mean_value = matrix[i][j]
                    max_value = matrix[i][j]
                else:
                    if matrix[i][j] < min_value:
                        min_value = matrix[i][j]
                    if matrix[i][j] > max_value:
                        max_value = matrix[i][j]
                    mean_value += matrix[i][j]

        mean_value /= len(matrix) * len(matrix[0])

        if min_value == int(min_value):
            min_value = int(min_value)
        if max_value == int(max_value):
            max_value = int(max_value)
        
        min_label.config(text=min_value)
        mean_label.config(text=f"{mean_value:.2f}")
        max_label.config(text=max_value)
    except ValueError:
        min_label.config(text="N/A")
        mean_label.config(text="N/A")
        max_label.config(text="N/A")

def EntryCallback(sv):
    Calculate()

assetPath = "./Assets/"

# Main program
root = tk.Tk()
root.title("Kalkulator Matrix")
root.geometry("480x600")

# Background image
bg_image = Image.open(assetPath + "KalkulatorMatriks_Background.png")
bg_image = bg_image.resize((480, 600))
bg_photo = ImageTk.PhotoImage(bg_image)

bg_label = tk.Label(root, image=bg_photo)
bg_label.place(x=0, y=0)

# Matrix box image
box_image = Image.open(assetPath + "KalkulatorMatriks_Box.png")
box_image = box_image.resize((350, 200))
box_photo = ImageTk.PhotoImage(box_image)

matrix_frame = tk.Label(root, image=box_photo, bd=0)
matrix_frame.place(x=70, y=100)

# Input matriks (2x3)
entries = []
for i in range(2):
    row_entries = []
    for j in range(3):
        entry = tk.Entry(root, font=("Arial", 28), width=5, justify='center', bg="#fee9ca")
        entry.place(x=75 + j*115, y=130 + i*95)
        sv = tk.StringVar()
        sv.trace("w", lambda name, index, mode, sv=sv: EntryCallback(sv))
        entry.config(textvariable=sv)
        row_entries.append(entry)
    entries.append(row_entries)

# Output box image
output_box_image = Image.open(assetPath + "KalkulatorMatriks_OutputBox.png")
output_box_image = output_box_image.resize((350, 110))
output_box_photo = ImageTk.PhotoImage(output_box_image)

output_frame = tk.Label(root, image=output_box_photo, bd=0)
output_frame.place(x=70, y=410)

# Teks label output perhitungan
min_label = tk.Label(root, text="", font=("Arial", 16, "bold"), width=8, bg="#fee9ca")
min_label.place(x=75, y=485)

mean_label = tk.Label(root, text="", font=("Arial", 16, "bold"), width=8, bg="#fee9ca")
mean_label.place(x=195, y=485)

max_label = tk.Label(root, text="", font=("Arial", 16, "bold"), width=7, bg="#fee9ca")
max_label.place(x=315, y=485)

# Menjalankan program
root.mainloop()
