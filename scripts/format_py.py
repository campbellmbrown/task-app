import argparse
from pathlib import Path

from formatting.black_formatting import BlackFormatter


PATH_OF_THIS_FILE = Path(__file__).parent.absolute()
SEARCH_DIR_RELATIVE = ".."
SEARCH_PATH = Path.joinpath(PATH_OF_THIS_FILE, SEARCH_DIR_RELATIVE).resolve()

EXCLUDE_FILES = []

EXCLUDE_DIRECTORIES = []

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Formats all cpp code.")
    parser.add_argument("--check", "-c", action="store_true", help="Check the code instead of changing it.")
    args = parser.parse_args()

    uncrustify_formatter = BlackFormatter(SEARCH_PATH, EXCLUDE_DIRECTORIES, EXCLUDE_FILES)
    uncrustify_formatter.format(args.check)
