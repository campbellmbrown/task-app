"""A script to apply formatting on .cpp and .h files.

Uses uncrustify (https://github.com/uncrustify/uncrustify) to format (or check the formatting of) the codebase.
The formatting settings are found in uncrustify.cfg.
To generate a list of default settings for uncrustify use uncrustify --show-config

Example usage:
python3 scripts/format-cpp.py --check
python3 scripts/format-cpp.py
"""

import itertools
import os
from pathlib import Path
from typing import List

from .utilities import execute_command, execute_command_output

PATH_OF_THIS_FILE = Path(__file__).parent.absolute()
CONFIG_PATH = Path.joinpath(PATH_OF_THIS_FILE, "config/Uncrustify-0.72.0_f.cfg")
UNCRUSTIFY_VERSION_TO_CHECK = b"Uncrustify-0.72.0_f"
TEMP_FILE_NAME = "uncrustify_temp.txt"


class UncrustifyFormatter:
    def __init__(self, search_path: Path, exclude_dirs: List[str], exclude_paths: List[str]):
        self.search_path = search_path
        self.exclude_dirs = [Path.joinpath(search_path, excdir).resolve() for excdir in exclude_dirs]
        self.exclude_paths = [Path.joinpath(search_path, excpath).resolve() for excpath in exclude_paths]

    def is_file_excluded(self, file: Path) -> bool:
        """Checks if a file should be excluded.

        Args:
            file (Path): The path of the file.

        Returns:
            bool: True if the file should be excluded, false otherwise.
        """
        for exclude_directory in self.exclude_dirs:
            if file.as_posix().startswith(exclude_directory.as_posix()):
                return True
        for exclude_file in self.exclude_paths:
            if file.as_posix() == exclude_file.as_posix():
                return True
        return False

    def generate_list_of_files_to_format(self) -> List[Path]:
        """Generates a list of files to format, excluding all
        files in the exclude directory list and exclude file list.

        Returns:
            List[Path]: A list of files to format.
        """
        files: List[Path] = []
        for file in itertools.chain(
            self.search_path.glob("**/*.cpp"),
            self.search_path.glob("**/*.c"),
            self.search_path.glob("**/*.h"),
        ):
            file = file.resolve()
            if not self.is_file_excluded(file):
                files.append(file)

        return files

    def check_version(self) -> bool:
        match = execute_command_output("uncrustify --version") == UNCRUSTIFY_VERSION_TO_CHECK
        if not match:
            print(f"WARNING: You are using the wrong uncrustify version. Please install {UNCRUSTIFY_VERSION_TO_CHECK}")





    def format(self, check: bool) -> None:
        self.check_version()

        files = self.generate_list_of_files_to_format()

        # Configure and run Uncrustify
        check_args = "--check" if check else "--replace --no-backup --if-changed"

        # Writing all paths to a temp file
        with open(TEMP_FILE_NAME, "w") as f:
            for file in files:
                f.write(file.as_posix() + "\n")

        # Executing command
        exit_code = execute_command(f'uncrustify -c "{CONFIG_PATH.as_posix()}" {check_args} -F {TEMP_FILE_NAME}')
        os.remove(TEMP_FILE_NAME)
        if exit_code != 0:
            print(f"COMMAND FAILED (exit code: {exit_code})")
            exit(exit_code)
