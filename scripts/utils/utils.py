from typing import Optional


def is_empty(filename: str) -> bool:
    # Check if the input_file is empty
    with open(filename) as f:
        x = f.read().strip()
    return len(x) == 0


def compare_answer(actual: str, expected: str, rstrip=True) -> str:
    def get_lines(name):
        with open(name) as f:
            lines = f.readlines()

        def preprocess_line(line: str) -> Optional[str]:
            # Personal hack - if the line starts with ![ then we ignore it
            if line.startswith("--["):
                return None
            if rstrip:
                return line.rstrip()
            return line

        lines = [preprocess_line(line) for line in lines]
        lines = [line for line in lines if line is not None]

        return lines

    actual_lines = get_lines(actual)
    expected_lines = get_lines(expected)

    if len(actual_lines) != len(expected_lines):
        return f"😥 WA: diff # lines. expected={len(expected_lines)}, actual={len(actual_lines)}"

    diff = 0
    for actual_line, expected_line in zip(actual_lines, expected_lines):
        if actual_line != expected_line:
            diff += 1

    if diff:
        return f"😥 WA: {diff}/{len(actual_lines)} lines are different"

    return "✅ AC"
