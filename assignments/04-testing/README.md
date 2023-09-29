# Assignment 4: Testing

In this assignment, you will get the chance to write a few unit tests in the
[Criterion testing framework](https://github.com/Snaipe/Criterion).

## 0. Setup

### 0.1. Sync and Branch Your Repo

Make sure that you are at the latest change in your repo by running the
following commands:

```
$ git switch main
$ git pull
$ git pull upstream main
$ git push
```

If you run into issues performing the above operations, ask for help on Discord.

Once you have done this, create a new branch for this assignment:

```
$ git switch -c assignment-04
```

### 0.2. Read the Rubric

The `rubric.md` file contains the rubric for this assignment. You should take a
look at the rubric (particularly the correctness portion) to get a sense of how
your submission will be evaluated.

## 1. Tests, Suite Tests

There are three functions to test in this problem:

- `mean`, which calculates the mean of an array of integers.
- `print_int`, which prints an integer to standard output.
- `read_int`, which reads in an integer between -99 and 999 (inclusive) from the
  user.

Each function has a correct implementation and an incorrect implementation - in
`src/`, you should see a function ending in `_correct.c` and `_incorrect.c`,
respectively. You should read these files and the `.h` files to get a sense of
what the functions expect to take and how the incorrect implementation might
fail.

Your job is to write unit tests to check these functions. Your goal is to write
tests where the correct implementations pass, but the incorrect implementations
can fail. In the `test/` directory, you will find three test files:
`test_mean.c`, `test_print_int.c`, and `test_read_int.c`. Fill in each of these
files with **at least three substantially different tests**, at least one of
which causes the incorrect implementation to fail and at least one of which the
incorrect implementation will still pass. (Here, "substantially different" means
checking a reasonably distinct "conceptual fact" about the code's behavior, as
explained below.)

**Please document your tests.** Above each test, write a short comment
explaining what behavior you are testing for. This should be about behavior and
not the test case; for example, if you are testing that the mean of the int
array `{42}` is `42.0`, your comment should say

```
// Check that the mean of an array with one element is that element.
```

instead of

```
// Check that the mean of {42} is 42.0.
```

In other words, your test should be checking for some conceptual fact about the
code's behavior (the mean of an array of one element).

You should not change any of the `CMakeLists.txt` files or any files in `src/`.
Also, the appropriate libraries have already been included for you in each of
the test files, so you should not need to change the `#include`s in those file
unless you need something else from the C standard library. (Our gentle hint is
that you probably don't need to include any other files, though.)

For `test_print_int.c` and `test_read_int.c`, you may find it helpful to read
the
[stream redirect sample for Criterion](https://github.com/Snaipe/Criterion/blob/bleeding/samples/redirect.c).
Note that on systems we have tested, you will sometimes encounter a crash when
writing tests as shown in this sample. In this case, running `fclose(stream)`
for the appropriate `stream` (e.g., `stdin`) after you are done using it will do
the trick.

For more subtle debugging purposes, we have also included a file called
`print_info.c` that you can use to print out some useful information about
certain types on your system. It is unlikely that you will run into issues, but
in case you do, the output of this program may be helpful.

## 2. Submission

To submit this assignment, add and commit your changed files. These should be
some files in the `test` directory. Be sure to write a reasonably clear commit
message.

Once you have committed your changes, push them to origin (your fork of the
course repository) and open a pull request to **your `main` branch**. Assign the
team "olincollege/softsys-20XX-YY-assistant" as reviewers (with "XX" and "YY"
replaced with the appropriate year and term).

Then, submit the URL to that pull request on Canvas.
