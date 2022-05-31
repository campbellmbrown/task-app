from .ignore_list import EXCLUDE_DIRECTORIES, EXCLUDE_FILES


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
    def format(self, check: bool) -> None:
        exclude_regex = "(" + "|".join(x.relative_to(Path().absolute()).as_posix() for x in exclude_paths) + ")"
        exclude_regex = exclude_regex.replace("\\", "\\\\")
        exclude_regex = exclude_regex.replace(".", "\\.")

        task_utilities.execute_command(
            'black --line-length {} --exclude="^/{}/"{} {}'.format(
                MAX_CODE_LINE_WIDTH,
                exclude_regex,
                " --check" if check else "",
                search_path.as_posix(),
            ),
        )
