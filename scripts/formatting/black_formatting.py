"""A script to apply formatting on python files.

Uses Black (https://black.readthedocs.io/en/stable/) to format (or check the formatting of) the codebase.

Example usage:
    python3 scripts/format-py.py --check
    python3 scripts/format-py.py
"""

from pathlib import Path
from typing import List

from .utilities import execute_command

LINE_LENGTH = 120


class BlackFormatter:
    def __init__(self, search_path: Path, exclude_dirs: List[str], exclude_paths: List[str]):
        self.search_path = search_path
        self.exclude_dirs = exclude_dirs
        self.exclude_paths = exclude_paths

    def format(self, check: bool) -> None:
        exclude_regex = "(" + "|".join(self.exclude_dirs + self.exclude_paths) + ")"
        exclude_regex = exclude_regex.replace("\\", "/")
        exclude_regex = exclude_regex.replace(".", "\\.")

        execute_command(
            'black --line-length {} --exclude="{}"{} {}'.format(
                LINE_LENGTH,
                exclude_regex,
                " --check" if check else "",
                str(self.search_path).replace("\\", "/"),
            ),
        )
