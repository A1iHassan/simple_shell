# HSH - Simple Shell Project

HSH is a minimalistic shell project implemented in C, providing a basic command-line interface for users to interact with the operating system.

## Supported Commands

The shell supports the following commands:

1. **ls:** List files and directories.
    ```bash
    ls
    ```

2. **cd:** Change the current working directory.
    ```bash
    cd /path/to/directory
    ```

3. **pwd:** Print the current working directory.
    ```bash
    pwd
    ```

4. **env:** Display the environment variables.
    ```bash
    env
    ```

5. **setenv:** Set an environment variable.
    ```bash
    setenv VARIABLE_NAME variable_value
    ```

6. **unsetenv:** Unset an environment variable.
    ```bash
    unsetenv VARIABLE_NAME
    ```

7. **echo:** Display a message or the value of a variable.
    ```bash
    echo Hello, World!
    ```

8. **exit:** Exit the shell.
    ```bash
    exit
    ```

## How to Run

To run the HSH shell, execute:

```bash
./hsh
```

## Limitations

- This shell is designed for simplicity and may not cover all edge cases or advanced features.
- Input and output redirection, as well as piping, are not implemented in this basic version.
- Error handling is minimal.

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvement, please open an issue or submit a pull request.