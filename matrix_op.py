##
## EPITECH PROJECT, 2025
## G-MAT-100-LYN-1-1-103cipher-14 [WSL: Ubuntu-24.04]
## File description:
## matrix_op.py
##

import sys
import math

def get_ascii_matrix(string, size=-1):
    result = []
    idx = 0
    length = len(string)

    if size == -1:
        size = math.ceil(math.sqrt(length))
    nb_lines = math.ceil(length / size)
    for _ in range(nb_lines):
        line = []
        for _ in range(size):
            if idx < length:
                line.append(ord(string[idx]))
                idx += 1
            else:
                line.append(0)
        result.append(line)
    return result

def multiply_matrices(matrix_one, matrix_two):
    line_a = len(matrix_one)
    if line_a == 0:
        return []
    cols_a = len(matrix_one[0])
    line_b = len(matrix_two)
    cols_b = len(matrix_two[0])

    if cols_a != line_b:
        return None
    result = []
    for _ in range(line_a):
        result.append([0] * cols_b)
    for i in range(line_a):
        for j in range(cols_b):
            temp = 0.0
            for k in range(cols_a):
                temp += matrix_one[i][k] * matrix_two[k][j]
            result[i][j] = int(round(temp))
    return result

def invert_matrix(matrix):
    n = len(matrix)
    augmented = []
    for i in range(n):
        identity_row = [0.0] * n
        identity_row[i] = 1.0
        augmented.append(matrix[i].copy() + identity_row)
    for i in range(n):
        pivot = augmented[i][i]
        if pivot == 0:
            for k in range(i + 1, n):
                if augmented[k][i] != 0:
                    augmented[i], augmented[k] = augmented[k], augmented[i]
                    pivot = augmented[i][i]
                    break
            else:
                sys.exit(84)
        for j in range(2 * n):
            augmented[i][j] = augmented[i][j] / pivot
        for k in range(n):
            if k != i:
                factor = augmented[k][i]
                for j in range(2 * n):
                    augmented[k][j] -= factor * augmented[i][j]
    inverse = []
    for i in range(n):
        inverse.append(augmented[i][n:])
    return inverse


def print_key_matrix(matrix):
    newline = "\n"
    space = " "
    count = 0
    print("Key matrix:")
    for line in matrix:
        for i in line:
            count += 1
            if count % 3:
                print(round(i, 3), end=space)
            else:
                print(round(i, 3), end=newline)
    print() #\n

def print_encrypt_matrix(matrix):
    print("Encrypted message:")
    temp = []
    for line in matrix:
        for col in line:
            temp.append(col)
    print(*temp)

def encrypt(message, key_str):
    key_matrix = get_ascii_matrix(key_str)
    key_size = len(key_matrix)
    message_matrix = get_ascii_matrix(message, key_size)
    encrypt_matrix = multiply_matrices(message_matrix, key_matrix)
    print_key_matrix(key_matrix)
    print_encrypt_matrix(encrypt_matrix)

def get_encrypted_matrix(msg_str, cols):
    matrix = []
    current_row = []
    values = []
    for x in msg_str.split():
        values.append(float(x))
    for val in values:
        current_row.append(val)
        if len(current_row) == cols:
            matrix.append(current_row)
            current_row = []
    if current_row:
        while len(current_row) < cols:
            current_row.append(0.0)
        matrix.append(current_row)
    return matrix

def print_decrypted_message(matrix):
    temp = []
    print("Decrypted message:")
    for row in matrix:
        for i in row:
            print(chr(i), end='')
    print()

def decrypt(encrypted_message, key_str):
    key_matrix = get_ascii_matrix(key_str)
    inverted_key = invert_matrix(key_matrix)
    cols = len(key_matrix)
    encrypted_matrix = get_encrypted_matrix(encrypted_message, cols)
    result = multiply_matrices(encrypted_matrix, inverted_key)
    print_key_matrix(inverted_key)
    print_decrypted_message(result)