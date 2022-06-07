# Task App

## Brief

TODO

---

## Development

### Formatting

#### C++

C++ code is formatted using [Uncrustify 0.72.0](https://github.com/uncrustify/uncrustify). This can be installed using the linked instructions, or accessed through the [campbellbrown/formatting](https://hub.docker.com/r/campbellbrown/formatting) Docker container. The Uncrustify-0.72.0_f.cfg file contains the settings used for formatting.

To apply C++ formatting locally:

```console
py -3 scripts/format_cpp.py [--check]
```

To exclude C++ source/header files from being formatted, modify the *format_cpp.py* script.

#### Python

Python code is formatted using [Black](https://black.readthedocs.io/en/stable/). This can be installed using the installation instructions in the link, or accessed through the [campbellbrown/formatting](https://hub.docker.com/r/campbellbrown/formatting) Docker container. The line length is set to 120 characters.

To apply python formatting locally:

```console
py -3 scripts/format_py.py [--check]
```

To exclude python files from being formatted, modify the *format_py.py* script.
