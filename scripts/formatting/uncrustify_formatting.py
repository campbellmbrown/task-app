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
import shlex
import subprocess
from pathlib import Path
from typing import List
from .ignore_list import EXCLUDE_DIRECTORIES, EXCLUDE_FILES

PATH_OF_THIS_FILE = Path(__file__).parent.absolute()


def evaluate_relative_path(path: Path) -> Path:
    return Path.joinpath(PATH_OF_THIS_FILE, path).resolve()


SEARCH_PATH = evaluate_relative_path(Path("../.."))
CONFIG_PATH = evaluate_relative_path(Path("config/Uncrustify-0.72.0_f.cfg"))
UNCRUSTIFY_VERSION_TO_CHECK = b"Uncrustify-0.72.0_f"


def execute_command(command: str) -> int:
    """Runs a command in a subprocess.

    Args:
        command (str): The command to run.

    Returns:
        int: The exit code of the command.
    """
    print(f"> {command}")
    p = subprocess.Popen(shlex.split(command))
    p.wait()
    p.communicate()
    return p.returncode


class UncrustifyFormatter:
    def is_file_excluded(self, file: Path) -> bool:
        """Checks if a file should be excluded.

        Args:
            file (Path): The path of the file.

        Returns:
            bool: True if the file should be excluded, false otherwise.
        """
        for exclude_directory in EXCLUDE_DIRECTORIES:
            if file.as_posix().startswith(evaluate_relative_path(exclude_directory).as_posix()):
                return True
        for exclude_file in EXCLUDE_FILES:
            if file.as_posix() == evaluate_relative_path(exclude_file).as_posix():
                return True
        return False

    def generate_list_of_files_to_format(self) -> List[Path]:
        """Generates a list of files to format, excluding all
        files in the exclude directory list and exclude file list.

        Returns:
            List[Path]: A list of files to format.
        """
        files: List[Path] = []
        search_path = evaluate_relative_path(SEARCH_PATH)
        for file in itertools.chain(
            Path(search_path).glob("**/*.cpp"),
            Path(search_path).glob("**/*.c"),
            Path(search_path).glob("**/*.h"),
        ):
            file = file.resolve()
            if not self.is_file_excluded(file):
                files.append(file)

        return files

    def correct_uncrustify_version(self) -> bool:
        return subprocess.check_output(["uncrustify", "--version"]).strip(b"\r\n") == UNCRUSTIFY_VERSION_TO_CHECK

    def format(self, check: bool) -> None:
        if not self.correct_uncrustify_version():
            print(f"WARNING: You are using the wrong uncrustify version. Please install {UNCRUSTIFY_VERSION_TO_CHECK}")

        files = self.generate_list_of_files_to_format()

        # Configure and run Uncrustify
        check_args = "--check" if check else "--replace --no-backup --if-changed"
        temp_file_name = "uncrustify_temp.txt"

        # Writing all paths to a temp file
        with open(temp_file_name, "w") as f:
            for file in files:
                f.write(file.as_posix() + "\n")

        # Executing command
        exit_code = execute_command(f"uncrustify -c \"{CONFIG_PATH.as_posix()}\" {check_args} -F {temp_file_name}")
        os.remove(temp_file_name)
        if exit_code != 0:
            print(f"COMMAND FAILED (exit code: {exit_code})")
            exit(exit_code)
