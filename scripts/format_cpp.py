import argparse

from formatting.uncrustify_formatting import UncrustifyFormatter

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Formats all cpp code.")
    parser.add_argument("--check", "-c", action='store_true', help='Check the code instead of changing it.')
    args = parser.parse_args()

    uncrustify_formatter = UncrustifyFormatter()
    uncrustify_formatter.format(args.check)
