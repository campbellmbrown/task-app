import argparse
from pathlib import Path

from formatting.uncrustify_formatting import UncrustifyFormatter


PATH_OF_THIS_FILE = Path(__file__).parent.absolute()
SEARCH_DIR_RELATIVE = ".."
SEARCH_PATH = Path.joinpath(PATH_OF_THIS_FILE, SEARCH_DIR_RELATIVE).resolve()

# Exclude files relative to the search path.
EXCLUDE_FILES = [
    "src/foo.cpp",
]

# Exclude directories relative to the search path.
EXCLUDE_DIRECTORIES = [
    "src/Debug",
]

# Exclude directories with patterns
EXCLUDE_DIRECTORIES.extend(SEARCH_PATH.glob("tests/**/build-*"))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Formats all cpp code.")
    parser.add_argument("--check", "-c", action="store_true", help="Check the code instead of changing it.")
    args = parser.parse_args()

    uncrustify_formatter = UncrustifyFormatter(SEARCH_PATH, EXCLUDE_DIRECTORIES, EXCLUDE_FILES)
    uncrustify_formatter.format(args.check)
