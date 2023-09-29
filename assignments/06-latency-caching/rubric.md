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

### 1. Transpose for the Camera

#### Scope of Changes

1: Only the implementation file (`src/transpose.c`) was changed.

0: One or more files other than the above were changed.

#### Cache Performance

Note that to get credit for this section, the `is_tranpose::test` unit test must
pass.

For the `transpose` function:

3: The function, when run with the provided unit tests, results in at least 600
fewer misses than the reference implementation.

2: The function yields between 300 and 599 fewer misses than the reference
implementation.

1: The function yields between 100 and 299 fewer misses than the reference
implementation.

0: The function yields up to 99 fewer misses than the reference implementation,
or more misses.

#### Extra Credit

1 point for every 500 fewer misses than the reference implementation, starting
at 1100 fewer misses (1100 fewer misses is 1 extra point).

### Points Summary

**Correctness Score: XX/3**

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

**Total score: XX/13**
