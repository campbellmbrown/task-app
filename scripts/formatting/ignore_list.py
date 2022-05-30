from pathlib import Path

EXCLUDE_DIRECTORIES = [
    Path("../../.git"),
]

# Exclude some of these.. is there a better way maybe?
# From: https://www.codegrepper.com/code-examples/python/python+pathlib+get+files+in+directory+with+pattern
EXCLUDE_DIRECTORIES.extend(Path("../../tests/").glob("build*"))

# Exclude files relative to this file
# e.g. Path(../src/file_name.cpp)
EXCLUDE_FILES = [
    Path("../../src/foo.cpp"),
]
