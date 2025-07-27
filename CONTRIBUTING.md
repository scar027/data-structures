# Contributing Guidelines
## Coding Style

The repository comes with a [.clang-format](./.clang-format) file which is aimed at maintaining a consistent style during development. The style followed is based on [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main) and [The Linux Kernel Coding Style](https://www.kernel.org/doc/html/v4.10/process/coding-style.html). Make sure to run it over your '.cpp' and '.h' files before making any pull requests.
```bash
find . \( -name '*.cpp' -o -name '*.h' \) -print0 | xargs -0 clang-format -i
```

## Developer Certificate of Origin (DCO)

When sending code, please either send signed-off patches or a pull request with signed-off commits. If you don't sign off on them, it won't be accepted. This means adding a line that says "Signed-off-by: Name \<Email\>" at the end of each commit, indicating that you wrote the code and have the right to pass it on as an open source patch. You can simply use the `--signoff` flag while writing the commit message for this purpose.

## Commit Messages

Also, please write good Git commit messages. A good commit message looks like this:

    Header line explaining the commit in one line
    
    Body of commit message is a few lines of text, explaining things
    in more detail, possibly giving some background about the issue
    being fixed, etc etc.
    
    The body of the commit message can be several paragraphs, and
    please do proper word-wrap and keep columns shorter than about
    74 characters or so. That way "git log" will show things
    nicely even when it's indented.
    
    Reported-by: whoever-reported-it
    Signed-off-by: Your Name <you@example.com>

That header line really should be meaningful, and really should be just one line. The header line is what is shown by tools like gitk and shortlog, and should summarize the change in one readable line of text, independently of the longer explanation.

The preferred way to write a commit message is using imperative mood, e.g. "Make foo do xyz" instead of "This patch makes foo do xyz" or "I made foo do xyz", as if you are giving commands or requests to the code base.

## References
Here are some amazing resources that helped shape this project.
1. [Labuladong Algo Notes](https://labuladong.online/algo/en/data-structure-basic/)
1. [Creating a C++ library with CMake](https://decovar.dev/blog/2021/03/08/cmake-cpp-library/)
1. [Clear, Functional C++ Documentation with Sphinx + Breathe + Doxygen + CMake](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)
