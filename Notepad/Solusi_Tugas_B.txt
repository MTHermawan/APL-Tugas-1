def cek_tripel_pythagoras(a, b, c):
    sisi = sorted([a, b, c])
    x, y, z = sisi
    print(f"\nMenguji apakah {z}² = {x}² + {y}²")
    print(f"{z**2} = {x**2} + {y**2}")
    print(f"{z**2} = {x**2 + y**2}")
    if z**2 == x**2 + y**2:
        print(f"{x}, {y}, dan {z} membentuk Tripel Pythagoras!")
    else:
        print(f"{x}, {y}, dan {z} BUKAN Tripel Pythagoras.")

a = int(input("Masukkan nilai a: "))
b = int(input("Masukkan nilai b: "))
c = int(input("Masukkan nilai c: "))
    
cek_tripel_pythagoras(a, b, c)
