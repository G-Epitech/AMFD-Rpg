import json

def trim_zeros(matrix):
    # Supprimer les premières lignes et colonnes ne contenant que des 0
    while all(val == 0 for val in matrix[0]):
        matrix.pop(0)
    while all(val == 0 for val in [row[0] for row in matrix]):
        for i in range(len(matrix)):
            matrix[i].pop(0)

    # Supprimer les dernières lignes et colonnes ne contenant que des 0
    while all(val == 0 for val in matrix[-1]):
        matrix.pop(-1)
    while all(val == 0 for val in [row[-1] for row in matrix]):
        for i in range(len(matrix)):
            matrix[i].pop(-1)

    # Trouver la première ligne contenant un 1 et la première colonne contenant un 1
    first_row = -1
    first_col = -1
    for i in range(len(matrix)):
        if 1 in matrix[i]:
            first_row = i
            break
    for j in range(len(matrix[0])):
        if 1 in [row[j] for row in matrix]:
            first_col = j
            break

    # Supprimer les premières lignes et colonnes avant le premier 1
    if first_row != -1:
        matrix = matrix[first_row:]
    if first_col != -1:
        for i in range(len(matrix)):
            matrix[i] = matrix[i][first_col:]

    # Trouver la dernière ligne contenant un 1 et la dernière colonne contenant un 1
    last_row = -1
    last_col = -1
    for i in range(len(matrix)-1, -1, -1):
        if 1 in matrix[i]:
            last_row = i
            break
    for j in range(len(matrix[0])-1, -1, -1):
        if 1 in [row[j] for row in matrix]:
            last_col = j
            break

    # Supprimer les dernières lignes et colonnes après le dernier 1
    if last_row != -1:
        matrix = matrix[:last_row+1]
    if last_col != -1:
        for i in range(len(matrix)):
            matrix[i] = matrix[i][:last_col+1]

    return matrix

file_name = input("Nom du fichier json : ")
file_data = open(file_name)

data = json.load(file_data)

chunks = data["chunks"]
global_len = len(chunks)
global_tab = []
global_start_x = chunks[0]["x"]
global_start_y = chunks[0]["y"]

# Build tab

max_y = 0
max_x = 0
for index in range(global_len):
    start_x = chunks[index]["x"] - global_start_x
    start_y = chunks[index]["y"] - global_start_y
    if start_y > max_y:
        max_y = start_y
    if start_x > max_x:
        max_x = start_x
for y in range(max_y + 16):
    global_tab.append([])
    for x in range(max_x + 16):
        global_tab[y].append(0)

for index in range(global_len):
    start_x = chunks[index]["x"] - global_start_x
    start_y = chunks[index]["y"] - global_start_y

    for y in range(16):
        for x in range(16):
            global_tab[start_y + y][start_x + x] = chunks[index]["data"][16 * y + x]

global_tab = trim_zeros(global_tab)

json = json.dumps(global_tab)
file_save = open("configs/new_collision.json", "w")
file_save.write(str(json))

file_data.close()
file_save.close()
