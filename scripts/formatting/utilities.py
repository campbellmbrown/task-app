import shlex
import subprocess


def execute_command(command: str) -> int:
    """Runs a command in a subprocess and returns the exit code."""
    print(f"> {command}")
    p = subprocess.Popen(shlex.split(command))
    p.wait()
    p.communicate()
    return p.returncode


def execute_command_output(command: str) -> str:
    """Runs a command in a subprocess and returns the output."""
    return subprocess.check_output(shlex.split(command)).strip(b"\r\n")
