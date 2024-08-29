# Simple Lexer

## Overview

This project implements a basic lexer in C, designed to read from a file and tokenize arithmetic expressions containing numbers and operators. The lexer identifies and classifies tokens such as addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`), and numeric values. This implementation demonstrates fundamental concepts in lexical analysis and basic file handling in C.

## Features

- **Tokenization**: Identifies tokens for arithmetic operators and numeric values.
- **File Handling**: Reads input from a file and processes it character by character.
- **Error Handling**: Detects and reports unknown tokens.

## File Structure

- `lexer.c`: The main source file containing the lexer implementation.
- `test.txt`: A sample input file containing arithmetic expressions (can be replaced with your own input file).

## Limitations
- Currently handles only basic arithmetic operators and numeric values.
- Does not handle numbers with spaces between them.
- No support for more complex expressions or error recovery beyond unknown tokens.

