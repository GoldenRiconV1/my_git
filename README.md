# 🔐 103CIPHER

> A matrix-based cryptography project developed for the Epitech mathematics module.

![Language](https://img.shields.io/badge/Language-Python_3.12-blue)
![Type](https://img.shields.io/badge/Type-Cryptography-red)
![License](https://img.shields.io/badge/License-MIT-green)

## 📋 Table of Contents
1. [📖 About the Project](#-about-the-project)
2. [🚀 Core Project](#-core-project)
    - [Prerequisites](#prerequisites)
    - [Usage](#usage)
    - [Examples](#examples)
3. [✨ Bonus: Interactive Interface](#-bonus-interactive-interface)
    - [Features](#features)
    - [Installation & Launch](#installation--launch)
4. [🧮 Mathematical Theory](#-mathematical-theory)

---

## 📖 About the Project

**103cipher** is a software that encrypts and decrypts messages using a complex encryption key in the form of a matrix. The principle relies on **matrix multiplication** for encoding and the use of the **inverse matrix** for decoding. This project is inspired by the Hill Cipher.

---

## 🚀 Core Project

The core of the project is a command-line script (CLI) that strictly follows the subject's standards.

### Prerequisites
* **Python 3.12+**.
* No external libraries are used for matrix calculus (usage of `numpy` is prohibited).

### Usage

The program is executed via the `103cipher` binary (or the main python script) with the following syntax:

```bash
./103cipher [message] [key] [flag]
````

| Argument | Description |
| :--- | :--- |
| `message` | The message to encrypt (ASCII string) or decrypt (sequence of numbers). |
| `key` | The encryption key, composed of ASCII characters. |
| `flag` | `0` to encrypt the message, `1` to decrypt it. |

### Examples

**1. Encryption**
Transforming the message "Just because I don't care..." with the key "Homer S".

```bash
./103cipher "Just because I don't care doesn't mean I don't understand." "Homer S" 0
```

*Expected Output:*

```text
Key matrix:
72.0	111.0	109.0
101.0	114.0	32.0
83.0	0.0	0.0

Encrypted message:
26690 21552 11810 19718 16524 13668 ... (sequence of numbers)
```

**2. Decryption**
Recovering the original message from the encrypted sequence.

```bash
./103cipher "26690 21552 11810 19718 16524..." "Homer S" 1
```

-----

## ✨ Bonus: Interactive Interface

To enhance the user experience, a graphical terminal interface (TUI) has been developed in the `bonus/` directory. It offers intuitive navigation, colors, and better error handling.

### Features

  * 🎨 **Rich Interface**: Uses the `rich` library for colorful menus and panels.
  * 🚦 **Visual Feedback**: Loading spinners and icons (emojis) for operation status.
  * 🛡️ **Robustness**: Handling of import errors and user inputs.
  * 🇺🇸 **Language**: Fully localized in English for international accessibility.

### Installation & Launch

The bonus requires external Python dependencies listed in the `Pipfile`.

1.  **Install Dependencies:**

    ```bash
    cd bonus
    pip install rich pyfiglet emoji
    # Or via pipenv if installed
    pipenv install
    ```

2.  **Launch the Bonus:**

    ```bash
    python3 bonus.py
    ```

### Menu Preview

```text
   ╭────────────────── Main Menu ───────────────────╮
   │                                                │
   │           [0] Encryption 🔒                    │
   │           [1] Decryption 🔓                    │
   │           [2] Exit ❌                          │
   │                                                │
   ╰────────────────────────────────────────────────╯
```

-----

## 🧮 Mathematical Theory

The encryption process follows these steps:

1.  **Key Transformation**: Convert the ASCII key into numbers, then arrange them into the smallest possible square matrix.
2.  **Message Transformation**: Convert the message into a matrix where the number of columns fits the key matrix size.
3.  **Multiplication**: $Matrix_{Message} \times Matrix_{Key} = Matrix_{Encrypted}$.

Decryption performs the reverse operation:

1.  Calculate the **inverse matrix** of the key ($K^{-1}$).
2.  Multiply the encrypted message matrix by this inverse matrix.

> **Note:** Matrix inversion is performed "by hand" using the Gauss-Jordan elimination method, without advanced mathematical libraries.

-----

### Authors

Project created for **Epitech**.
