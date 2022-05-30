# Task App

## Development

### Formatting

C++ code is formatted using [Uncrustify 0.72.0](https://github.com/uncrustify/uncrustify). This can be installed using the linked instructions, or accessed through the [campbellbrown/formatting](https://hub.docker.com/r/campbellbrown/formatting) Docker container. The Uncrustify-0.72.0_f.cfg file contains the settings used for formatting.

To apply C++ formatting locally:

```console
py -3 scripts/format_cpp.py [--check]
```

Formatting is enforced in the pipeline. Files can be excluded by adding to ignore_list.py.
