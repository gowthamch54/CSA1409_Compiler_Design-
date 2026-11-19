# Compiler Design Lab: Experiments 1–20

Each experiment is provided as an individual C source file.

## Compile and run

Open Git Bash in this folder and compile an experiment, for example:

```bash
gcc Experiment-01.c -o exp01
./exp01
```

On Windows Git Bash, run the generated executable with:

```bash
./exp01.exe
```

For Experiment 3, create `flex_input.txt` in the same folder with the sample C input.
For Experiment 17, pass a text filename as an argument, for example `./exp17 sample.txt`.
For Experiment 18, enter three-address statements one per line and type `END` to finish.

Notes:
- The programs have been updated for modern GCC and standard C.
- The original experiment objectives and core logic are retained.
- Some original examples contained logic errors or incomplete algorithms; these versions use corrected implementations.
- Experiment 7 uses `$` for epsilon.
- Experiment 8 expects productions in the compact format shown in its source comments.
