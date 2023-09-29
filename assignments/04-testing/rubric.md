# Rubric for Assignment 4: Testing

## Submission

### Canvas

1: The link submitted on Canvas is for the pull request containing the
assignment submission.

0: The link submitted on Canvas is not for the pull request containing the
assignment submission.

### Git Branch

1: The branch includes only changes for this assignment.

0: The branch includes commits or changes outside this assignment.

### Git Commit Message

1: All commit messages for the branch are reasonably clear.

0: One or more commit messages for the branch are reasonably clear.

### GitHub Pull Request

1: The pull request is made to the `main` branch of the student's fork of the
course repository.

0: The pull request is made to a branch other than `main` or to a repo that is
not the student's fork of the course repository.

### Points Summary

**Submission Score: XX/4**

## Correctness

### 1. Tests, Suite Tests

#### Scope of Changes

1: Only the three test case files (`test/test_mean.c`, `test/test_print_int.c`,
and `test/test_read_int.c`) were changed.

0: One or more files other than the three above were changed.

#### Test Case

For each of the three sets of test cases (`test_mean`, `test_print_int`, and
`test_tic_tac_toe`), one point for each of the following criteria:

- There are at least three test cases.
- The test cases are substantially different from each other.
- The correct implementation passes all test cases.
- The incorrect implementation passes at least one of the test cases.
- The incorrect implementation fails at least one of the test cases.
- Each test case has a short comment explaining the behavior it is checking for.

### Points Summary

**Correctness Score: XX/19**

## Style and Clean Code

### Clang-Format

2: Clang-Format produces no warnings when run on the changed files.

1: Clang-Format produces a few minor warnings when run on the changed files.

0: Clang-Format produces many warnings when run on the changed files.

### Clang-Tidy

2: Clang-Tidy produces no warnings when building with make.

1: Clang-Tidy produces a few minor warnings when building with make.

0: Clang-Tidy produces many warnings when building with make.

### Compiler Warnings

2: The compiler produces no warnings when building with make.

1: The compiler produces a few minor warnings when building with make.

0: The compiler produces many warnings when building with make.

### Points

**Style and Clean Code Score: XX/6**

## Summary

Add up the points in the three totals here.

**Total score: XX/29**
